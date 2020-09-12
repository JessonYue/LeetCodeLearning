//
// Created by 12 on 2020/9/2.
//

#include "dns.h"

int main() {
    char szDomainName[] = "www.baidu.com";
    DNSLookup dnslookup;
    vector<DNSAnswer> vectorAnswer;
    DNSQuestion question;//= (DNSQuestion *) calloc(1, sizeof(DNSQuestion));
    DNSHeader header;//= (DNSHeader *) calloc(1, sizeof(DNSHeader));
    bool bRet = dnslookup.lookupCore(szDomainName, header, question, vectorAnswer);
    dnslookup.printDNSHeader(header);
    dnslookup.printDNSQuestion(question);
    dnslookup.printDNSAnswer(vectorAnswer);
//    printf("----------%d%c%c", strlen(vectorAnswer[1].name),vectorAnswer[1].name[0],vectorAnswer[1].name[1]);

    if (!bRet) {
        printf("error!\n");
        return -1;
    }
    return 0;
}

