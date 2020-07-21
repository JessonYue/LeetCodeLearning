#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#include <unistd.h>
#include <sys/types.h>
#include "ELF.h"
#include <cstring>
#include <fstream>
#include <cerrno>
#include <cstdio>

char strtable[9999];

int main(int a, char **args) {
    char *elf_magic;
    FILE *fp;
    std::fstream ifs; // open an elf file;
    Elf32_Ehdr *elf32_header = nullptr;
    Elf64_Ehdr *elf64_header = nullptr;

//    const char *c = "/Users/xing/Desktop/hhplayer-release/jni/arm64-v8a/libijkplayer.so";
    const char *c = "/Users/xing/Desktop/hhplayer-release/jni/armeabi-v7a/libijkplayer.so";
    printf("开始读取文件:%s\n", c);
    ifs.open(c, std::ios::in | std::ios::binary);
    if (!ifs.is_open()) {
        std::cout << "Error " << strerror(errno) << ",errno " << errno << std::endl;
        return -1;
    }

    /**
     * 读取ELF魔数
     */
    elf_magic = new char[N_MAGIC]; //Magic 16位
    ifs.read((char *) elf_magic, N_MAGIC);
    ifs.seekg(0, std::ios::beg);//文件指针回到文件开始，便于一次读取ELF文件头
    printf("magic: ");
    for (int i = 0; i < EI_NIDENT; ++i) {
        //十六进制输出每个数
        printf("%02x ", elf_magic[i]);
    }
    printf("\n成功\n");
    //45 4c 46对应'E','L','F'，用于判断是否是ELF文件
    if (elf_magic[EI_MAG0] != ELFMAG0 ||
        elf_magic[EI_MAG1] != ELFMAG1 ||
        elf_magic[EI_MAG2] != ELFMAG2 ||
        elf_magic[EI_MAG3] != ELFMAG3) {
        //本文件不是ELF文件
        std::cout << "error this file is not an elf file,errno -1,exit!" << std::endl;
        return -1;
    }

    /**
     * 根据EI_CLASS判断版本
     */
    if (elf_magic[EI_CLASS] == ELFCLASSNONE) {
        printf("无效文件！");
        //elf版本无效
        std::cout << "error this file is not a standard elf file,errno -2,exit!" << std::endl;
        return -2;
    } else if (elf_magic[EI_CLASS] == ELFCLASS32) {
        printf("Class(类型)：ELF32\n");
        getEIDATA(elf_magic[EI_DATA]);
        printf("version(ELF版本)：%d\n", elf_magic[EI_VERSION]);
        //再读一次，还是前52个字节
        elf32_header = new Elf32_Ehdr[1];
        ifs.read((char *) elf32_header, sizeof(Elf32_Ehdr));
        getHead32(elf32_header);

        printf("=================================================================");
        fp = fopen(c, "rb");
        if (fp == nullptr) {
            printf("%s not exit\n", c);
            exit(1);
        }
        Elf32_Shdr shdr[99];
        fseek(fp, elf32_header->e_shoff, SEEK_SET);
        fread(shdr, sizeof(Elf32_Shdr), elf32_header->e_shnum, fp);
        fseek(fp, shdr[elf32_header->e_shstrndx].sh_offset, SEEK_SET);
        fread(strtable, 1, shdr[elf32_header->e_shstrndx].sh_size, fp);
        printf("There are %d section headers, starting at offset 0x%04x:\n\n", elf32_header->e_shnum,
               elf32_header->e_shoff);
        section_header_32_parse(shdr, elf32_header->e_shnum);
        printf("=================================================================");
        Elf32_Phdr phdr[99];
        fseek(fp, elf32_header->e_phoff, SEEK_SET);
        int count = elf32_header->e_phnum;    //程序头表的数量
        fread(phdr, sizeof(Elf32_Phdr), count, fp);
        printf("There are %d program headers, starting at offset 0x%04x:\n\n", count, elf32_header->e_phoff);
        program_header_32_parse(phdr, count);
    } else if (elf_magic[EI_CLASS] == ELFCLASS64) {
        printf("Class(类型)：ELF64\n");
        getEIDATA(elf_magic[EI_DATA]);
        printf("version(ELF版本)：%d\n", elf_magic[EI_VERSION]);
        elf64_header = new Elf64_Ehdr[1];
        ifs.read((char *) elf64_header, sizeof(Elf64_Ehdr));
        getHead64(elf64_header);

        printf("=================================================================");
        fp = fopen(c, "rb");
        if (fp == nullptr) {
            printf("%s not exit\n", c);
            exit(1);
        }
        Elf64_Shdr shdr[99];
        fseek(fp, elf64_header->e_shoff, SEEK_SET);
        fread(shdr, sizeof(Elf64_Shdr), elf64_header->e_shnum, fp);
        fseek(fp, shdr[elf64_header->e_shstrndx].sh_offset, SEEK_SET);
        fread(strtable, 1, shdr[elf64_header->e_shstrndx].sh_size, fp);
        printf("There are %d section headers, starting at offset 0x%04x:\n\n", elf64_header->e_shnum,
               elf64_header->e_shoff);
        section_header_64_parse(shdr, elf64_header->e_shnum);
        printf("=================================================================");
        Elf64_Phdr phdr[99];
        fseek(fp, elf64_header->e_phoff, SEEK_SET);
        int count = elf64_header->e_phnum;    //程序头表的数量
        fread(phdr, sizeof(Elf64_Phdr), count, fp);
        printf("There are %d program headers, starting at offset 0x%04x:\n\n", count, elf64_header->e_phoff);
        program_header_64_parse(phdr, count);
    }

    delete[] elf_magic;
    delete[] elf32_header;
    delete[] elf64_header;

    printf("=====> ok");

    return 0;
}

//获取数据类型 0.无效格式 1.小端格式 2.大端格式
void getEIDATA(int type) {
    switch (type) {
        case ELFDATANONE:
            printf("EI_DATA：无效格式\n");
            break;
        case ELFDATA2LSB:
            printf("EI_DATA：小端格式\n");
            break;
        case ELFDATA2MSB:
            printf("EI_DATA：大端格式\n");
            break;
    }
}

int getHead64(Elf64_Ehdr *ehdr) {
    std::string s;
    //文件类型
    switch (ehdr->e_type) {
        case ET_NONE:
            s = INF_ET_NONE;
            break;
        case ET_REL:
            s = INF_ET_REL;
            break;
        case ET_EXEC:
            s = INF_ET_EXEC;
            break;
        case ET_DYN:
            s = INF_ET_DYN;
            break;
        case ET_CORE:
            s = INF_ET_CORE;
            break;
        case ET_NUM:
            s = INF_ET_NUM;
            break;
        case ET_LOOS:
            s = INF_ET_LOOS;
            break;
        case ET_HIOS:
            s = INF_ET_HIOS;
            break;
        case ET_LOPROC:
            s = INF_ET_LOPROC;
            break;
        case ET_HIPROC:
            s = INF_ET_HIPROC;
            break;
        default:
            s = INF_ET_NONE;
    }
    std::cout << "Header of ELF (ELF头文件):" << std::endl;
    std::cout << std::hex;
    std::cout << "Type(文件目标类型): " << s << std::endl;
    std::cout << "Version(ELF版本号): 0x" << ehdr->e_version << std::endl;
    std::cout << "Entry point address(程序入口地址): 0x" << ehdr->e_entry << std::endl;
    std::cout << std::dec;
    std::cout << "Start of program headers(程序头部偏移): " << ehdr->e_phoff << std::endl;
    std::cout << "Size of program headers(程序中每个结构体的大小): " << ehdr->e_phentsize << "(bytes)" << std::endl;
    std::cout << "Number of program headers(程序中包含的结构体数): " << ehdr->e_phnum << std::endl;
    std::cout << "Start of section headers(段表偏移): " << ehdr->e_shoff << std::endl;
    std::cout << "Size of section headers(段表中每个结构体的大小): " << ehdr->e_shentsize << "(bytes)" << std::endl;
    std::cout << "Number of section headers(段表中包含的结构体数): " << ehdr->e_shnum << std::endl;
    std::cout << "(用于标识ELF文件平台相关的属性): " << ehdr->e_flags << std::endl;
    std::cout << "(ELF文件头长度): " << ehdr->e_ehsize << "(bytes)" << std::endl;
    std::cout << "(段表字符串表所在的段在段表中的下标): " << ehdr->e_shstrndx << std::endl;
    std::cout << "处理器体系结构: " << ehdr->e_machine << std::endl;

    switch (ehdr->e_machine) {
        case 0 :
            printf("未知体系结构\n");
            break;
        case 1 :
            printf("AT&T WE 32100\n");
            break;
        case 2 :
            printf("SPARC\n");
            break;
        case 3 :
            printf("Intel Architecture\n");
            break;
        case 4 :
            printf("Motorola 68000\n");
            break;
        case 5 :
            printf("Motorola 88000\n");
            break;
        case 7 :
            printf("Intel 80860\n");
            break;
        case 8 :
            printf("MIPS RS3000 Big-Endian\n");
            break;
        case 10 :
            printf("MIPS RS4000 Big-Endian\n");
            break;
        case 62 :
            printf("AMD x86-64 architecture\n");
            break;
    }
}

int getHead32(Elf32_Ehdr *ehdr) {
    std::string s;
    //文件类型
    switch (ehdr->e_type) {
        case ET_NONE:
            s = INF_ET_NONE;
            break;
        case ET_REL:
            s = INF_ET_REL;
            break;
        case ET_EXEC:
            s = INF_ET_EXEC;
            break;
        case ET_DYN:
            s = INF_ET_DYN;
            break;
        case ET_CORE:
            s = INF_ET_CORE;
            break;
        case ET_NUM:
            s = INF_ET_NUM;
            break;
        case ET_LOOS:
            s = INF_ET_LOOS;
            break;
        case ET_HIOS:
            s = INF_ET_HIOS;
            break;
        case ET_LOPROC:
            s = INF_ET_LOPROC;
            break;
        case ET_HIPROC:
            s = INF_ET_HIPROC;
            break;
        default:
            s = INF_ET_NONE;
    }
    std::cout << "Header of ELF (ELF头文件):" << std::endl;
    std::cout << std::hex;
    std::cout << "Type(文件目标类型): " << s << std::endl;
    std::cout << "Version(ELF版本号): 0x" << ehdr->e_version << std::endl;
    std::cout << "Entry point address(程序入口地址): 0x" << ehdr->e_entry << std::endl;
    std::cout << std::dec;
    std::cout << "Start of program headers(程序头部偏移): " << ehdr->e_phoff << std::endl;
    std::cout << "Size of program headers(程序中每个结构体的大小): " << ehdr->e_phentsize << "(bytes)" << std::endl;
    std::cout << "Number of program headers(程序中包含的结构体数): " << ehdr->e_phnum << std::endl;
    std::cout << "Start of section headers(段表偏移): " << ehdr->e_shoff << std::endl;
    std::cout << "Size of section headers(段表中每个结构体的大小): " << ehdr->e_shentsize << "(bytes)" << std::endl;
    std::cout << "Number of section headers(段表中包含的结构体数): " << ehdr->e_shnum << std::endl;
    std::cout << "(用于标识ELF文件平台相关的属性): " << ehdr->e_flags << std::endl;
    std::cout << "(ELF文件头长度): " << ehdr->e_ehsize << "(bytes)" << std::endl;
    std::cout << "(段表字符串表所在的段在段表中的下标): " << ehdr->e_shstrndx << std::endl;
    std::cout << "处理器体系结构: " << ehdr->e_machine << std::endl;

    switch (ehdr->e_machine) {
        case 0 :
            printf("未知体系结构\n");
            break;
        case 1 :
            printf("AT&T WE 32100\n");
            break;
        case 2 :
            printf("SPARC\n");
            break;
        case 3 :
            printf("Intel Architecture\n");
            break;
        case 4 :
            printf("Motorola 68000\n");
            break;
        case 5 :
            printf("Motorola 88000\n");
            break;
        case 7 :
            printf("Intel 80860\n");
            break;
        case 8 :
            printf("MIPS RS3000 Big-Endian\n");
            break;
        case 10 :
            printf("MIPS RS4000 Big-Endian\n");
            break;
        case 62 :
            printf("AMD x86-64 architecture\n");
            break;
    }
}

/***********************section_header*****************************************/
void section_header_32_parse(Elf32_Shdr *shdr, int count) {
    puts("节头表:");
    printf("[编号]\t\t\t名称\t\t\t\t\t类型\t\t\t\t属性\t\t\t\t虚拟地址\t\t\t偏移量\t\t大小\t\t\t 索引值\t\t信息\t 对齐长度\t 表项大小\n");
    for (int i = 0; i < count; ++i) {
        printf("[%02d]\t%s", i, &strtable[shdr[i].sh_name]);
        for (int j = 0; j < 25 - strlen(&strtable[shdr[i].sh_name]); ++j) {
            putchar(' ');
        }
        switch (shdr[i].sh_type) {
            case 0 :
                printf("SHT_NULL\t");
                break;
            case 1 :
                printf("SHT_PROGBITS");
                break;
            case 2 :
                printf("SHT_SYMTAB\t");
                break;
            case 3 :
                printf("SHT_STRTAB\t");
                break;
            case 4 :
                printf("SHT_RELA\t");
                break;
            case 5 :
                printf("SHT_HASH\t");
                break;
            case 6 :
                printf("SHT_DYNAMIC\t");
                break;
            case 7 :
                printf("SHT_NOTE\t");
                break;
            case 8 :
                printf("SHT_NOBITS\t");
                break;
            case 9 :
                printf("SHT_REL\t");
                break;
            case 10 :
                printf("SHT_SHLIB\t");
                break;
            case 11 :
                printf("SHT_DYNSYM\t");
                break;
            case 14 :
                printf("SHT_INIT_ARRAY");
                break;
            case 15 :
                printf("SHT_FINI_ARRAY");
                break;
            case 0x70000000 :
                printf("SHT_LOPROC");
                break;
            case 0x7fffffff :
                printf("SHT_HIPROC");
                break;
            case 0x80000000 :
                printf("SHT_LOUSER");
                break;
            case 0xffffffff :
                printf("SHT_HIUSER");
                break;
            case 0x6ffffff6 :
                printf("SHT_GNU_HASH");
                break;
            case 0x6fffffff :
                printf("SHT_GNU_versym");
                break;
            case 0x6ffffffe :
                printf("SHT_GNU_verneed");
                break;
            default:
                printf("         \t");
        }
        printf("\t");
        printf("    0x%x \t", shdr[i].sh_flags);//属性
        printf("0x%016x\t", shdr[i].sh_addr);//虚拟地址
        printf("0x%08x\t", shdr[i].sh_offset);//偏移量
        printf("%4lu bytes  \t\t", shdr[i].sh_size);//大小
        printf("%u\t\t", shdr[i].sh_link);//索引值
        printf("%u\t", shdr[i].sh_info);//信息
        printf("%2lu bytes\t", shdr[i].sh_addralign);//对齐长度
        printf("%4x\n", shdr[i].sh_entsize);//表项大小
    }
}

void section_header_64_parse(Elf64_Shdr *shdr, int count) {
    puts("节头表:");
    printf("[编号]\t\t\t名称\t\t\t类型\t\t\t\t属性\t\t\t\t虚拟地址\t\t\t偏移量\t\t大小\t\t\t 索引值\t\t信息\t 对齐长度\t 表项大小\n");
    for (int i = 0; i < count; ++i) {
        printf("[%02d]\t%s", i, &strtable[shdr[i].sh_name]);
        for (int j = 0; j < 20 - strlen(&strtable[shdr[i].sh_name]); ++j) {
            putchar(' ');
        }
        switch (shdr[i].sh_type) {
            case 0 :
                printf("SHT_NULL\t");
                break;
            case 1 :
                printf("SHT_PROGBITS");
                break;
            case 2 :
                printf("SHT_SYMTAB\t");
                break;
            case 3 :
                printf("SHT_STRTAB\t");
                break;
            case 4 :
                printf("SHT_RELA\t");
                break;
            case 5 :
                printf("SHT_HASH\t");
                break;
            case 6 :
                printf("SHT_DYNAMIC\t");
                break;
            case 7 :
                printf("SHT_NOTE\t");
                break;
            case 8 :
                printf("SHT_NOBITS\t");
                break;
            case 9 :
                printf("SHT_REL\t");
                break;
            case 10 :
                printf("SHT_SHLIB\t");
                break;
            case 11 :
                printf("SHT_DYNSYM\t");
                break;
            case 14 :
                printf("SHT_INIT_ARRAY");
                break;
            case 15 :
                printf("SHT_FINI_ARRAY");
                break;
            case 0x70000000 :
                printf("SHT_LOPROC");
                break;
            case 0x7fffffff :
                printf("SHT_HIPROC");
                break;
            case 0x80000000 :
                printf("SHT_LOUSER");
                break;
            case 0xffffffff :
                printf("SHT_HIUSER");
                break;
            case 0x6ffffff6 :
                printf("SHT_GNU_HASH");
                break;
            case 0x6fffffff :
                printf("SHT_GNU_versym");
                break;
            case 0x6ffffffe :
                printf("SHT_GNU_verneed");
                break;
        }
        printf("\t0x%x \t", shdr[i].sh_flags);//属性
        printf("0x%016x\t", shdr[i].sh_addr);//虚拟地址
        printf("0x%08x\t", shdr[i].sh_offset);//偏移量
        printf("%4lu bytes  \t\t", shdr[i].sh_size);//大小
        printf("%u\t\t", shdr[i].sh_link);//索引值
        printf("%u\t", shdr[i].sh_info);//信息
        printf("%2lu bytes\t", shdr[i].sh_addralign);//对齐长度
        printf("%4x\n", shdr[i].sh_entsize);//表项大小
    }
}

/***********************program_header*****************************************/

void program_header_32_parse(Elf32_Phdr *phdr, int count) {
    puts("类型\t\t\t属性\t偏移量\t虚拟地址\t\t物理地址\t\t\t文件大小\t\t镜像大小\t\t对齐长度");
    for (int i = 0; i < count; ++i) {
        switch (phdr[i].p_type) {
            case 0 :
                printf("PT_NULL\t");
                break;
            case 1 :
                printf("PT_LOAD\t");
                break;
            case 2 :
                printf("PT_DYNAMIC");
                break;
            case 3 :
                printf("PT_INTERP");
                break;
            case 4 :
                printf("PT_NOTE\t");
                break;
            case 5 :
                printf("PT_SHLIB");
                break;
            case 6 :
                printf("PT_PHDR\t");
                break;
            case 0x6474e550 :
                printf("GNU_EH_FRAME");
                break;
            case 0x6474e551 :
                printf("GNU_STACK");
                break;
            case 0x6474e552 :
                printf("GNU_RELRO");
                break;
            case 0x6474e553 :
                printf("GNU_PROPERTY");
                break;
            case 0x70000000 :
                printf("PT_LOPROC");
                break;
            case 0x7fffffff :
                printf("PT_HIPROC");
                break;
        }
        putchar('\t');
        switch (phdr[i].p_flags) {
            case 0 :
                printf("none");
                break;
            case 1 :
                printf("x");
                break;
            case 2 :
                printf("w");
                break;
            case 3 :
                printf("wx");
                break;
            case 4 :
                printf("r");
                break;
            case 5 :
                printf("rx");
                break;
            case 6 :
                printf("rw");
                break;
            case 7 :
                printf("rwx");
                break;
        }
        printf("\t0x%04x", phdr[i].p_offset);
        printf("\t0x%08x", phdr[i].p_vaddr);
        printf("\t0x%08x", phdr[i].p_paddr);
        printf("\t%4u bytes", phdr[i].p_filesz);
        printf("\t%4u bytes", phdr[i].p_memsz);
        printf("\t%4u bytes", phdr[i].p_align);
        putchar('\n');
    }
}

void program_header_64_parse(Elf64_Phdr *phdr, int count) {

    puts("程序头表:");
    puts("类型\t\t\t属性\t\t偏移量\t\t虚拟地址\t\t\t\t物理地址\t\t\t\t文件大小\t\t\t镜像大小\t\t\t对齐长度");
    for (int i = 0; i < count; ++i) {
        switch (phdr[i].p_type) {
            case 0 :
                printf("PT_NULL\t");
                break;
            case 1 :
                printf("PT_LOAD\t");
                break;
            case 2 :
                printf("PT_DYNAMIC");
                break;
            case 3 :
                printf("PT_INTERP");
                break;
            case 4 :
                printf("PT_NOTE\t");
                break;
            case 5 :
                printf("PT_SHLIB");
                break;
            case 6 :
                printf("PT_PHDR\t");
                break;
            case 0x6474e550 :
                printf("GNU_EH_FRAME");
                break;
            case 0x6474e551 :
                printf("GNU_STACK");
                break;
            case 0x6474e552 :
                printf("GNU_RELRO");
                break;
            case 0x70000000 :
                printf("PT_LOPROC");
                break;
            case 0x7fffffff :
                printf("PT_HIPROC");
                break;
        }
        putchar(' \t');
        switch (phdr[i].p_flags) {
            case 0 :
                printf("none");
                break;
            case 1 :
                printf("x");
                break;
            case 2 :
                printf("w");
                break;
            case 3 :
                printf("wx");
                break;
            case 4 :
                printf("r");
                break;
            case 5 :
                printf("rx");
                break;
            case 6 :
                printf("rw");
                break;
            case 7 :
                printf("rwx");
                break;
        }
        printf("\t0x%08x", phdr[i].p_offset);
        printf("\t0x%016x", phdr[i].p_vaddr);
        printf("\t0x%016x", phdr[i].p_paddr);
        printf("\t%6u bytes", phdr[i].p_filesz);
        printf("\t%6u bytes", phdr[i].p_memsz);
        printf("\t%8u bytes", phdr[i].p_align);
        putchar('\n');
    }
}
