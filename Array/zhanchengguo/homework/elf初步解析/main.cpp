#include <iostream>
#include<stdio.h>
#include "elf.h"

void printfElfHeadMessage(Elf64_Ehdr elfheader);

int main() {
    FILE *fp = NULL;
    fp = fopen("/Users/zhanchengguo/Desktop/libnative-lib.so", "r");
    Elf64_Ehdr elfheader;
    if (1 == fread(&elfheader, sizeof(Elf64_Ehdr), 1, fp)) {
        printfElfHeadMessage(elfheader);
    } else {
        printf("Read file fail\n");
    }
    return 0;
}

/**
 * 解析ELF 文件头信息
 * @param elfheader
 */
void printfElfHeadMessage(Elf64_Ehdr elfheader) {
    printf("The ELF Header Message:\n");
    printf("Magic:");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%x", elfheader.e_ident[i]);
    }
    printf("\n");
    // 文件类型
    printf("e_type:：%hx\n", elfheader.e_type);
    // 架构
    printf("e_machine：%hx\n", elfheader.e_machine);
    // 文件版本
    printf("e_version：%x\n", elfheader.e_version);
    // 入口点的虚拟地址
    printf("e_entry：%lx\n", elfheader.e_entry);
    // 程序头部表偏移量
    printf("e_phoff：%lx\n", elfheader.e_phoff);
    // 节头部表偏移量
    printf("e_shoff：%lx\n", elfheader.e_shoff);
    // 保存与文件相关的，特定于处理器的标志
    printf("e_flags：%x\n", elfheader.e_flags);
    // ELF 头大小(字节)
    printf("e_ehsize：%hx\n", elfheader.e_ehsize);
    // 程序头部条目大小
    printf("e_phentsize：%hx\n", elfheader.e_phentsize);
    // 程序头部条目数量
    printf("e_phnum：%hx\n", elfheader.e_phnum);
    // 节头部条目大小
    printf("e_shentsize：%hx\n", elfheader.e_shentsize);
    // 节头部条目数量
    printf("e_shnum：%d\n", elfheader.e_shnum);
    // 节头部字符串表的索引
    printf("e_shstrndx：%d\n", elfheader.e_shstrndx);
}

