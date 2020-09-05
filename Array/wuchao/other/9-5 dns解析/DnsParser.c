//
// Created by 吴超 on 2020/9/1.
//
#include <unistd.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <zconf.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <stdio.h>

#define A 1;
#define NS 2;
#define MD 3;
#define MF 4;
#define CNAME 5;
#define SOA 6;
#define MB 7;
#define MG 8;
#define MR 9;
#define nu 10;//NULL
#define WKS 11;
#define PTR 12;
#define HINFO 13;
#define MINFO 14;
#define MX 15;
#define TXT 16;
#define AXFR 252;
#define MAILB 253;
#define MAILA 254;
#define ALL 255;

#define IN 1;
#define CS 2;
#define CH 3;
#define HS 4;
typedef struct Header{
    unsigned short id;
    unsigned short qr:1;//0 query 1 response
    unsigned short opcode:4;// 查询类型 0 a standard query (QUERY) 1 an inverse query (IQUERY) 2 a server status request (STATUS) 3-15 reserved for future use
    unsigned short aa:1;
    unsigned short tc:1;
    unsigned short rd:1;//期望递归查询
    unsigned short ra:1;//递归查询是否可用
    unsigned short z:3;//保留字段
    unsigned short rcode:4;//响应码（错误码）
    unsigned short qdCount;//question section 元素个数
    unsigned short anCount;//answer 里资源记录个数
    unsigned short nsCount;//authority 记录里域名服务器资源记录个数
    unsigned short arCount;//additional 记录里资源记录个数
} Header;

typedef struct Question{
    unsigned char* qName;
    unsigned short qType;
    unsigned short qClass;
} Question;


typedef struct ResourceRecord{
    unsigned char* name;
    unsigned short type;
    unsigned short class;
    unsigned int ttl;
    unsigned short rdLength;
    unsigned char * rdData;
}ResourceRecord;


unsigned char* parseCompressString(unsigned char* buf,unsigned char* originBuf,size_t * size);
unsigned char* parseCompressStringWithLength(unsigned char* buf,unsigned char* originBuf,int length);
void buildHeader(unsigned char* buf){
    Header head;
    Header * header = &head;
    memset(header,0,sizeof(Header));

    header->id = (unsigned short )htons(getpid());
    header->qr = 0;
    header->qdCount = htons(1);
    memcpy(buf,header,sizeof(Header));
}

size_t buildQuestion(char* domain,unsigned char* buf){
    size_t index = 0;
    size_t count = 0;
    while(domain[index+count]!='\0'){
        if(domain[index+count]!='.'){
            buf[index+count+1] = domain[index+count];
            count++;
        } else {
            buf[index] = count;
            index+=count+1;
            count = 0;
        }
    }
    buf[index] = count;
    index+=count+1;
    buf[index++] = '\0';
    *((unsigned short*) (buf+index)) = htons(1);
    index+=2;
    *((unsigned short*) (buf+index)) = htons(1);
    index+=2;
    return index;
}

Header * parseResponseHeader(unsigned char* buf){
    Header *header = malloc(sizeof(Header));
    memset(header,0,sizeof(Header));
    memcpy(&header->id,buf,sizeof(header->id));
    header->id = ntohs(header->id);
    buf+=2;
    unsigned short flag = *((unsigned short*)buf);
    header->qr = flag>>15;
    header->opcode = flag<<1>>(16-4);
    header->aa = flag<<5>>15;
    header->tc = flag<<6>>15;
    header->rd = flag<<7>>15;
    header->ra = flag<<8>>15;
    header->z = flag<<9>>(16-3);
    header->rcode = flag<<12>>(16-4);
    buf+=2;
    memcpy(&header->qdCount,buf,sizeof(header->qdCount));
    buf+=2;
    memcpy(&header->anCount,buf,sizeof(header->anCount));
    buf+=2;
    memcpy(&header->nsCount,buf,sizeof(header->nsCount));
    buf+=2;
    memcpy(&header->arCount,buf,sizeof(header->arCount));
    header->qdCount = ntohs(header->qdCount);
    header->anCount = ntohs(header->anCount);
    header->nsCount = ntohs(header->nsCount);
    header->arCount = ntohs(header->arCount);
    return header;
}

char* parseType(unsigned short type){
    switch (type) {
        case 1:
            return "A";
        case 5:
            return "CNAME";
    }
    return "\0";
}

char* parseClass(unsigned short class){
    switch (class) {
        case 1:
            return "IN";
        case 2:
            return "CS";
        case 3:
            return "CH";
            case 4:
                return "HS";
    }
    return "\0";
}

unsigned char* parseCompressString(unsigned char* buf,unsigned char* originBuf,size_t * size){
    unsigned char *result = malloc(sizeof(char));
    int partCount;
    int index = 0;
    unsigned char *start = buf;
    while(*buf!='\0'){
        if((*buf)>>6==3){
            size_t * compressSize = malloc(sizeof(size_t));
            unsigned char* compressString = parseCompressString(originBuf+*(buf+1),originBuf,compressSize);
            while(*compressString!='\0'){
                result[index++] = *compressString;
                compressString++;
            }
            buf+=2;
            *size = buf-start;
            break;
        } else {
            partCount = *((unsigned char*)buf);
            buf++;
            int partIndex = 0;
            while(partIndex++<partCount){
                result[index++] = *buf;
                buf++;
            }
            if(*buf=='\0') break;
            result[index++] = '.';
        }
    }
    return result;
}

unsigned char* parseCompressStringWithLength(unsigned char* buf,unsigned char* originBuf,int length){
    unsigned char *result = malloc(sizeof(char));
    int partCount;
    int index = 0;
    while(index<length){
        if((*buf)>>6==3){
            size_t * size = malloc(sizeof(size_t));
            unsigned char* compressString = parseCompressString(originBuf+*(buf+1),originBuf,size);
            int compressIndex = 0;
            while(*compressString!='\0'){
                result[index+compressIndex] = *compressString;
                compressIndex++;
                compressString++;
            }
            buf+=2;
            index+=2;
        } else {
            partCount = *((unsigned char*)buf);
            buf++;
            int partIndex = 0;
            while(partIndex++<partCount){
                result[index++] = *buf;
                buf++;
            }
            if(index == length) break;
            result[index++] = '.';
        }
    }
    return result;
}

ssize_t parseQuestions(int count,unsigned char* buf){
    Question ques;
    Question *question = &ques;
    memset(question,0,sizeof(Question));
    question->qName = malloc(sizeof(unsigned char ));
    int questionsIndex = 0;
    unsigned char* cur = buf;
    while(questionsIndex++<count){
        int nameCount = *((unsigned char*)cur);
        cur++;
        int index = 0;
        while(*cur!='\0'){
            int partIndex = 0;
            while(partIndex++<nameCount){
                question->qName[index++] = *cur;
                cur++;
            }
            if(*cur=='\0') break;
            nameCount = *((unsigned char*)cur);
            cur++;
            question->qName[index++] = '.';
        }
        printf("Name:%s\n",question->qName);
        cur++;
        question->qType = ntohs(*((unsigned short*)cur));
        printf("Type:%s\n",parseType(question->qType));
        cur+=2;
        question->qClass = ntohs(*((unsigned short*)cur));
        printf("Class:%s\n",parseClass(question->qClass));
        cur+=2;
    }

    return cur-buf;
}

size_t Int2String(int num,char *str)
{
    sprintf(str, "%d", num);
    return strlen(str);

}

char* parseIpAddress(unsigned char* buf,unsigned short length){
    int index = 0;
    char* result = malloc(sizeof(char));
    char* cur = result;
    while(index<length){
        uint8_t part= (*buf-'0');
        cur+=Int2String(part,cur);
        index++;
        if(index==length) break;
        buf++;
        *cur = '.';
        cur++;
    }
    return result;
}

void parseAnswers(int count,unsigned char* buf,unsigned char* originBuf){
    int answerIndex = 0;
    while(answerIndex++<count){
        ResourceRecord ans;
        ResourceRecord * answer = & ans;
        answer->name = malloc(sizeof(char));
        size_t * size = malloc(sizeof(size_t));
        answer->name = parseCompressString(buf,originBuf,size);
        buf+=*size;
        printf("Name:%s\n",answer->name);
        answer->type = ntohs(*((unsigned short*)buf));
        printf("Type:%s\n",parseType(answer->type));
        buf+=2;
        answer->class = ntohs(*((unsigned short*)buf));
        printf("Class:%s\n",parseClass(answer->class));
        buf+=2;
        answer->ttl = ntohl(*((unsigned int*)buf));
        printf("Time to live:%d\n",answer->ttl);
        buf+=4;
        answer->rdLength = ntohs(*((unsigned short *)buf));
        printf("Data length:%d\n",answer->rdLength);
        buf+=2;
        answer->rdData = malloc(sizeof(unsigned char ));
        if(answer->type==1){
            answer->rdData = parseIpAddress(buf,answer->rdLength);
            buf+=answer->rdLength;
            printf("Address:%s\n",answer->rdData);
        } else if(answer->type==5){
            answer->rdData = parseCompressStringWithLength(buf,originBuf,answer->rdLength);
            buf+=answer->rdLength;
            printf("CNAME:%s\n",answer->rdData);
        }
        printf("-----------------\n");
    }
}

int main(){
    printf("请输入要解析的域名:\n");
    char domain[100];
    scanf("%s",domain);
    printf("请输入dns服务器:\n");
    char domainParserHost[100];
    scanf("%s",domainParserHost);
    struct sockaddr_in dest;
    unsigned char buffer[1024];
    unsigned char recvBuffer[1024];
    memset(&buffer,0,sizeof(buffer));
    int s;
    s = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
    dest.sin_family = AF_INET;
    dest.sin_port = htons(53);
    dest.sin_addr.s_addr = inet_addr(domainParserHost);
    buildHeader(buffer);
    size_t headerSize = sizeof(Header);
    size_t questionSize = buildQuestion(domain,&buffer[headerSize]);
    if(sendto(s,buffer,headerSize+questionSize,0,(struct sockaddr *)&dest,sizeof(dest))<0){
        printf("socket error");
    }
    socklen_t socklen = sizeof(socklen_t);

    recvfrom(s,recvBuffer,1024,0,(struct sockaddr *)&dest,&socklen);
    Header * responseHeader = parseResponseHeader(recvBuffer);
    printf("Transcation ID:%xd\n",responseHeader->id);
    printf("Questions:%d\n",responseHeader->qdCount);
    printf("Answers:%d\n",responseHeader->anCount);
    printf("Authority rrs:%d\n",responseHeader->nsCount);
    printf("Additional rrs:%d\n",responseHeader->arCount);
    printf("Queries:\n");
    size_t queriesSize = parseQuestions(responseHeader->qdCount,&recvBuffer[headerSize]);
    printf("Answers:\n");
    parseAnswers(responseHeader->anCount,&recvBuffer[headerSize+queriesSize],recvBuffer);
}




