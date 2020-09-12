//
// Created by 12 on 2020/9/2.
//

#ifndef CPP_STUDY_DNS_H
#define CPP_STUDY_DNS_H

#include <iostream>
#include <stdint.h>
#include <vector>
#include <string>
//win平台运行
#include <WINSOCK2.H>

#pragma comment(lib, "ws2_32.lib")

#define MAX_DOMAINNAME_LEN 255
#define DNS_PORT  53
#define DNS_TYPE_SIZE 2
#define DNS_HEADER_SIZE 12
#define DNS_CLASS_SIZE 2
#define DNS_TTL_SIZE 4
#define DNS_DATALEN_SIZE 2
#define DNS_IP_SIZE 4
#define DNS_TYPE_A  0x0001 //1 a host address
#define DNS_TYPE_CNAME 0x0005 //5 the canonical name for an alias
#define DNS_PACKET_MAX_SIZE (sizeof(DNSHeader) + MAX_DOMAINNAME_LEN + DNS_TYPE_SIZE + DNS_CLASS_SIZE)
#define DNS_SERVER_IP inet_addr("114.114.114.114")

using namespace std;

//DNS报头
struct DNSHeader {
    uint16_t transID; //标识符，一般填入本进程的标识符
    uint16_t flags; //标志位 ,具体含义查文档
    uint16_t questionCount; //DNS查询/回复包数据部分Question字段的个数
    uint16_t answerCount; //DNS查询/回复包数据部分Answer字段的个数
    uint16_t authorityCount; //权威名称服务器的数目
    uint16_t additionalCount; //额外的记录数目（权威名称服务器对应 IP 地址的数目）
};
//请求结构体
struct DNSQuestion {
    char *domainName; //查询域名
    uint16_t type; //DNS 查询请求的资源类型。通常查询类型为 A 类型，表示由域名获取对应的 IP 地址。值为1
    uint16_t clazz; //地址类型，通常为互联网地址，值为 1
};
//回答结构体
struct DNSAnswer {
//    uint16_t domainNameOffset; //查询域名数据地址偏移量，一般都是询问域名的数据偏移地址
    char *name;
    uint16_t type; // 值为1表示A类型， 如果值5表示cName,需要计算偏移获取名称内容
    uint16_t clazz;//地址类型，通常为互联网地址，值为 1。
    uint32_t ttl; //生存时间，单位秒
    uint16_t length;//数据内容长度
    char *cName; //cName内容
    char *ip;//ip地址
};
//权威服务器和附加信息暂时不解析

class DNSLookup {
public:
    DNSLookup(int32_t dnsIp = DNS_SERVER_IP);

    ~DNSLookup();

    bool lookupCore(char *domainName, DNSHeader &header, DNSQuestion &question, vector<DNSAnswer> &answers);

    void printDNSHeader(DNSHeader &header);

    void printDNSQuestion(DNSQuestion &question);

    void printDNSAnswer(vector<DNSAnswer> &answers);

private:
    SOCKET m_sock; //socket实例
    char *m_szDNSPacket; //接收到的dns数据
    bool m_bIsInitOK; //是否初始化成功
    uint16_t m_usCurrentProcID; //当前进程Id

    int32_t m_serverIp;//域名服务器ip地址

    bool sendDNSRequest(sockaddr_in sockAddrDNSServer, char *szDomainName);

    bool recvDNSResponse(sockaddr_in sockAddrDNSServer, DNSHeader &header, DNSQuestion &question,
                         vector<DNSAnswer> &answers);

    bool encodeDotStr(char *szDotStr, char *szEncodedStr);

    bool decodeDotStr(char *szEncodedStr, uint16_t *pusEncodedStrLen, char *szDotStr, uint16_t nDotStrSize,
                      char *szPacketStartPos = NULL);
};

#endif //CPP_STUDY_DNS_H
