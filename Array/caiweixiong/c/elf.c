//
// Created by Vashon on 2020/6/22.
//

#include "elf.h"
#include <stdio.h>
#include <stdlib.h>

// 运行Elf文件解析
void runElfParse(void);

// 检查文件是否 ELF 文件，不是则退出程序
void checkElfFile(FILE *file);

// 输出ELF头部的信息
void printfEhdrMessage(Elf32_Ehdr);

// 输出程序头部的信息
void printfPhdrMessage(FILE *, int, int);

// 输出节头部的信息
void printfShdrMessage(FILE *, int, int);

void runElfParse(void) {
    FILE *file = NULL;
    file = fopen("E:\\workspace\\c\\libtest.so", "rb");
    if (!file) {
        printf("Open file fail\n");
        return;
    } else {
        checkElfFile(file);
    }
    fclose(file);
}

void checkElfFile(FILE *file) {
    if (!file)
        return;
    FILE *elf = file;
    Elf32_Ehdr elf32Ehdr;    // elf 头部表
    // void rewind(FILE *stream) 设置文件位置为给定流 stream 的文件的开头
    rewind(elf);
    // 从给定流 stream 读取数据到 ptr 所指向的数组中，成功，则返回读取的数量：nmemb
    // size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)
    if (1 == fread(&elf32Ehdr, sizeof(Elf32_Ehdr), 1, elf)) {
        if (ELFMAG0 == elf32Ehdr.e_ident[EI_MAG0]
            && ELFMAG1 == elf32Ehdr.e_ident[EI_MAG1]
            && ELFMAG2 == elf32Ehdr.e_ident[EI_MAG2]
            && ELFMAG3 == elf32Ehdr.e_ident[EI_MAG3]) {
            printf("This is elf file\n");
            printfEhdrMessage(elf32Ehdr);
            if (0 == elf32Ehdr.e_phnum)
                printf("\nElf file program header is null\n");
            else {
                printf("\n--------------------------------------\n");
                printfPhdrMessage(file, elf32Ehdr.e_phoff, elf32Ehdr.e_phnum);
            }
            if (0 == elf32Ehdr.e_shnum)
                printf("\nElf file section header is null\n");
            else {
                printf("\n--------------------------------------\n");
                printfShdrMessage(file, elf32Ehdr.e_shoff, elf32Ehdr.e_shnum);
            }
        } else {
            printf("This is not elf file\n");
        }
    } else {
        printf("Read file fail\n");
    }
}

void printfEhdrMessage(Elf32_Ehdr ehdr) {
    printf("The ELF Header Message:\n");
    printf("Magic: ");
    for (int i = 0; i < EI_NIDENT; ++i) {
        printf("%02x ", ehdr.e_ident[i]);
    }
    printf("\n");
    printf("Type:                           \t%d\n", ehdr.e_type);             // 文件类型
    printf("Machine:                        \t%d\n", ehdr.e_machine);          // 架构
    printf("Version:                        \t%#02x\n", ehdr.e_version);       // 文件版本
    printf("Entry point address:            \t%#02x\n", ehdr.e_entry);         // 入口点的虚拟地址
    printf("Start of program headers:       \t%d(bytes)\n", ehdr.e_phoff);     // 程序头部表偏移量
    printf("Start of section headers:       \t%d(bytes)\n", ehdr.e_shoff);     // 节头部表偏移量
    printf("Flags:                          \t%#02x\n", ehdr.e_flags);         // 保存与文件相关的，特定于处理器的标志
    printf("Size of this header:            \t%d(bytes)\n", ehdr.e_ehsize);    // ELF 头大小(字节)
    printf("Size of program headers:        \t%d(bytes)\n", ehdr.e_phentsize); // 程序头部条目大小
    printf("Number of program headers:      \t%d\n", ehdr.e_phnum);            // 程序头部条目数量
    printf("Size of section headers:        \t%d(bytes)\n", ehdr.e_shentsize); // 节头部条目大小
    printf("Number of section headers:      \t%d\n", ehdr.e_shnum);            // 节头部条目数量
    printf("Section header string table index:\t%d\n", ehdr.e_shstrndx);       // 节头部字符串表的索引
}

void printfPhdrMessage(FILE *elf, int offset, int count) {
    // int fseek(FILE *stream, long int offset, int whence) 设置流 stream 的文件位置为给定的偏移 offset，参数 offset 意味着从给定的 whence 位置查找的字节数。
    // fseek(elf, 0, SEEK_SET);
    // 将文件位置标识移动到程序头部位置
    fseek(elf, offset, SEEK_SET);
    printf("Program header from %ld bytes\n", ftell(elf));
    printf("The Program Header Message:\n");
    Elf32_Phdr *phdr = malloc(count * sizeof(Elf32_Phdr));
    if (count == fread(phdr, sizeof(Elf32_Phdr), count, elf)) {
        Elf32_Phdr *p = phdr;
        printf("Type\t\tOffset\t\tVirtAddr\tPhysAddr\tFileSiz\t\tMemSiz\t\tFlg\n");
        for (int i = 0; i < count; ++i, p++) {
            printf("%-10d\t%-#6x\t\t%-#6x\t\t%-#6x\t\t%-#5x\t\t%-#5x\t\t%-#x\n", \
                p->p_type, p->p_offset, \
                p->p_vaddr, p->p_paddr, \
                p->p_filesz, p->p_memsz, p->p_flags);
        }
    } else
        printf("Read program header fail\n");
    free(phdr);
    phdr = NULL;
}

void printfShdrMessage(FILE *elf, int offset, int count) {
    fseek(elf, offset, SEEK_SET);
    printf("Section header from %ld bytes\n", ftell(elf));
    printf("The Section Header Message:\n");
    Elf32_Shdr *shdr = malloc(count * sizeof(Elf32_Shdr));
    if (count == fread(shdr, sizeof(Elf32_Shdr), count, elf)) {
        Elf32_Shdr *s = shdr;
        printf("[Nr]\tName\tType\t\tAddr\tOff\tSize\tES\tFlag\tAlign\n");
        for (int i = 0; i < count; ++i, s++) {
            printf("[%02d]\t%-4x\t%-8x\t%-#6x\t%-#6x\t%-#4x\t%-#x\t%-#x\t%-#x\n", \
               i, s->sh_name, s->sh_type, s->sh_addr, \
               s->sh_offset, s->sh_size, s->sh_entsize, \
               s->sh_flags, s->sh_addralign);
        }
    } else
        printf("Read program header fail\n");
    free(shdr);
    shdr = NULL;
}