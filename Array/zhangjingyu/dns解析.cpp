#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define DNS_SVR "192.168.1.1"
#define DNS_HOST  0x01
#define DNS_CNAME 0x05
int socketfd;
struct sockaddr_in dest;
/**
 * 发送dns请求
 * @param dns_name
 */
static void send_dns_request(const char *dns_name);
/**
 * 生成DNS会话
 */
static void generate_question(const char *dns_name
        , unsigned char *buf , int *len);

/**
 * 解析dns response
 */
static void parse_dns_response();
/**
 * 解析dns name
 * @param chunk
 * @param ptr
 * @param out
 * @param len
 */
static void parse_dns_name(unsigned char *chunk , unsigned char *ptr
        , char *out , int *len);

/**
 * 是否是dns 站点
 */
static int is_pointer(int in);

static void send_dns_request(const char *dns_name){

    unsigned char request[256];
    unsigned char *ptr = request;
    unsigned char question[128];
    int question_len;


    generate_question(dns_name , question , &question_len);

    *((unsigned short*)ptr) = htons(0xff00);
    ptr += 2;
    *((unsigned short*)ptr) = htons(0x0100);
    ptr += 2;
    *((unsigned short*)ptr) = htons(1);
    ptr += 2;
    *((unsigned short*)ptr) = 0;
    ptr += 2;
    *((unsigned short*)ptr) = 0;
    ptr += 2;
    *((unsigned short*)ptr) = 0;
    ptr += 2;
    memcpy(ptr , question , question_len);
    ptr += question_len;

    sendto(socketfd , request , question_len + 12 , 0
            , (struct sockaddr*)&dest , sizeof(struct sockaddr));
}

static void generate_question(const char *dns_name , unsigned char *buf , int *len){
    char *pos;
    unsigned char *ptr;
    int n;

    *len = 0;
    ptr = buf;
    pos = (char*)dns_name;
    for(;;){
        n = strlen(pos) - (strstr(pos , ".") ? strlen(strstr(pos , ".")) : 0);
        *ptr ++ = (unsigned char)n;
        memcpy(ptr , pos , n);
        *len += n + 1;
        ptr += n;
        if(!strstr(pos , ".")){
            *ptr = (unsigned char)0;
            ptr ++;
            *len += 1;
            break;
        }
        pos += n + 1;
    }
    *((unsigned short*)ptr) = htons(1);
    *len += 2;
    ptr += 2;
    *((unsigned short*)ptr) = htons(1);
    *len += 2;
}

static void parse_dns_response(){

    unsigned char buf[1024];
    unsigned char *ptr = buf;
    struct sockaddr_in addr;
    char *src_ip;
    int n , i , flag , querys , answers;
    int type , ttl , datalen , len;
    char cname[128] , aname[128] , ip[20] , *cname_ptr;
    unsigned char netip[4];
    size_t addr_len = sizeof(struct sockaddr_in);

    n = recvfrom(socketfd , buf , sizeof(buf) , 0
            , (struct sockaddr*)&addr , reinterpret_cast<socklen_t *>(&addr_len));
    ptr += 4; /* move ptr to Questions */
    querys = ntohs(*((unsigned short*)ptr));
    ptr += 2; /* move ptr to Answer RRs */
    answers = ntohs(*((unsigned short*)ptr));
    ptr += 6; /* move ptr to Querys */
    /* move over Querys */
    for(i= 0 ; i < querys ; i ++){
        for(;;){
            flag = (int)ptr[0];
            ptr += (flag + 1);
            if(flag == 0)
                break;
        }
        ptr += 4;
    }
    printf("-------------------------------\n");
    /* now ptr points to Answers */
    for(i = 0 ; i < answers ; i ++){
        bzero(aname , sizeof(aname));
        len = 0;
        parse_dns_name(buf , ptr , aname , &len);
        ptr += 2; /* move ptr to Type*/
        type = htons(*((unsigned short*)ptr));
        ptr += 4; /* move ptr to Time to live */
        ttl = htonl(*((unsigned int*)ptr));
        ptr += 4; /* move ptr to Data lenth */
        datalen = ntohs(*((unsigned short*)ptr));
        ptr += 2; /* move ptr to Data*/
        if(type == DNS_CNAME){
            bzero(cname , sizeof(cname));
            len = 0;
            parse_dns_name(buf , ptr , cname , &len);
            printf("%s is an alias for %s\n" , aname , cname);
            ptr += datalen;
        }
        if(type == DNS_HOST){
            bzero(ip , sizeof(ip));
            if(datalen == 4){
                memcpy(netip , ptr , datalen);
                inet_ntop(AF_INET , netip , ip , sizeof(struct sockaddr));
                printf("%s has address %s\n" , aname , ip);
                printf("\tTime to live: %d minutes , %d seconds\n"
                        , ttl / 60 , ttl % 60);
            }
            ptr += datalen;
        }

    }
    ptr += 2;
}

static void parse_dns_name(unsigned char *chunk
        , unsigned char *ptr , char *out , int *len){
    int n , alen , flag;
    char *pos = out + (*len);

    for(;;){
        flag = (int)ptr[0];
        if(flag == 0)
            break;
        if(is_pointer(flag)){
            n = (int)ptr[1];
            ptr = chunk + n;
            parse_dns_name(chunk , ptr , out , len);
            break;
        }else{
            ptr ++;
            memcpy(pos , ptr , flag);
            pos += flag;
            ptr += flag;
            *len += flag;
            if((int)ptr[0] != 0){
                memcpy(pos , "." , 1);
                pos += 1;
                (*len) += 1;
            }
        }
    }

}

static int is_pointer(int in){
    return ((in & 0xc0) == 0xc0);
}

int main() {
    char * address = "www.baidu.com";
//    printf("请输入要解析的域名:\n");
//    char domain[100];
//    scanf("%s",domain);
    printf("请输入dns服务器:\n");
    char domainParserHost[100];
    scanf("%s",domainParserHost);

    socketfd = socket(AF_INET,SOCK_DGRAM,0);
    if (socketfd<0){
        perror("socket 创建失败");
        exit(-1);
    }
    bzero(&dest,sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_port = htons(53);
    dest.sin_addr.s_addr = inet_addr(domainParserHost);

    send_dns_request(address);
    parse_dns_response();

    return 0;
}
