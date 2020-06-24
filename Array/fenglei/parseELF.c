//
// Created by 丰雷 on 2020/6/22.
//
#include <stdio.h>
#include <mm_malloc.h>
#include <string.h>
#include<ctype.h>

#define FILE_PATH "/Users/fenglei/Documents/development/clion-projects/leetcode_learning/libnative-lib.so"
#define EI_NIDENT 16

typedef uint32_t Elf32_Addr;
typedef uint16_t Elf32_Half;
typedef uint32_t Elf32_Off;
typedef uint32_t Elf32_Word;

typedef struct {
    unsigned char e_ident[EI_NIDENT];
    Elf32_Half e_type;
    Elf32_Half e_machine;
    Elf32_Word e_version;
    Elf32_Addr e_entry;
    Elf32_Off e_phoff;
    Elf32_Off e_shoff;
    Elf32_Word e_flags;
    Elf32_Half e_ehsize;
    Elf32_Half e_phentsize;
    Elf32_Half e_phnum;
    Elf32_Half e_shentsize;
    Elf32_Half e_shnum;
    Elf32_Half e_shstrndx;
} Elf32_Ehdr;

// 初始化头文件
void init_header(Elf32_Ehdr *header);
// 读取指定位置的字节
void readFileBytes(int start, int read_bytes, const char *path, const unsigned char *buffer);
// 打印 header
void printELFHeader(Elf32_Ehdr *header);

void readFileBytes(int start, int read_bytes, const char *path, const unsigned char *buffer) {
    // 读取的字节大小
    FILE *file;
    if ((file = fopen(path, "rb")) == NULL) return;
    // 移动指针到文件开始偏移 start 个字节开始读取
    fseek(file, start, SEEK_SET);
    int size = fread(buffer, sizeof(char), read_bytes, file);
    for (int i = 0; i < size; i++) {
        printf("%02x ", (unsigned) buffer[i]);
    }
    printf("\n");
}

void init_header(Elf32_Ehdr *header) {
    // 读取 e_ident
    readFileBytes(0, 16, FILE_PATH, header->e_ident);
    // 读取 e_type
    unsigned char e_type[2];
    readFileBytes(16, 2, FILE_PATH, e_type);
    header->e_type = *(uint16_t *)&e_type[0];
    // 读取 e_machine
    unsigned char e_machine[2];
    readFileBytes(18, 2, FILE_PATH, e_machine);
    header->e_machine = *(uint16_t *)&e_machine[0];
    // 读取 e_version
    unsigned char e_version[4];
    readFileBytes(20, 4, FILE_PATH, e_version);
    header->e_version = *(uint32_t *)&e_version[0];
    // 读取 e_entry
    unsigned char e_entry[4];
    readFileBytes(24, 4, FILE_PATH, e_entry);
    header->e_entry = *(uint32_t *)&e_entry[0];
    // 读取 e_phoff
    unsigned char e_phoff[4];
    readFileBytes(28, 4, FILE_PATH, e_phoff);
    header->e_phoff = *(uint32_t *)&e_phoff[0];
    // 读取 e_phoff
    unsigned char e_shoff[4];
    readFileBytes(32, 4, FILE_PATH, e_shoff);
    header->e_shoff = *(uint32_t *)&e_shoff[0];
    // 读取 e_flags
    unsigned char e_flags[4];
    readFileBytes(36, 4, FILE_PATH, e_flags);
    header->e_flags = *(uint32_t *)&e_flags[0];
    // 读取 e_ehsize
    unsigned char e_ehsize[2];
    readFileBytes(40, 2, FILE_PATH, e_ehsize);
    header->e_ehsize = *(uint16_t *)&e_ehsize[0];
    // 读取 e_phentsize
    unsigned char e_phentsize[2];
    readFileBytes(42, 2, FILE_PATH, e_phentsize);
    header->e_phentsize = *(uint16_t *)&e_phentsize[0];
    // 读取 e_phentsize
    unsigned char e_phnum[2];
    readFileBytes(44, 2, FILE_PATH, e_phnum);
    header->e_phnum = *(uint16_t *)&e_phnum[0];
    // 读取 e_shentsize
    unsigned char e_shentsize[2];
    readFileBytes(46, 2, FILE_PATH, e_shentsize);
    header->e_shentsize = *(uint16_t *)&e_shentsize[0];
    // 读取 e_shnum
    unsigned char e_shnum[2];
    readFileBytes(48, 2, FILE_PATH, e_shnum);
    header->e_shnum = *(uint16_t *)&e_shnum[0];
    // 读取 e_phentsize
    unsigned char e_shstrndx[2];
    readFileBytes(50, 2, FILE_PATH, e_shstrndx);
    header->e_shstrndx = *(uint16_t *)&e_shstrndx[0];
}

void printELFHeader(Elf32_Ehdr *header){
    // 打印 e_ident
    printf("e_ident:    ");
    for (int i = 0; i < EI_NIDENT; ++i) {
        printf("%d ",header->e_ident[i]);
    }

    printf("\n");
    // 打印 e_type
    printf("e_type:     %d\n",header->e_type);
    // 打印 e_machine
    printf("e_machine:  %d\n",header->e_machine);
    // 打印 e_version
    printf("e_version:  %d\n",header->e_version);
    // 打印 e_entry
    printf("e_entry:    %d\n",header->e_entry);
    // 打印 e_phoff
    printf("e_phoff:    %d\n",header->e_phoff);
    // 打印 e_shoff
    printf("e_shoff:    %d\n",header->e_shoff);
    // 打印 e_flags
    printf("e_flags:    %d\n",header->e_flags);
    // 打印 e_ehsize
    printf("e_ehsize:   %d\n",header->e_ehsize);
    // 打印 e_phentsize
    printf("e_phentsize:%d\n",header->e_phentsize);
    // 打印 e_phnum
    printf("e_phnum:    %d\n",header->e_phnum);
    // 打印 e_shentsize
    printf("e_shentsize:%d\n",header->e_shentsize);
    // 打印 e_shnum
    printf("e_shnum:    %d\n",header->e_shnum);
    // 打印 e_shstrndx
    printf("e_shstrndx: %d\n",header->e_shstrndx);
}


int main() {
    Elf32_Ehdr *header = malloc(sizeof(Elf32_Ehdr));
    init_header(header);
    printELFHeader(header);
    return 0;
}
