//
// Created by 12 on 2020/9/2.
//

#include "dns.h"

DNSLookup::DNSLookup(int32_t dnsIp) : m_serverIp(dnsIp),
                                      m_bIsInitOK(false),
                                      m_sock(INVALID_SOCKET),
                                      m_szDNSPacket(NULL) {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) == SOCKET_ERROR) {
        m_bIsInitOK = false;
    }

    if ((m_sock = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET) {
        m_bIsInitOK = false;
    }

//    m_event = WSACreateEvent();
//    WSAEventSelect(m_sock, m_event, FD_READ);

    m_szDNSPacket = static_cast<char *>(calloc(DNS_PACKET_MAX_SIZE, sizeof(char)));
    if (m_szDNSPacket == NULL) {
        m_bIsInitOK = false;
    }

    m_usCurrentProcID = (uint16_t) GetCurrentProcessId();

    m_bIsInitOK = true;
}

DNSLookup::~DNSLookup() {
    WSACleanup();

    if (m_szDNSPacket != NULL) {
        free(m_szDNSPacket);
    }
}

bool DNSLookup::lookupCore(char *domainName, DNSHeader &header, DNSQuestion &question, vector<DNSAnswer> &answers) {
    if (!m_bIsInitOK || domainName == NULL) {
        return false;
    }

    //配置SOCKET
    sockaddr_in sockAddrDNSServer;
    sockAddrDNSServer.sin_family = AF_INET;
    sockAddrDNSServer.sin_addr.s_addr = m_serverIp;
    sockAddrDNSServer.sin_port = htons(DNS_PORT);

    return !(!sendDNSRequest(sockAddrDNSServer, domainName) ||
             !recvDNSResponse(sockAddrDNSServer, header, question, answers));
}

bool DNSLookup::sendDNSRequest(sockaddr_in sockAddrDNSServer, char *domainName) {
    char *pWriteDNSPacket = m_szDNSPacket;
    //填充DNS查询报文头部
    DNSHeader *header = (DNSHeader *) pWriteDNSPacket;
    header->transID = htons(m_usCurrentProcID);
    header->flags = htons(0x0010);
    header->questionCount = htons(0x0001);
    header->answerCount = 0x0000;
    header->authorityCount = 0x0000;
    header->additionalCount = 0x0000;

    USHORT nDomainNameLen = strlen(domainName);
    //设置DNS查询报文内容
    DNSQuestion *question = static_cast<DNSQuestion *>(malloc(sizeof(DNSQuestion)));
    question->domainName = (char *) malloc(nDomainNameLen + 2);
    encodeDotStr(domainName, question->domainName);
    question->type = htons(0x0001);
    question->clazz = htons(0x0001);
    nDomainNameLen = strlen(question->domainName) + 1;

    memcpy(pWriteDNSPacket += DNS_HEADER_SIZE, question->domainName, nDomainNameLen);
    memcpy(pWriteDNSPacket += nDomainNameLen, (char *) (&question->type), DNS_TYPE_SIZE);
    memcpy(pWriteDNSPacket += DNS_TYPE_SIZE, (char *) (&question->clazz), DNS_CLASS_SIZE);

    //发送DNS查询报文
    uint16_t nDNSPacketSize = DNS_HEADER_SIZE + DNS_TYPE_SIZE + DNS_CLASS_SIZE + nDomainNameLen;
    int dwSent = sendto(m_sock,
                        m_szDNSPacket,
                        nDNSPacketSize,
                        0,
                        (SOCKADDR *) &sockAddrDNSServer,
                        sizeof(sockAddrDNSServer));
    if (dwSent == SOCKET_ERROR) {
        printf("send %s failed\n", m_szDNSPacket);
        return false;
    }
    free(question);
    return true;
}

bool DNSLookup::recvDNSResponse(sockaddr_in sockAddrDNSServer, DNSHeader &header, DNSQuestion &question,
                                vector<DNSAnswer> &answers) {
    answers.clear();

    char recvbuf[1024] = {'\0'};
    char szDotName[128] = {'\0'};
    int nSockaddrDestSize = sizeof(sockAddrDNSServer);
    int dwRecv = recvfrom(m_sock, recvbuf, 1024, 0, (SOCKADDR *) &sockAddrDNSServer, &nSockaddrDestSize);
    if (dwRecv) {
        printf("dwRecv:%d\n", dwRecv);
    }

    header = *((DNSHeader *) recvbuf);
    //转换格式
    header.transID = ntohs(header.transID);
    header.flags = ntohs(header.flags);
    header.answerCount = ntohs(header.answerCount);
    header.questionCount = ntohs(header.questionCount);
    header.authorityCount = ntohs(header.authorityCount);
    header.additionalCount = ntohs(header.additionalCount);

    //取一个字符串的内容
    char *pDNSData = recvbuf + DNS_HEADER_SIZE;
    //解析字符后已用长度
    uint16_t len = 0;
    //解析后字符串长度
    uint8_t strLen = 0;
    //解析Question字段
    for (int i = 0; i < header.questionCount; i++) {
        if (!decodeDotStr(pDNSData, &len, szDotName, 128, pDNSData)) {
            return false;
        }
        strLen = strlen(szDotName) + 1;
        question.domainName = (char *) malloc(strLen);
        memcpy(question.domainName, szDotName, strLen);
        pDNSData += len;
        question.type = ntohs(*((uint16_t *) pDNSData));
        pDNSData += DNS_TYPE_SIZE;
        question.clazz = ntohs(*((uint16_t *) pDNSData));
        pDNSData += DNS_CLASS_SIZE;
    }
    //解析Answer字段
    for (int i = 0; i < header.answerCount; i++) {
        if (!decodeDotStr(pDNSData, &len, szDotName, 128, recvbuf)) {
            return false;
        }
        //结构体申请内存时结构体和结构体指针有区别，注意要申请的内容，此处如果使用结构体指针就会产生奇怪的answer->name不能正常打印，数据异常
        DNSAnswer *answer = (DNSAnswer *) calloc(1, sizeof(DNSAnswer));
        strLen = strlen(szDotName) + 1;
        answer->name = (char *) malloc(strLen);
        memcpy(answer->name, szDotName, strLen);
        pDNSData += len;
        answer->type = ntohs(*((uint16_t *) pDNSData));
        pDNSData += DNS_TYPE_SIZE;
        answer->clazz = ntohs(*((uint16_t *) pDNSData));
        pDNSData += DNS_CLASS_SIZE;
        answer->ttl = ntohl(*((uint32_t *) pDNSData));
        pDNSData += DNS_TTL_SIZE;
        answer->length = ntohs(*((uint16_t *) pDNSData));
        pDNSData += DNS_DATALEN_SIZE;
        if (answer->type == DNS_TYPE_A) {
            answer->ip = (char *) malloc(DNS_IP_SIZE * 2 + 1);
            sprintf(answer->ip,
                    "%d.%d.%d.%d",
                    *(uint8_t *) pDNSData,
                    *(uint8_t *) (pDNSData + 1),
                    *(uint8_t *) (pDNSData + 2),
                    *(uint8_t *) (pDNSData + 3));
            pDNSData += DNS_IP_SIZE;
        } else if (answer->type == DNS_TYPE_CNAME) {
            if (!decodeDotStr(pDNSData, &len, szDotName, 128, recvbuf)) {
                return false;
            }
            strLen = strlen(szDotName) + 1;
            answer->cName = (char *) malloc(strLen);
            memcpy(answer->cName, szDotName, strLen);

            pDNSData += len;
        }

        answers.push_back(*answer);
    }

    //Step4：关闭SOCKET连接
    closesocket(m_sock);
    return true;
}

/*
 * convert "www.baidu.com" to "\x03www\x05baidu\x03com"
 * 0x0000 03 77 77 77 05 62 61 69 64 75 03 63 6f 6d 00 ff
 */
bool DNSLookup::encodeDotStr(char *domainName, char *encodedStr) {
    USHORT nDotStrLen = strlen(domainName);
    //格式化后的字符串开头会加入一个字节的长度内容
    if (domainName == NULL || encodedStr == NULL) {
        return FALSE;
    }

    char *strCopy = new char[nDotStrLen + 1];
    strcpy(strCopy, domainName);
    char *nextPart = strtok(strCopy, ".");
    uint16_t partLen = 0;
    uint16_t encodeLen = 0;
    while (nextPart != NULL) {
        if ((partLen = strlen(nextPart)) != 0) {
            //通过偏移填把充格式化后的字符串填充到对应位置
            sprintf(encodedStr + encodeLen, "%c%s", partLen, nextPart);
            encodeLen += partLen + 1;
        }
        nextPart = strtok(NULL, ".");
    }
    delete strCopy;
    return true;
}

/*
 * convert "\x03www\x05baidu\x03com\x00" to "www.baidu.com"
 * 0x0000 03 77 77 77 05 62 61 69 64 75 03 63 6f 6d 00 ff
 * convert "\x03www\x05baidu\xc0\x13" to "www.baidu.com"
 * 0x0000 03 77 77 77 05 62 61 69 64 75 c0 13 ff ff ff ff
 * 0x0010 ff ff ff 03 63 6f 6d 00 ff ff ff ff ff ff ff ff
 */
bool DNSLookup::decodeDotStr(char *encodedStr, uint16_t *pusEncodedStrLen, char *domainName, uint16_t domainNameSize,
                             char *packetStartPos) {
    if (encodedStr == NULL || pusEncodedStrLen == NULL || domainName == NULL) {
        return false;
    }

    //当前字符串，每个段前包含当前段长度值
    char *pDecodePos = encodedStr;
    //已读取编码字符串长度
    uint16_t usPlainStrLen = 0;
    //域名段前面的长度内容
    uint8_t nLabelDataLen = 0;
    //已解析内容长度
    *pusEncodedStrLen = 0;
    //按字节读取数据内容，知道内容结束
    while ((nLabelDataLen = *pDecodePos) != 0) {
        //普通格式，LabelDataLen + Label, 长度不超过64
        if ((nLabelDataLen & 0xc0) == 0) {
            //使用长度加上域名段的长度超过目的空间长度返回错误
            if (usPlainStrLen + nLabelDataLen + 1 > domainNameSize) {
                return false;
            }
            memcpy(domainName + usPlainStrLen, pDecodePos + 1, nLabelDataLen);
            memcpy(domainName + usPlainStrLen + nLabelDataLen, ".", 1);
            *pusEncodedStrLen += (nLabelDataLen + 1);
            usPlainStrLen += (nLabelDataLen + 1);
            pDecodePos += (nLabelDataLen + 1);
        } else {
            if (packetStartPos == NULL) {
                return false;
            }
            //获取偏移地址，& 0x3fff 过滤掉0xc0
            uint16_t jumpPos = ntohs(*(uint16_t *) pDecodePos) & 0x3fff;
            uint16_t nEncodeStrLen = 0;
            if (!decodeDotStr(packetStartPos + jumpPos,
                              &nEncodeStrLen,
                              domainName + usPlainStrLen,
                              domainNameSize - usPlainStrLen,
                              packetStartPos)) {
                return false;
            }
            //表示偏移量为0xc0XX所以是2个字节
            *pusEncodedStrLen += 2;
            return true;
        }
    }
    //把最后一个点去掉换成0
    domainName[usPlainStrLen - 1] = 0;
    //把退出循环的00的占位加上
    *pusEncodedStrLen += 1;

    return true;
}

void DNSLookup::printDNSHeader(DNSHeader &header) {
    cout << "===NSHeader===" << endl;
    printf("CurrentProcID:0x%x\n", m_usCurrentProcID);
    printf("transID:0x%x\n", header.transID);
    printf("flags:0x%x\n", header.flags);
    printf("questionCount:%d\n", header.questionCount);
    printf("answerCount:%d\n", header.answerCount);
    printf("authorityCount:%d\n", header.authorityCount);
    printf("additionalCount:%d\n", header.additionalCount);
}

void DNSLookup::printDNSQuestion(DNSQuestion &question) {
    cout << "===DNSQuestion===" << endl;
    printf("domainName:%s\n", question.domainName);
    printf("type:%d\n", question.type);
    printf("clazz:%d\n", question.clazz);
}

void DNSLookup::printDNSAnswer(vector<DNSAnswer> &answers) {
    cout << "===DNSAnswer===" << endl;
    DNSAnswer answer;
    for (int i = 0; i < answers.size(); i++) {
        answer = answers[i];
        printf("domainName:%s\n", answer.name);
        printf("type:%d\n", answer.type);
        printf("clazz:%d\n", answer.clazz);
        printf("time to live:%d\n", answer.ttl);
        printf("data length:%d\n", answer.length);
        if (answer.type == DNS_TYPE_A) {
            printf("ip:%s\n", answer.ip);
        } else {
            printf("cName:%s\n", answer.cName);
        }
    }
}
