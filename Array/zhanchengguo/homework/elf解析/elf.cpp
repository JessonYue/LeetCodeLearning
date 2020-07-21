#include <iostream>
#include<stdio.h>
#include "elf.h"


void checkElf(FILE *file);

void print32Elf_info(FILE *file);

void printfElfHeadMessage(Elf32_Ehdr elfheader);

void printfProgramHeaderMessage(FILE *elf, int offset, int count);

void printfSectionHeaderMessage(FILE *elf, int offset, int count, uint16_t shstrndx);

void getSectionNameByName(uint32_t nameIndex, char srcName[], char destName[]);

void getSectionTypeNameByType(uint32_t type, char name[]);

void getSectionFlagNameByFlags(uint32_t flags, char flag[]);

int main() {
    FILE *file = NULL;
    file = fopen("/Users/zhanchengguo/Desktop/libnative-lib.so", "rb");
    if (file) {
        printf("File is null\n");
    } else {
        checkElf(file);
    }
    fclose(file);
    return 0;
}

void checkElf(FILE *file) {
    //检测文件类型与文件字长
    unsigned char buffer[16];
    //设置文件位置为给定流 stream 的文件的开头
    rewind(file);
    if (fread(buffer, sizeof(char) * 16, 1, file) == 1) {
        if (ELFMAG0 == buffer[EI_MAG0]
            && ELFMAG1 == buffer[EI_MAG1]
            && ELFMAG2 == buffer[EI_MAG2]
            && ELFMAG3 == buffer[EI_MAG3]) {
            //ELF文件
            if (buffer[EI_CLASS] == ELFCLASS32) {
                //32位的elf文件
                print32Elf_info(file);
            } else {
                printf("unkowe file type\n");
            }
        } else {
            printf("File is not elf file\n");
        }
    } else {
        printf("Read file fail\n");
    }
}

void print32Elf_info(FILE *elf) {
    //读取之前记得将文件位置标识重置
    rewind(elf);
    Elf32_Ehdr elf32Ehdr;
    if (fread(&elf32Ehdr, sizeof(Elf32_Ehdr), 1, elf) == 1) {
        printfElfHeadMessage(elf32Ehdr);
        if (elf32Ehdr.e_phnum != 0) {
            printf("Print programs header message\n");
            printfProgramHeaderMessage(elf, elf32Ehdr.e_phoff, elf32Ehdr.e_phnum);
        }
        if (elf32Ehdr.e_shnum != 0) {
            printf("Print section header message\n");
            printfSectionHeaderMessage(elf, elf32Ehdr.e_shoff, elf32Ehdr.e_shnum, elf32Ehdr.e_shstrndx);
        }
    } else {
        printf("Read elf header file fail\n");
    }

}

/**
 * 解析ELF 文件头信息
 * @param elfheader
 */
void printfElfHeadMessage(Elf32_Ehdr elfheader) {
    printf("The ELF Header Message:\n");
    printf("Magic:");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%x", elfheader.e_ident[i]);
    }
    printf("\n");
    // 文件类型
    printf("Type：%hx\n", elfheader.e_type);
    // 架构
    printf("Machine：%hx\n", elfheader.e_machine);
    // 文件版本
    printf("Version：%x\n", elfheader.e_version);
    // 入口点的虚拟地址
    printf("Entry point address：%lx\n", elfheader.e_entry);
    // 程序头部表偏移量
    printf("Start of program headers：%lx\n", elfheader.e_phoff);
    // 节头部表偏移量
    printf("Start of section headers：%lx\n", elfheader.e_shoff);
    // 保存与文件相关的，特定于处理器的标志
    printf("Flags：%x\n", elfheader.e_flags);
    // ELF 头大小(字节)
    printf("Size of this header：%d\n", elfheader.e_ehsize);
    // 程序头部条目大小
    printf("Size of program headers：%d\n", elfheader.e_phentsize);
    // 程序头部条目数量
    printf("Number of program headers：%d\n", elfheader.e_phnum);
    // 节头部条目大小
    printf("Size of section headers：%d\n", elfheader.e_shentsize);
    // 节头部条目数量
    printf("Number of section headers：%d\n", elfheader.e_shnum);
    // 节头部字符串表的索引
    printf("Section header string table index：%d\n", elfheader.e_shstrndx);
}

/**
 * 解析程序头(Program Header)信息
 * @param elf
 * @param offset
 * @param count
 */
void printfProgramHeaderMessage(FILE *elf, int offset, int count) {
    // fseek(elf, 0, SEEK_SET);
    // 将文件位置标识移动到程序头部位置
    fseek(elf, offset, SEEK_SET);
    printf("Program header from %ld bytes\n", ftell(elf));
    printf("The Program Header Message:\n");
    Elf32_Phdr *phdr = static_cast<Elf32_Phdr *>(malloc(count * sizeof(Elf32_Phdr)));
    if (count == fread(phdr, sizeof(Elf32_Phdr), count, elf)) {
        Elf32_Phdr *p = phdr;
        printf("Type\tOffset\tVirtAddr\tPhysAddr\tFileSiz\tMemSiz\tFlg\n");
        for (int i = 0; i < count; ++i, p++) {
            printf("%-10d\t%-#6x\t%-#6x\t%-#6x\t%-#5x\t%-#5x\t%-#x\n",
                   p->p_type, p->p_offset,
                   p->p_vaddr, p->p_paddr,
                   p->p_filesz, p->p_memsz, p->p_flags);
        }
    } else {
        printf("Read program header fail\n");
    }
    free(phdr);
    phdr = NULL;
}

/**
 * 解析段头(Section Header)信息
 * @param elf
 * @param offset
 * @param count
 */
void printfSectionHeaderMessage(FILE *elf, int offset, int count, uint16_t shstrndx) {
    fseek(elf, offset, SEEK_SET);
    printf("Section header from %ld bytes\n", ftell(elf));
    printf("The Section Header Message:\n");
    Elf32_Shdr *shdr = static_cast<Elf32_Shdr *>(malloc(count * sizeof(Elf32_Shdr)));
    if (count == fread(shdr, sizeof(Elf32_Shdr), count, elf)) {
        Elf32_Shdr shstr = shdr[shstrndx];
        Elf32_Shdr *s = shdr;
        char srcName[shstr.sh_size];
        char destName[24];
        char typeName[16];
        char flag[12];
        fseek(elf, shstr.sh_offset, SEEK_SET);      // 将文件偏移到节表字符串表的位置
        fread(srcName, shstr.sh_size, 1, elf);  // 读取劫镖字符串表

        printf("\t[%2s]\t%-24s%-12s\t%-8s\t%-6s\t%-6s\t%2s\t%3s\t%2s\t%3s\t%2s\n",
               "Nr", "Name", "Type", "Addr", "Off", "Size", "ES", "Flg", "Lk", "Inf", "Al");
        for (int i = 0; i < count; ++i, s++) {
            getSectionNameByName(s->sh_name, srcName, destName);
            getSectionTypeNameByType(s->sh_type, typeName);
            getSectionFlagNameByFlags(s->sh_flags, flag);
            printf("\t[%2d]\t%-24s%-12s\t%08x\t%06x\t%06x\t%-2d\t%-s\t%-2d\t%-2d\t%-2d\n", \
               i, destName, typeName, s->sh_addr, \
               s->sh_offset, s->sh_size, s->sh_entsize, \
               flag, s->sh_link, s->sh_info, s->sh_addralign);
        }

    } else {
        printf("Read program header fail\n");
    }
    free(shdr);
    shdr = NULL;
}

void getSectionNameByName(uint32_t nameIndex, char srcName[], char destName[]) {
    char *name = srcName;
    name += nameIndex;  // 将指针变量向后偏移 index 位
    memset(destName, '\0', 24);
    strcpy(destName, name);
}

void getSectionTypeNameByType(uint32_t type, char name[]) {
    memset(name, '\0', 16);
    // 注意，这里不可以直接：name = "NULL"这样进行赋值，只能通过strcpy这个函数或者自己逐个字符读写
    switch (type) {
        case SHT_NULL:
            strcpy(name, "NULL");
            break;
        case SHT_PROGBITS:
            strcpy(name, "PROGBITS");
            break;
        case SHT_SYMTAB:
            strcpy(name, "SYMTAB");
            break;
        case SHT_STRTAB:
            strcpy(name, "STRTAB");
            break;
        case SHT_RELA:
            strcpy(name, "RELA");
            break;
        case SHT_HASH:
            strcpy(name, "HASH");
            break;
        case SHT_DYNAMIC:
            strcpy(name, "DYNAMIC");
            break;
        case SHT_NOTE:
            strcpy(name, "NOTE");
            break;
        case SHT_NOBITS:
            strcpy(name, "NOBITS");
            break;
        case SHT_REL:
            strcpy(name, "REL");
            break;
        case SHT_SHLIB:
            strcpy(name, "SHLIB");
            break;
        case SHT_DYNSYM:
            strcpy(name, "DYNSYM");
            break;
        case SHT_INIT_ARRAY:
            strcpy(name, "INIT_ARRAY");
            break;
        case SHT_FINI_ARRAY:
            strcpy(name, "FINI_ARRAY");
            break;
        case SHT_PREINIT_ARRAY:
            strcpy(name, "PREINIT_ARRAY");
            break;
        case SHT_GROUP:
            strcpy(name, "GROUP");
            break;
        case SHT_SYMTAB_SHNDX:
            strcpy(name, "SYMTAB_SHNDX");
            break;
        case SHT_NUM:
            strcpy(name, "NUM");
            break;
        case SHT_LOOS:
            strcpy(name, "LOOS");
            break;
        case SHT_GNU_ATTRIBUTES:
            strcpy(name, "GNU_ATTRIBUTES");
            break;
        case SHT_GNU_HASH:
            strcpy(name, "GNU_HASH");
            break;
        case SHT_GNU_LIBLIST:
            strcpy(name, "GNU_LIBLIST");
            break;
        case SHT_CHECKSUM:
            strcpy(name, "CHECKSUM");
            break;
        case SHT_LOSUNW:
            strcpy(name, "LOSUNW");
            break;
        case SHT_SUNW_COMDAT:
            strcpy(name, "SUNW_COMDAT");
            break;
        case SHT_SUNW_syminfo:
            strcpy(name, "SUNW_syminfo");
            break;
        case SHT_GNU_verdef:
            strcpy(name, "GNU_verdef");
            break;
        case SHT_GNU_verneed:
            strcpy(name, "GNU_verneed");
            break;
        case SHT_GNU_versym:
            strcpy(name, "GNU_versym");
            break;
        case SHT_LOPROC:
            strcpy(name, "LOPROC");
            break;
        case SHT_HIPROC:
            strcpy(name, "HIPROC");
            break;
        case SHT_LOUSER:
            strcpy(name, "LOUSER");
            break;
        case SHT_HIUSER:
            strcpy(name, "HIUSER");
            break;
        default:
            strcpy(name, "NULL");
    }
}

void getSectionFlagNameByFlags(uint32_t flags, char flag[]) {
    memset(flag, '\0', 12);
    char temp[12];
    memset(temp, '\0', 12);
    int index = 0;
    uint32_t result = 0;
    result |= flags;
    if (result & SHF_WRITE)
        temp[index++] = 'W';
    if (result & SHF_ALLOC)
        temp[index++] = 'A';
    if (result & SHF_EXECINSTR)
        temp[index++] = 'X';
    if (result & SHF_MERGE)
        temp[index++] = 'M';
    if (result & SHF_STRINGS)
        temp[index++] = 'S';
    if (result & SHF_INFO_LINK)
        temp[index++] = 'I';
    if (result & SHF_LINK_ORDER)
        temp[index++] = 'L';
    if (result & SHF_GROUP)
        temp[index++] = 'G';
    if (result & SHF_MASKOS)
        temp[index++] = 'o';
    if ((result & SHF_MASKPROC) == SHF_MASKPROC)
        temp[index++] = 'p';
    if ((result & SHF_TLS) || (result & SHF_COMPRESSED) || (result & SHF_OS_NONCONFORMING))
        temp[index] = 'x';
    strcpy(flag, temp);
}


