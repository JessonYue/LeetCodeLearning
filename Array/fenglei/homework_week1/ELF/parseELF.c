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

// ELF header
typedef struct {
    // 魔数 目标文件标识
    unsigned char e_ident[EI_NIDENT];
    // 目标文件类型
    Elf32_Half e_type;
    // 文件目标体系结构类型
    Elf32_Half e_machine;
    // 目标文件版本
    Elf32_Word e_version;
    // 程序入口虚拟地址 没有程序入口为 0
    Elf32_Addr e_entry;
    // 程序头部表格(Program Header Table) 偏移量，如果没有为 0
    Elf32_Off e_phoff;
    // 节区头部表格(Section Header Table) 偏移量，如果没有为 0
    Elf32_Off e_shoff;
    // 特定处理器标识 采用 EF_machine_flag 的格式
    Elf32_Word e_flags;
    // ELF header 大小
    Elf32_Half e_ehsize;
    // 程序头部表格(Program Header Table) 表项大小
    Elf32_Half e_phentsize;
    // 程序头部表格(Program Header Table) 表项数目
    Elf32_Half e_phnum;
    // 节区头部表格(Section Header Table) 表项大小
    Elf32_Half e_shentsize;
    // 节区头部表格(Section Header Table) 表项数目
    Elf32_Half e_shnum;
    // 节区头部表格(Section Header Table) 与 节区名称字符串表的表项索引，如果没有节区名称字符串表参数为 SHN_UNDEF
    Elf32_Half e_shstrndx;
} Elf32_Ehdr;


typedef struct elf32_phdr {
    // 段类型
    Elf32_Word p_type;
    // 第一个段的字节偏移
    Elf32_Off p_offset;
    // 第一个字节被放到内存的虚拟地址
    Elf32_Addr p_vaddr;
    // 仅用于与物理地址相关的系统中 此字段对于可执行文件和共享目标 文件而言具体内容是未指定的
    Elf32_Addr p_paddr;
    // 段在文件映像中所占的字节数
    Elf32_Word p_filesz;
    // 段在内存映像中所占的字节数
    Elf32_Word p_memsz;
    // 段标识
    Elf32_Word p_flags;
    // 此成员给出段在文件中和内存中如何对齐的
    Elf32_Word p_align;
} Elf32_Phdr;


// 读取头文件
void read_header(Elf32_Ehdr *header);

// 读取程序头
void read_program_header(Elf32_Ehdr *header);

// 读取指定位置的字节
void readFileBytes(int start, int read_bytes, const char *path, const unsigned char *buffer);

// 打印 header
void printELFHeader(Elf32_Ehdr *header);


void printProgramHeader(char *name,unsigned char *data);

void printProgramHeader(char *name,unsigned char *data) {
    printf("%s:     ", name);
    for (int i = 0; i < 4; ++i) {
        printf("%02x ", (unsigned) data[i]);
    }
    printf("\n");
}

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

void read_header(Elf32_Ehdr *header) {
    // 读取 e_ident
    readFileBytes(0, 16, FILE_PATH, header->e_ident);
    // 读取 e_type
    unsigned char e_type[2];
    readFileBytes(16, 2, FILE_PATH, e_type);
    header->e_type = *(uint16_t *) &e_type[0];

    // 读取 e_machine
    unsigned char e_machine[2];
    readFileBytes(18, 2, FILE_PATH, e_machine);
    header->e_machine = *(uint16_t *) &e_machine[0];
    // 读取 e_version
    unsigned char e_version[4];
    readFileBytes(20, 4, FILE_PATH, e_version);
    header->e_version = *(uint32_t *) &e_version[0];
    // 读取 e_entry
    unsigned char e_entry[4];
    readFileBytes(24, 4, FILE_PATH, e_entry);
    header->e_entry = *(uint32_t *) &e_entry[0];
    // 读取 e_phoff
    unsigned char e_phoff[4];
    readFileBytes(28, 4, FILE_PATH, e_phoff);
    header->e_phoff = *(uint32_t *) &e_phoff[0];
    // 读取 e_phoff
    unsigned char e_shoff[4];
    readFileBytes(32, 4, FILE_PATH, e_shoff);
    header->e_shoff = *(uint32_t *) &e_shoff[0];
    // 读取 e_flags
    unsigned char e_flags[4];
    readFileBytes(36, 4, FILE_PATH, e_flags);
    header->e_flags = *(uint32_t *) &e_flags[0];
    // 读取 e_ehsize
    unsigned char e_ehsize[2];
    readFileBytes(40, 2, FILE_PATH, e_ehsize);
    header->e_ehsize = *(uint16_t *) &e_ehsize[0];
    // 读取 e_phentsize
    unsigned char e_phentsize[2];
    readFileBytes(42, 2, FILE_PATH, e_phentsize);
    header->e_phentsize = *(uint16_t *) &e_phentsize[0];
    // 读取 e_phentsize
    unsigned char e_phnum[2];
    readFileBytes(44, 2, FILE_PATH, e_phnum);
    header->e_phnum = *(uint16_t *) &e_phnum[0];
    // 读取 e_shentsize
    unsigned char e_shentsize[2];
    readFileBytes(46, 2, FILE_PATH, e_shentsize);
    header->e_shentsize = *(uint16_t *) &e_shentsize[0];
    // 读取 e_shnum
    unsigned char e_shnum[2];
    readFileBytes(48, 2, FILE_PATH, e_shnum);
    header->e_shnum = *(uint16_t *) &e_shnum[0];
    // 读取 e_phentsize
    unsigned char e_shstrndx[2];
    readFileBytes(50, 2, FILE_PATH, e_shstrndx);
    header->e_shstrndx = *(uint16_t *) &e_shstrndx[0];
}

void read_program_header(Elf32_Ehdr *header) {
    // 读取 ProgramHeader
    int program_header_size = header->e_phnum * header->e_phentsize;
    unsigned char program[program_header_size];
    Elf32_Phdr *phdr_array[header->e_phnum];
    readFileBytes(header->e_ehsize, program_header_size, FILE_PATH, program);
    int i;
    for (i = 0; i < header->e_phnum; ++i) {
        printf("---------size:%d-----------\n", (i + 1));
        Elf32_Phdr *phdr = malloc(sizeof(Elf32_Phdr));
        int segment_size = i * header->e_phentsize;
        // 读取 p_type
        unsigned char p_type[4];
        strncpy(p_type, program + segment_size, 4);
        phdr->p_type = *(uint32_t *) &p_type[0];
        printProgramHeader("p_type",p_type);
        // 读取 p_offset
        unsigned char p_offset[4];
        strncpy(p_offset, program + segment_size + 4, 4);
        phdr->p_offset = *(uint32_t *) &p_offset[0];
        printProgramHeader("p_offset",p_offset);
        // 读取 p_vaddr
        unsigned char p_vaddr[4];
        strncpy(p_vaddr, program + segment_size + 8, 4);
        phdr->p_vaddr = *(uint32_t *) &p_vaddr[0];
        printProgramHeader("p_vaddr",p_vaddr);
        // 读取 p_paddr
        unsigned char p_paddr[4];
        strncpy(p_paddr, program + segment_size + 12, 4);
        phdr->p_paddr = *(uint32_t *) &p_paddr[0];
        printProgramHeader("p_paddr",p_paddr);
        // 读取 p_filesz
        unsigned char p_filesz[4];
        strncpy(p_filesz, program + segment_size + 20, 4);
        phdr->p_filesz = *(uint32_t *) &p_filesz[0];
        printProgramHeader("p_filesz",p_filesz);
        // 读取 p_memsz
        unsigned char p_memsz[4];
        strncpy(p_memsz, program + segment_size + 20, 4);
        phdr->p_memsz = *(uint32_t *) &p_memsz[0];
        printProgramHeader("p_memsz",p_memsz);
        // 读取 p_flags
        unsigned char p_flags[4];
        strncpy(p_flags, program + segment_size + 24, 4);
        phdr->p_flags = *(uint32_t *) &p_flags[0];
        printProgramHeader("p_flags",p_flags);
        // 读取 p_align
        unsigned char p_align[4];
        strncpy(p_align, program + segment_size + 28, 4);
        phdr->p_align = *(uint32_t *) &p_align[0];
        printProgramHeader("p_align",p_align);

        phdr_array[i] = phdr;
    }
}


void printELFHeader(Elf32_Ehdr *header) {
    // 打印 e_ident
    printf("e_ident:    ");
    for (int i = 0; i < EI_NIDENT; ++i) {
        printf("%d ", header->e_ident[i]);
    }

    printf("\n");
    // 打印 e_type
    printf("e_type:     %d\n", header->e_type);
    // 打印 e_machine
    printf("e_machine:  %d\n", header->e_machine);
    // 打印 e_version
    printf("e_version:  %d\n", header->e_version);
    // 打印 e_entry
    printf("e_entry:    %d\n", header->e_entry);
    // 打印 e_phoff
    printf("e_phoff:    %d\n", header->e_phoff);
    // 打印 e_shoff
    printf("e_shoff:    %d\n", header->e_shoff);
    // 打印 e_flags
    printf("e_flags:    %d\n", header->e_flags);
    // 打印 e_ehsize
    printf("e_ehsize:   %d\n", header->e_ehsize);
    // 打印 e_phentsize
    printf("e_phentsize:%d\n", header->e_phentsize);
    // 打印 e_phnum
    printf("e_phnum:    %d\n", header->e_phnum);
    // 打印 e_shentsize
    printf("e_shentsize:%d\n", header->e_shentsize);
    // 打印 e_shnum
    printf("e_shnum:    %d\n", header->e_shnum);
    // 打印 e_shstrndx
    printf("e_shstrndx: %d\n", header->e_shstrndx);
}

void test() {
    char src[40];
    char dest[12];

    memset(dest, '\0', sizeof(dest));
    strcpy(src, "1234567890abcdefg");
    strncpy(dest, src + 1, 10);

    printf("最终的目标字符串： %s\n", dest);

}

int main() {
    Elf32_Ehdr *header = malloc(sizeof(Elf32_Ehdr));
    read_header(header);
    printELFHeader(header);
    printf("\n");
    read_program_header(header);


    return 0;
}
