#include<iostream>
#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include <vector>
#include "elf.h"

using namespace std;

/** 
    非常重要的一个宏，功能很简单： 
    P:需要对其的段地址 
    ALIGNBYTES:对其的字节数 
    功能：将P值补充到时ALIGNBYTES的整数倍 
    这个函数也叫：页面对其函数 
    eg: 0x3e45/0x1000 == >0x4000 
     
*/
#define ALIGN(P, ALIGNBYTES)  ( ((unsigned long)P + ALIGNBYTES -1)&~(ALIGNBYTES-1) )

int addSectionFun(char *, char *, unsigned int);

int readElf(char *lpPath, Elf32_Ehdr *ehdr);

int main() {
    Elf32_Ehdr *ehdr;
    char *path = "/Users/huyang67/ddtrunk/ddcore/lib/libs/armeabi/libJDToolKit.so";
    readElf(path, ehdr);
    return 0;
}


int readElf(char *lpPath, Elf32_Ehdr *ehdr1) {
    Elf32_Ehdr *ehdr;
    unsigned mapSZ = 0;//文件大小
    FILE *fdr;
    int MagNum = 0;
    fdr = fopen(lpPath, "rb");
    if (fdr == NULL) {
        printf("Open file failed");
        return 1;
    }
    fseek(fdr, 0, SEEK_END);
    mapSZ = ftell(fdr);//源文件的长度大小

    fseek(fdr, 0, SEEK_SET);
    fread(ehdr, sizeof(Elf32_Ehdr), 1, fdr);
    printf("\a mapSZ: %d  \n", mapSZ);
    printf("Magic:\t");
    for (MagNum = 0; MagNum < 16; MagNum++) {
        printf("%02x ", ehdr->e_ident[MagNum]);
    }
    printf("\n/*****elf header table****/\n");
    printf("e_type  %d\n", ehdr->e_type);
    printf("e_machine  %d\n", ehdr->e_machine);
    printf("e_version  %d\n", ehdr->e_version);
    printf("e_entry  %d\n", ehdr->e_entry);
    printf("e_phoff  %d\n", ehdr->e_phoff);
    printf("e_shoff  %d\n", ehdr->e_shoff);
    printf("e_flags  %d\n", ehdr->e_flags);
    printf("e_ehsize  %d\n", ehdr->e_ehsize);
    printf("e_phentsize  %d\n", ehdr->e_phentsize);
    printf("e_phnum  %d\n", ehdr->e_phnum);
    printf("e_shentsize  %d\n", ehdr->e_shentsize);
    printf("e_shnum  %d\n", ehdr->e_shnum);
    printf("e_shstrndx  %d\n", ehdr->e_shstrndx);


    printf("\n/*****section header table****/\n");
    int sectionnum = ehdr->e_shnum;
    Elf32_Shdr *sectionHeader = (Elf32_Shdr *) malloc(sizeof(Elf32_Shdr) * sectionnum);
    fseek(fdr, ehdr->e_shoff, SEEK_SET);
    int ret = fread(sectionHeader, sizeof(Elf32_Shdr), sectionnum, fdr);
    printf("ret = %d",ret);
    int symSize;
    int symOff;
    int nSyms;

    for (int i = 0; i < sectionnum; i++) {
        printf("sh_name  %d    ", sectionHeader->sh_name);
        printf("sh_type  %0x    ", sectionHeader->sh_type);
        printf("sh_flags  %d    ", sectionHeader->sh_flags);
        printf("sh_addr  %d    ", sectionHeader->sh_addr);
        printf("sh_offset  %d    ", sectionHeader->sh_offset);
        printf("sh_size  %d    ", sectionHeader->sh_size);
        printf("sh_link  %d    ", sectionHeader->sh_link);
        printf("sh_info  %d    ", sectionHeader->sh_info);
        printf("sh_addralign  %d    ", sectionHeader->sh_addralign);
        printf("sh_entsize  %d\n", sectionHeader->sh_entsize);
        if (sectionHeader->sh_type == 7) {
            printf("\n/*****section SHT_SYMTAB ****/\n");
            symSize = sectionHeader->sh_size;
            symOff = sectionHeader->sh_offset;
            symSize = sectionHeader->sh_size;


        }


        sectionHeader++;
    }


    return 0;
}

//int addSectionFun(char *path, char *szSecname, unsigned int nNewSecSize) {
//    char name[50];
//    FILE *fdr, *fdw;
//    char *base = NULL;
//    Elf32_Ehdr *ehdr;
//    Elf32_Phdr *t_phdr, *load1, *load2, *dynamic;
//    Elf32_Shdr *s_hdr;
//    int flag = 0;
//    int i = 0;
//    unsigned mapSZ = 0;
//    unsigned nLoop = 0;
//    unsigned int nAddInitFun = 0;
//    unsigned int nNewSecAddr = 0;
//    unsigned int nModuleBase = 0;
//    memset(name, 0, sizeof(name));
//    if (nNewSecSize == 0) {
//        return 0;
//    }
//    fdr = fopen(path, "rb");
//    strcpy(name, path);
//    if (strchr(name, '.')) {
//        strcpy(strchr(name, '.'), "_new.so");
//    } else {
//        strcat(name, "_new");
//    }
//    fdw = fopen(name, "wb");
//    if (fdr == NULL || fdw == NULL) {
//        printf("Open file failed");
//        return 1;
//    }
//    fseek(fdr, 0, SEEK_END);
//    mapSZ = ftell(fdr);//源文件的长度大小
//    printf("mapSZ:0x%x\n", mapSZ);
//
//    base = (char *) malloc(mapSZ * 2 + nNewSecSize);//2*源文件大小+新加的Section size
//    printf("base 0x%x \n", base);
//
//    memset(base, 0, mapSZ * 2 + nNewSecSize);
//    fseek(fdr, 0, SEEK_SET);
//    fread(base, 1, mapSZ, fdr);//拷贝源文件内容到base
//    if (base == (void *) -1) {
//        printf("fread fd failed");
//        return 2;
//    }
//
//    //判断Program Header
//    ehdr = (Elf32_Ehdr *) base;
//    t_phdr = (Elf32_Phdr *) (base + sizeof(Elf32_Ehdr));
//    for (i = 0; i < ehdr->e_phnum; i++) {
//        if (t_phdr->p_type == PT_LOAD) {
//            //这里的flag只是一个标志位，去除第一个LOAD的Segment的值
//            if (flag == 0) {
//                load1 = t_phdr;
//                flag = 1;
//                nModuleBase = load1->p_vaddr;
//                printf("load1 = %p, offset = 0x%x \n", load1, load1->p_offset);
//
//            } else {
//                load2 = t_phdr;
//                printf("load2 = %p, offset = 0x%x \n", load2, load2->p_offset);
//            }
//        }
//        if (t_phdr->p_type == PT_DYNAMIC) {
//            dynamic = t_phdr;
//            printf("dynamic = %p, offset = 0x%x \n", dynamic, dynamic->p_offset);
//        }
//        t_phdr++;
//    }
//
//    //section header
//    s_hdr = (Elf32_Shdr *) (base + ehdr->e_shoff);
//    //获取到新加section的位置，这个是重点,需要进行页面对其操作
//    printf("addr:0x%x\n", load2->p_paddr);
//    nNewSecAddr = ALIGN(load2->p_paddr + load2->p_memsz - nModuleBase, load2->p_align);
//    printf("new section add:%x \n", nNewSecAddr);
//
//    if (load1->p_filesz < ALIGN(load2->p_paddr + load2->p_memsz, load2->p_align)) {
//        printf("offset:%x\n", (ehdr->e_shoff + sizeof(Elf32_Shdr) * ehdr->e_shnum));
//        //注意这里的代码的执行条件，这里其实就是判断section header是不是在文件的末尾
//        if ((ehdr->e_shoff + sizeof(Elf32_Shdr) * ehdr->e_shnum) != mapSZ) {
//            if (mapSZ + sizeof(Elf32_Shdr) * (ehdr->e_shnum + 1) > nNewSecAddr) {
//                printf("无法添加节\n");
//                return 3;
//            } else {
//                memcpy(base + mapSZ, base + ehdr->e_shoff,
//                       sizeof(Elf32_Shdr) * ehdr->e_shnum);//将Section Header拷贝到原来文件的末尾
//                ehdr->e_shoff = mapSZ;
//                mapSZ += sizeof(Elf32_Shdr) * ehdr->e_shnum;//加上Section Header的长度
//                s_hdr = (Elf32_Shdr *) (base + ehdr->e_shoff);
//                printf("ehdr_offset:%x", ehdr->e_shoff);
//            }
//        }
//    } else {
//        nNewSecAddr = load1->p_filesz;
//    }
//    printf("还可添加 %d 个节\n", (nNewSecAddr - ehdr->e_shoff) / sizeof(Elf32_Shdr) - ehdr->e_shnum - 1);
//
//    int nWriteLen = nNewSecAddr + ALIGN(strlen(szSecname) + 1, 0x10) +
//                    nNewSecSize;//添加section之后的文件总长度：原来的长度 + section name + section size
//    printf("write len %x\n", nWriteLen);
//
//    char *lpWriteBuf = (char *) malloc(nWriteLen);//nWriteLen :最后文件的总大小
//    memset(lpWriteBuf, 0, nWriteLen);
//    //ehdr->e_shstrndx是section name的string表在section表头中的偏移值,修改string段的大小
//    s_hdr[ehdr->e_shstrndx].sh_size = nNewSecAddr - s_hdr[ehdr->e_shstrndx].sh_offset + strlen(szSecname) + 1;
//    strcpy(lpWriteBuf + nNewSecAddr, szSecname);//添加section name
//
//    //以下代码是构建一个Section Header
//    Elf32_Shdr newSecShdr = {0};
//    newSecShdr.sh_name = nNewSecAddr - s_hdr[ehdr->e_shstrndx].sh_offset;
//    newSecShdr.sh_type = SHT_PROGBITS;
//    newSecShdr.sh_flags = SHF_WRITE | SHF_ALLOC | SHF_EXECINSTR;
//    nNewSecAddr += ALIGN(strlen(szSecname) + 1, 0x10);
//    newSecShdr.sh_size = nNewSecSize;
//    newSecShdr.sh_offset = nNewSecAddr;
//    newSecShdr.sh_addr = nNewSecAddr + nModuleBase;
//    newSecShdr.sh_addralign = 4;
//
//    //修改Program Header信息
//    load1->p_filesz = nWriteLen;
//    load1->p_memsz = nNewSecAddr + nNewSecSize;
//    load1->p_flags = 7;      //可读 可写 可执行
//
//    //修改Elf header中的section的count值
//    ehdr->e_shnum++;
//    memcpy(lpWriteBuf, base, mapSZ);//从base中拷贝mapSZ长度的字节到lpWriteBuf
//    memcpy(lpWriteBuf + mapSZ, &newSecShdr, sizeof(Elf32_Shdr));//将新加的Section Header追加到lpWriteBuf末尾
//
//    //写文件
//    fseek(fdw, 0, SEEK_SET);
//    fwrite(lpWriteBuf, 1, nWriteLen, fdw);
//    fclose(fdw);
//    fclose(fdr);
//    free(base);
//    free(lpWriteBuf);
//    return 0;
//}