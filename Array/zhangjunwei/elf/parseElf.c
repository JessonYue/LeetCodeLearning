//
// Created by 张俊伟 on 2020/6/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "elf.h"


void parse_elf(char const *file_path);

void print_elf_header(Elf32_Ehdr *ehdr);


/******************ELF HEADER START*************************/
enum Elf_File_type {
    FILE_INVALID = 0,     //无效文件
    FILE_32,            //32位文件
    FILE_64             //64位文件
};
enum ELF_BYTE_ORDER {
    ELF_INVALID = 0,     //无效格式
    ELF_LITTLE_ENDIAN,        //小端
    ELF_BIG_ENDIAN            //大端
};



static bool ismagic(unsigned char const *ident);

static void filetype(unsigned char const *ident);

static void byte_order(unsigned char const *ident);

static void print_etype(Elf32_Ehdr *ehdr);

static void print_e_machine(Elf32_Ehdr *ehdr);


static void print_e_version(Elf32_Ehdr *ehdr);

static bool ismagic(unsigned char const *ident) {
    /**
     * 0x45 --> ASCII 'E'
     * 0x4c --> ASCII 'L'
     * 0x46 --> ASCII 'F'
     */
    return ident[0] == 0x7f
           && ident[1] == 0x45
           && ident[2] == 0x4c
           && ident[3] == 0x46;
}

static void filetype(unsigned char const *ident) {
    switch (ident[4]) {
        case FILE_INVALID:
            printf("Unknown\n");
            break;
        case FILE_32:
            printf("32 bits file\n");
            break;
        case FILE_64:
            printf("64 bits file\n");
            break;
    }
}

static void byte_order(unsigned char const *ident) {
    switch (ident[5]) {
        case ELF_INVALID:
            printf("INVALID 字节序\n");
            break;
        case ELF_LITTLE_ENDIAN:
            printf("LITTLE ENDIAN 字节序\n");
            break;
        case ELF_BIG_ENDIAN:
            printf("BIG ENDIAN 字节序\n");
            break;
    }
}

static void print_etype(Elf32_Ehdr *ehdr) {
    printf("  File Type:                         ");
    switch (ehdr->e_type) {
        case ET_NONE:
            printf("No file type  \n");
            break;
        case ET_REL:
            printf("Relocatable 可重定位文件 \n");
            break;
        case ET_EXEC:
            printf("Executable  可执行文件 \n");
            break;
        case ET_DYN:
            printf("Shared Object  共享文件 \n");
            break;
        case ET_CORE:
            printf("Core file \n");
            break;
        case ET_NUM:
            printf("Number of defined types \n");
            break;
        default:
            printf("Unknown\n");
    }
}

static void print_e_machine(Elf32_Ehdr *ehdr) {
    printf("ELF 文件的 CPU 乎台属性:                         ");
    switch (ehdr->e_type) {
        case EM_NONE:
            printf("No machine \n");
            break;
        case EM_M32:
            printf("AT&T WE 32100 \n");
            break;
        case EM_SPARC:
            printf("SPARC \n");
            break;
        case EM_386:
            printf("Intel x86 \n");
            break;
        case EM_68K:
            printf("Motorola 68000 \n");
            break;
        case EM_88K:
            printf("Motorola 88000 \n");
            break;
        case EM_860:
            printf("Intel 80860 \n");
            break;

        case EM_MIPS :
            printf("MIPS RS3000 \n");
            break;
        default:
            break;
    }
}

static void print_e_version(Elf32_Ehdr *ehdr) {
    switch (ehdr->e_version) {
        case EV_NONE:
            printf("Invalid version \n");
            break;
        case EV_CURRENT:
            printf("Current version \n");
            break;
    }
}

void print_e_entry(Elf32_Ehdr *ehdr) {
    printf("文件关联的入口点 %x\n", ehdr->e_entry);
}


void print_e_shoff(Elf32_Ehdr *ehdr) {
    printf("section 头表（section header table）在文件中的偏移量 %d 字节\n", ehdr->e_shoff);
    printf("section 头表（section header table）入口数目 %d 字节\n", ehdr->e_shnum);
    printf("section 头的大小 %d 字节 所有的入口都是同样的大小若为0表示大小不固定\n", ehdr->e_shentsize);
}

void print_e_flags(Elf32_Ehdr *ehdr) {
    printf("该成员保存着相关文件的特定处理器标志 %x\n", ehdr->e_flags);
}

void print_e_ehsize(Elf32_Ehdr *ehdr) {
    printf("ELF 头大小 %x 字节\n", ehdr->e_ehsize);
}

void print_pt(Elf32_Ehdr *ehdr) {
    printf("程序头表信息！");
    printf("程序头表（program header table）在文件中的偏移量 %d 字节。\n", ehdr->e_phoff);
    printf("e_phnum 程序头表中入口的个数 %d\n", ehdr->e_phnum);
    printf("e_phentsize 程序头表中一个入口的大小 %d\n", ehdr->e_phentsize);
}

void print_e_shstrndx(Elf32_Ehdr *ehdr) {
    printf("Section header string table index: %d\n", ehdr->e_shstrndx);
}

void print_elf_header(Elf32_Ehdr *ehdr) {
    //0~3 字节
    if (!ismagic(ehdr->e_ident)) {
        printf("Not an elf file\n");
        return;
    }
    //文件位数 类型  4
    filetype(ehdr->e_ident);
    //大端小端模式 5
    byte_order(ehdr->e_ident);
    //文件类型
    print_etype(ehdr);
    //机器类型
    print_e_machine(ehdr);
    print_e_version(ehdr);
    print_e_entry(ehdr);
    print_e_shoff(ehdr);
    print_e_flags(ehdr);
    print_e_ehsize(ehdr);
    print_pt(ehdr);
    print_e_shstrndx(ehdr);
}
/******************ELF HEADER  END*************************/
/******************ELF 段表（Section Header Table )  END*************************/
void print_sec_header(Elf32_Shdr *shdr, int num, char *sname) {
    int i;
    printf("Section Headers:\n");
    for (i = 0; i < num; i++) {
        printf("  [%d] ", i);
        //sname 字符串表  存放 各个段的段名 sh_name这个下标值来取段名
//        printf("index(%u) \n",  shdr[i].sh_name);
        printf("Name(%s) ", sname + shdr[i].sh_name);

        switch (shdr[i].sh_type) {
            case SHT_NULL:
                printf("Type(%s) ", "NULL");
                break;
            case SHT_PROGBITS:
                printf("Type(%s) ", "PROGBITS");
                break;
            case SHT_SYMTAB:
                printf("Type(%s) ", "SYMTAB");
                break;
            case SHT_STRTAB:
                printf("Type(%s) ", "STRTAB");
                break;
            case SHT_RELA:
                printf("Type(%s) ", "RELA");
                break;
            case SHT_HASH:
                printf("Type(%s) ", "HASH");
                break;
            case SHT_DYNAMIC:
                printf("Type(%s) ", "DYNAMIC");
                break;
            case SHT_NOTE:
                printf("Type(%s) ", "NOTE");
                break;
            case SHT_NOBITS:
                printf("Type(%s) ", "NOBITS");
                break;
            case SHT_REL:
                printf("Type(%s) ", "REL");
                break;
            case SHT_SHLIB:
                printf("Type(%s) ", "SHLIB");
                break;
            case SHT_DYNSYM:
                printf("Type(%s) ", "DYNSYM");
                break;
            dafault:
                printf("Type(%s) ", "UNKNOWN");
        }

        printf("Addr(0x%08x) ", shdr[i].sh_addr);
        printf("Off(0x%08x) ", shdr[i].sh_offset);
        printf("Size(0x%x) ", shdr[i].sh_size);

        printf("Flg(");
        if (shdr[i].sh_flags & 0x1)
            printf("W");
        if (shdr[i].sh_flags & 0x2)
            printf("A");
        if (shdr[i].sh_flags & 0x4)
            printf("X");
        printf(") ");

        printf("\n");
    }
}

/******************ELF 段表（Section Header Table )  END*************************/
/******************ELF Program Headers  START*************************/

void print_prog_header(Elf32_Phdr *phdr, int num) {
    int i;

    printf("Program Headers:\n");
    for (i = 0; i < num; i++) {
        printf("  [%d] ", i);

        switch (phdr[i].p_type) {
            case PT_NULL:
                printf("Type(%s) ", "NULL");
                break;
            case PT_LOAD:
                printf("Type(%s) ", "LOAD");
                break;
            case PT_DYNAMIC:
                printf("Type(%s) ", "SYNAMIC");
                break;
            case PT_INTERP:
                printf("Type(%s) ", "INTERP");
                break;
            case PT_NOTE:
                printf("Type(%s) ", "NOTE");
                break;
            case PT_SHLIB:
                printf("Type(%s) ", "SHLIB");
                break;
            case PT_PHDR:
                printf("Type(%s) ", "PHDR");
                break;
            case PT_NUM:
                printf("Type(%s) ", "PT_NUM");
                break;
            case PT_LOOS:
                printf("Type(%s) ", "PT_LOOS");
                break;
            default:
                printf("Type(%s-%d)  ", "UNKNOWN", phdr[i].p_type);
                break;
        }

        printf("Offset(0x%08x) ", phdr[i].p_offset);
        printf("VirtAddr(0x%08x) ", phdr[i].p_vaddr);
        printf("PhysAddr(0x%08x) ", phdr[i].p_paddr);
        printf("FileSize(0x%x) ", phdr[i].p_filesz);
        printf("MemSize(0x%x) ", phdr[i].p_memsz);

        printf("Flg(");
        if (phdr[i].p_flags & 0x4)
            printf("R");
        if (phdr[i].p_flags & 0x2)
            printf("W");
        if (phdr[i].p_flags & 0x1)
            printf("X");
        printf(") ");

        printf("Align(0x%x) ", phdr[i].p_align);
        printf("\n");
    }
}

/******************ELF Program Headers  END*************************/
/******************ELF Symbol tables  START*************************/
void print_symbol_table(Elf32_Sym *sym, int num, char *symname) {
    int i;
    printf("Symbol table: \n");
    for (i = 0; i < num; i++) {
        printf("  [%d]: ", i);
        //printf("name(%d) ", sym[i].st_name);
        printf("name(%s) ", symname + sym[i].st_name);
        printf("size(%d) ", sym[i].st_size);
        printf("value(0x%08x) ", sym[i].st_value);
        switch (ELF32_ST_TYPE(sym[i].st_info)) {
            case STT_NOTYPE:
                printf("info(%s) ", "NOTYPE");
                break;
            case STT_OBJECT:
                printf("info(%s) ", "OBJECT");
                break;
            case STT_FUNC:
                printf("info(%s) ", "FUNC");
                break;
            case STT_SECTION:
                printf("info(%s) ", "SECTION");
                break;
            case STT_FILE:
                printf("info(%s) ", "FILE");
                break;
            case STT_NUM:
                printf("info(%s) ", "Number of defined types");
                break;
            case STT_GNU_IFUNC:
                printf("info(%s) ", "Symbol is a indirect code object");
                break;
            case STT_LOOS:
                printf("info(%s) ", "Start of OS-specific");
                break;
            case STT_HIOS:
                printf("info(%s) ", "End of OS-specific");
                break;
            case STT_LOPROC:
                printf("info(%s) ", "Start of processor-specific");
                break;
            case STT_HIPROC:
                printf("info(%s) ", "End of processor-specific");
                break;
            default:
                printf("info(%s) ", "UNKNOWN");
                break;
        }
        printf("\n");
    }
    printf("\n");
}

/******************ELF Symbol table  END*************************/


void parse_elf(char const *file_path) {
    Elf32_Ehdr *ehdr = NULL;


    Elf32_Shdr *shdr;
    //段表的数目
    Elf32_Half shnum;
    //段表头在文件中的偏移
    Elf32_Off shoff;
    //Size of section headers: 40(bytes)
    Elf32_Half shentsize;
    //字符串表在 段表中的 索引下标
    Elf32_Half shstrndx;
    Elf32_Half phentsize;

    //程序头表
    Elf32_Phdr *phdr;
    Elf32_Half phnum;
    Elf32_Off phoff;

    //符号表
    Elf32_Symndx symndx;
    Elf32_Sym *sym;
    char *symname;
    int strndx;

    FILE *fr = fopen(file_path, "rb");
    if (fr == NULL) {
        printf("Cannot open file %s\n", file_path);
        return;
    }
    //读ELF header
    ehdr = (Elf32_Ehdr *) calloc(1, sizeof(Elf32_Ehdr));
    fread(ehdr, 1, sizeof(Elf32_Ehdr), fr);
    print_elf_header(ehdr);

    //Section Headers
    shnum = ehdr->e_shnum;
    shoff = ehdr->e_shoff;
    shentsize = ehdr->e_shentsize;
    shdr = (Elf32_Shdr *) malloc(sizeof(Elf32_Shdr) * shnum);

    for (int i = 0; i < shnum; ++i) {
        if (fseek(fr, shoff + i * shentsize, SEEK_SET) != 0) {
            printf("fseek failed\n");
            return;
        }
        fread(&shdr[i], sizeof(Elf32_Shdr), 1, fr);
        if (shdr[i].sh_type == SHT_SYMTAB)
            symndx = i;
        if(shdr[i].sh_type == SHT_STRTAB)
            strndx = i;
    }
    shstrndx = ehdr->e_shstrndx;
    Elf32_Word strsize = shdr[shstrndx].sh_size;

    char *sname = (char *) malloc(sizeof(char) * strsize);
    if (fseek(fr, shdr[shstrndx].sh_offset, SEEK_SET) != 0) {
        printf("fseek failed\n");
        return;
    }
    fread(sname, sizeof(char), strsize, fr);
    print_sec_header(shdr, shnum, sname);

    //Program Headers
    phnum = ehdr->e_phnum;
    phentsize = ehdr->e_phentsize;
    phoff = ehdr->e_phoff;
    phdr = (Elf32_Phdr *) malloc(sizeof(Elf32_Phdr) * phnum);
    for (int j = 0; j < phnum; ++j) {
        if (fseek(fr, phoff + j * phentsize, SEEK_SET) != 0) {
            printf("fseek failed\n");
            return;
        }
        fread(phdr + j, sizeof(Elf32_Phdr), 1, fr);
    }
    print_prog_header(phdr, phnum);

    //Symbol table
    sym = (Elf32_Sym *) malloc(sizeof(char) * shdr[symndx].sh_size);
    if (fseek(fr, shdr[symndx].sh_offset, SEEK_SET) != 0) {
        printf("fseek failed\n");
        return;
    }
    fread(sym, sizeof(char), shdr[symndx].sh_size, fr);
    symname = (char *) malloc(sizeof(char) * shdr[strndx].sh_size);
    if (fseek(fr, shdr[strndx].sh_offset, SEEK_SET) != 0) {
        printf("fseek failed\n");
        return;
    }
    fread(symname, sizeof(char),  shdr[strndx].sh_size, fr);
    print_symbol_table(sym,shdr[symndx].sh_size*sizeof(char)/sizeof(Elf32_Sym), symname);


    free(ehdr);
    free(shdr);
    free(phdr);
    free(sym);
    free(sname);
    free(symname);
    fclose(fr);
}

int main() {
    parse_elf("/Users/zhangjunwei/Desktop/licode/elf/libnative-lib.so");
    return 0;
}