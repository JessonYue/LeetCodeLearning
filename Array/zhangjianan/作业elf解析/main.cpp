//
// Created by 张佳男 on 2020/6/9.
//

#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <sys/stat.h>
#include <stdint-gcc.h>
#include <process.h>
#include "elf.h"

Elf64_Ehdr loadFile();

void readElfHeader(Elf64_Ehdr *file);

Elf64_Ehdr readElf();

void parseElf(Elf64_Ehdr hdr);

char *getMachine(Elf64_Half machine);

Elf64_Ehdr readElf() {
    FILE *fp;
    if ((fp = fopen("../sub.so", "r")) == NULL) {//打开文件
        printf("file open file");
        exit(0);
    }
    Elf64_Ehdr buff;
    fread(&buff, sizeof(Elf64_Ehdr), 1, fp);
    return buff;
}


int main() {
    Elf64_Ehdr elf = readElf();
    parseElf(elf);
//    Elf64_Ehdr file = loadFile();
//    readElfHeader(&file);
    return 0;
}

/**
 *解析头部
 * @param hdr
 */
void parseElf(Elf64_Ehdr hdr) {
    printf("Magic:     ");//ELF魔数 16个字节 程序员自我修养》72页
    for (int i = 0; i < EI_NIDENT; ++i) {
        printf("%02x ", hdr.e_ident[i]);
    }
    printf("\n");
    printf("\nClass:     ");
    //Magic最开始4个字节是所有ELF文件必须相同的表示码，0x7f 0x45 0x4c 0x46 ---《程序员自我修养》73页 0x45 0x4c 0x46(ELF的ASCII码)
    //Class  ELF文件类型 0x01是32位，ox02是64位
    switch (hdr.e_ident[4]) {
        case 1:
            printf("Elf32\n");
            break;

        case 2:
            printf("Elf64\n");
            break;

    }
    //Data   大小端
    printf("Data:      ");
    switch (hdr.e_ident[5]) {
        case 1:
            printf("2's complement, little endian\n");
            break;
        case 2:
            printf("2's complement, big endian\n");
            break;
    }
    //Version  默认版本为1
    printf("Version:   ");
    printf("%d(current)\n", hdr.e_ident[6]);
    //os version
    printf("OS/ABI:    UNIX - System V\n");

    //ABI Version
    printf("ABI Version:   0\n");
    //文件类型
    printf("Type:    ");
    switch (hdr.e_type) {
        case 1://ET_REL可重定位文件，一般位.o文件
            printf("Relocatable file\n");
            break;
        case 2://ET_EXEC可执行文件
            printf("Executable file\n");
            break;
        case 3://ET_DYN共享目标文件，一般为so文件
            printf("Shared object file\n");
            break;
    }
    // 架构Machine
    printf("Machine:    %d\n", hdr.e_machine);
//    char *machine = getMachine(hdr.e_machine);
    // 文件版本
    printf("Version:    %hx\n", hdr.e_version);
    //入口点的虚拟地址
    printf("Entry point address:    0x%lx\n", hdr.e_entry);
    // 程序头部表偏移量
    printf("e_phoff:    %d\n", hdr.e_phoff);
    // 节头部表偏移量
    printf("e_shoff:    %d\n", hdr.e_shoff);
    // 保存与文件相关的，特定于处理器的标志
    printf("e_flags:    0x%x\n", hdr.e_flags);
    // ELF 头大小(字节)
    printf("e_ehsize:    %d\n", hdr.e_ehsize);
    // 程序头部条目大小
    printf("e_phentsize:    %d\n", hdr.e_phentsize);
    // 程序头部条目数量
    printf("e_phnum:    %d\n", hdr.e_phnum);
    // 节头部条目大小
    printf("e_shentsize:    %d\n", hdr.e_shentsize);
    // 节头部条目数量
    printf("e_shnum:    %d\n", hdr.e_shnum);
    // 节头部字符串表的索引
    printf("e_shstrndx:    %d\n", hdr.e_shstrndx);

}

char *getMachine(Elf64_Half machine) {

    /*  EM_NONE = 0, //No machine
              EM_M32          = 1,    //AT&T WE 32100
      EM_SPARC        = 2,    //SPARC
          EM_386          = 3,    //Intel 80386
          EM_68K          = 4,    //Motorola 68000
          EM_88K          = 5,    //Motorola 88000
          reserved6      = 6,    //Reserved for future use (was EM_486)
          EM_860          = 7,    //Intel 80860
          EM_MIPS        = 8,    //MIPS I Architecture
          EM_S370        = 9,    //IBM System/370 Processor
          EM_MIPS_RS3_LE  = 10,    //MIPS RS3000 Little-endian
          reserved11      = 11,    //Reserved for future use
          reserved12      = 12,    //Reserved for future use
          reserved13      = 13,    //Reserved for future use
          reserved14      = 14,    //Reserved for future use
          EM_PARISC      = 15,    //Hewlett-Packard PA-RISC
          reserved16      = 16,    //Reserved for future use
          EM_VPP500      = 17,    //Fujitsu VPP500
          EM_SPARC32PLUS  = 18,    //Enhanced instruction set SPARC
          EM_960          = 19,    //Intel 80960
          EM_PPC          = 20,    //PowerPC
          EM_PPC64        = 21,    //64-bit PowerPC
          EM_S390        = 22,    //IBM System/390 Processor
          reserved23      = 23,    //Reserved for future use
          reserved24      = 24,    //Reserved for future use
          reserved25      = 25,    //Reserved for future use
          reserved26      = 26,    //Reserved for future use
          reserved27      = 27,    //Reserved for future use
          reserved28      = 28,    //Reserved for future use
          reserved29      = 29,    //Reserved for future use
          reserved30      = 30,    //Reserved for future use
          reserved31      = 31,    //Reserved for future use
          reserved32      = 32,    //Reserved for future use
          reserved33      = 33,    //Reserved for future use
          reserved34      = 34,    //Reserved for future use
          reserved35      = 35,    //Reserved for future use
          EM_V800        = 36,    //NEC V800
          EM_FR20        = 37,    //Fujitsu FR20
          EM_RH32        = 38,    //TRW RH-32
          EM_RCE          = 39,    //Motorola RCE
          EM_ARM          = 40,    //Advanced RISC Machines ARM
          EM_ALPHA        = 41,    //Digital Alpha
          EM_SH          = 42,    //Hitachi SH
          EM_SPARCV9      = 43,    //SPARC Version 9
          EM_TRICORE      = 44,    //Siemens TriCore embedded processor
          EM_ARC          = 45,    //Argonaut RISC Core, Argonaut Technologies Inc.
          EM_H8_300      = 46,    //Hitachi H8/300
          EM_H8_300H      = 47,    //Hitachi H8/300H
          EM_H8S          = 48,    //Hitachi H8S
          EM_H8_500      = 49,    //Hitachi H8/500
          EM_IA_64        = 50,    //Intel IA-64 processor architecture
          EM_MIPS_X      = 51,    //Stanford MIPS-X
          EM_COLDFIRE    = 52,    //Motorola ColdFire
          EM_68HC12      = 53,    //Motorola M68HC12
          EM_MMA          = 54,    //Fujitsu MMA Multimedia Accelerator
          EM_PCP          = 55,    //Siemens PCP
          EM_NCPU        = 56,    //Sony nCPU embedded RISC processor
          EM_NDR1        = 57,    //Denso NDR1 microprocessor
          EM_STARCORE    = 58,    //Motorola Star*Core processor
          EM_ME16        = 59,    //Toyota ME16 processor
          EM_ST100        = 60,    //STMicroelectronics ST100 processor
          EM_TINYJ        = 61,    //Advanced Logic Corp. TinyJ embedded processor family
          EM_X86_64      = 62,    //AMD x86-64 architecture
          EM_PDSP        = 63,    //Sony DSP Processor
          EM_PDP10        = 64,    //Digital Equipment Corp. PDP-10
          EM_PDP11        = 65,    //Digital Equipment Corp. PDP-11
          EM_FX66        = 66,    //Siemens FX66 microcontroller
          EM_ST9PLUS      = 67,    //STMicroelectronics ST9+ 8/16 bit microcontroller
          EM_ST7          = 68,    //STMicroelectronics ST7 8-bit microcontroller
          EM_68HC16      = 69,    //Motorola MC68HC16 Microcontroller
          EM_68HC11      = 70,    //Motorola MC68HC11 Microcontroller
          EM_68HC08      = 71,    //Motorola MC68HC08 Microcontroller
          EM_68HC05      = 72,    //Motorola MC68HC05 Microcontroller
          EM_SVX          = 73,    //Silicon Graphics SVx
          EM_ST19        = 75,    //Digital VAX
          EM_CRIS        = 76,    //Axis Communications 32-bit embedded processor
          EM_JAVELIN      = 77,    //Infineon Technologies 32-bit embedded processor
          EM_FIREPATH    = 78,    //Element 14 64-bit DSP Processor
          EM_ZSP          = 79,    //LSI Logic 16-bit DSP Processor
          EM_MMIX        = 80,    //Donald Knuth's educational 64-bit processor
          EM_HUANY        = 81,    //Harvard University machine-independent object files
          EM_PRISM        = 82,    //SiTera Prism
          EM_AVR          = 83,    //Atmel AVR 8-bit microcontroller
          EM_FR30        = 84,    //Fujitsu FR30
          EM_D10V        = 85,    //Mitsubishi D10V
          EM_D30V        = 86,    //Mitsubishi D30V
          EM_V850        = 87,    //NEC v850
          EM_M32R        = 88,    //Mitsubishi M32R
          EM_MN10300      = 89,    //Matsushita MN10300
          EM_MN10200      = 90,    //Matsushita MN10200
          EM_PJ          = 91,    //picoJava
          EM_OPENRISC    = 92,    //OpenRISC 32-bit embedded processor
          EM_ARC_A5      = 93,    //ARC Cores Tangent-A5
          EM_XTENSA      = 94,    //Tensilica Xtensa Architecture
          EM_VIDEOCORE    = 95,    //Alphamosaic VideoCore processor
          EM_TMM_GPP      = 96,    //Thompson Multimedia General Purpose Processor
          EM_NS32K        = 97,    //National Semiconductor 32000 series
          EM_TPC          = 98,    //Tenor Network TPC processor
          EM_SNP1K        = 99,    //Trebia SNP 1000 processor
          EM_ST200        = 100,    //STMicroelectronics (www.st.com) ST200 microcontroller
          EM_IP2K        = 101,    //Ubicom IP2xxx microcontroller family
          EM_MAX          = 102,    //MAX Processor
          EM_CR          = 103,    //National Semiconductor CompactRISC microprocessor
          EM_F2MC16      = 104,    //Fujitsu F2MC16
          EM_MSP430      = 105,    //Texas Instruments embedded microcontroller msp430
          EM_BLACKFIN    = 106,    //Analog Devices Blackfin (DSP) processor
          EM_SE_C33      = 107,    //S1C33 Family of Seiko Epson processors
          EM_SEP          = 108,    //Sharp embedded microprocessor
          EM_ARCA        = 109,    //Arca RISC Microprocessor
          EM_UNICORE      = 110    //Microprocessor series from PKU-Unity Ltd. and MPRC of Peking
  */
    return nullptr;
}

void readElfHeader(Elf64_Ehdr file) {

    /*  printf("\nClass:     ");
      //Magic最开始4个字节是所有ELF文件必须相同的表示码，0x7f 0x45 0x4c 0x46 ---《程序员自我修养》73页 0x45 0x4c 0x46(ELF的ASCII码)
      //Class  ELF文件类型 0x01是32位，ox02是64位
      switch (file[4]) {
          case 1:
              printf("Elf32\n");
              break;

          case 2:
              printf("Elf64\n");
              break;

      }
      //Data   大小端
      printf("Data:      ");
      switch(file[5])
      {
          case 1:
              printf("2's complement, little endian\n");
              break;
          case 2:
              printf("2's complement, big endian\n");
              break;
      }
      //Version  默认版本为1
      printf( "Version:   ");
      printf("%d(current)\n", file[6]);
      //os version
      printf("OS/ABI:    UNIX - System V\n");

      //ABI Version
      printf( "ABI Version:   0\n");
      //文件类型
      printf( "Type:    ");
      file+=16;
      switch (*(unsigned short int*)file) {
          case 1://ET_REL可重定位文件，一般位.o文件
              printf("Relocatable file\n");
              break;
          case 2://ET_EXEC可执行文件
              printf("Executable file\n");
              break;
          case 3://ET_DYN共享目标文件，一般为so文件
              printf("Shared object file\n");
              break;
      }
      //Machine
      printf( "Machine:    ");

      file += sizeof(unsigned short int);
      switch(*(unsigned short int*)file)
      {
          case 1:
              printf(" Intel 80386\n");
              break;
          case 2:
              printf(" ARM\n");
              break;
          case 3:
              printf(" AMD X86-64 arrchitecture\n");
              break;
          case 4:
              printf(" AARCH64\n");
              break;
          case 5:
              printf(" AARCH64\n");
              break;
          case 6:
              printf(" AARCH64\n");
              break;
      }*/
}

Elf64_Ehdr loadFile() {
//    char *pathname = "../libget.so";
    FILE *fp;
    if ((fp = fopen("../sub.so", "r")) == NULL) {//打开文件
        printf("file open file");
        exit(0);
    }
    struct stat *_Stat = (struct stat *) malloc(sizeof(struct stat *));
//    int s = stat(pathname, _Stat);
//    int filesize = _Stat->st_size;
    //求得文件的大小
    fseek(fp, 0L, SEEK_END);//
    long inputFileLength = ftell(fp);//返回给定流 stream 的当前文件位置。
    rewind(fp);//设置文件位置为给定流 stream 的文件的开头。
//    char *buff = (char *) malloc(sizeof(char) * inputFileLength);
    Elf64_Ehdr buff;
    fread(&buff, sizeof(Elf64_Ehdr), 1, fp);
//    int size = fread(buff, 1, inputFileLength, fp);
//    int size = fread(&buff, 1, inputFileLength, fp);
//    for (int i = 0; i < size; ++i) {
//        printf("%02x ",buff[i]);
//        if ((i+1)%16==0) {
//            printf("\n ");
//        }
//    }
    printf("Magic:     ");//ELF魔数 16个字节 程序员自我修养》72页
    for (int i = 0; i < EI_NIDENT; ++i) {
        printf("%02x ", buff.e_ident[i]);
    }
    return buff;
}