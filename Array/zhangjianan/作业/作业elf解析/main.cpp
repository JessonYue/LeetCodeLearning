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

void parseElf();

char *getMachine(Elf64_Half machine);
char *getSectionTypeNameByType(uint64_t type) {
    // 注意，这里不可以直接：name = "NULL"这样进行赋值，只能通过strcpy这个函数或者自己逐个字符读写
    switch (type) {
        case SHT_NULL:
            return "NULL";
        case SHT_PROGBITS:
            return "PROGBITS";
        case SHT_SYMTAB:
            return "SYMTAB";
        case SHT_STRTAB:
            return "STRTAB";
        case SHT_RELA:
            return "RELA";
        case SHT_HASH:
            return "HASH";
        case SHT_DYNAMIC:
            return "DYNAMIC";
        case SHT_NOTE:
            return "NOTE";
        case SHT_NOBITS:
            return "NOBITS";
        case SHT_REL:
            return "REL";
        case SHT_SHLIB:
            return "SHLIB";
        case SHT_DYNSYM:
            return "DYNSYM";
        case SHT_INIT_ARRAY:
            return "INIT_ARRAY";
        case SHT_FINI_ARRAY:
            return "FINI_ARRAY";
        case SHT_PREINIT_ARRAY:
            return "PREINIT_ARRAY";
        case SHT_GROUP:
            return "GROUP";
        case SHT_SYMTAB_SHNDX:
            return "SYMTAB_SHNDX";
        case SHT_NUM:
            return "NUM";
        case SHT_LOOS:
            return "LOOS";
        case SHT_GNU_ATTRIBUTES:
            return "GNU_ATTRIBUTES";
        case SHT_GNU_HASH:
            return "GNU_HASH";
        case SHT_GNU_LIBLIST:
            return "GNU_LIBLIST";

        case SHT_CHECKSUM:
            return "CHECKSUM";

        case SHT_LOSUNW:
            return "LOSUNW";

        case SHT_SUNW_COMDAT:
            return "SUNW_COMDAT";

        case SHT_SUNW_syminfo:
            return "SUNW_syminfo";

        case SHT_GNU_verdef:
            return "GNU_verdef";

        case SHT_GNU_verneed:
            return "GNU_verneed";

        case SHT_GNU_versym:
            return "GNU_versym";

        case SHT_LOPROC:
            return "LOPROC";

        case SHT_HIPROC:
            return "HIPROC";

        case SHT_LOUSER:
            return "LOUSER";

        case SHT_HIUSER:
            return "HIUSER";

        default:
            return "NULL";
    }
}

void getSectionFlagNameByFlags(uint64_t flags, char flag[]) {
    memset(flag, '\0', 12);
    char temp[12];
    memset(temp, '\0', 12);
    int index = 0;
    uint64_t result = 0;
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
//W #define SHF_WRITE               (1 << 0)    /* Writable */
//A #define SHF_ALLOC               (1 << 1)    /* Occupies memory during execution */
//X #define SHF_EXECINSTR           (1 << 2)    /* Executable */
//M #define SHF_MERGE               (1 << 4)    /* Might be merged */
//S #define SHF_STRINGS             (1 << 5)    /* Contains nul-terminated strings */
//I #define SHF_INFO_LINK           (1 << 6)    /* `sh_info' contains SHT index */
//L #define SHF_LINK_ORDER          (1 << 7)    /* Preserve order after combining */
//#define SHF_OS_NONCONFORMING    (1 << 8)    /* Non-standard OS specific handling required */
//G #define SHF_GROUP               (1 << 9)    /* Section is member of a group.  */
//#define SHF_TLS                 (1 << 10)   /* Section hold thread-local data.  */
//#define SHF_COMPRESSED          (1 << 11)   /* Section with compressed data. */
//o #define SHF_MASKOS              0x0ff00000  /* OS-specific.  */
//p #define SHF_MASKPROC            0xf0000000  /* Processor-specific */
//p #define SHF_ORDERED             (1 << 30)   /* Special ordering requirement (Solaris).  */
//p #define SHF_EXCLUDE             (1U << 31)  /* Section is excluded unless referenced or allocated (Solaris).*/
}
void printElf64_Shdr(int index, Elf64_Shdr elf64Shdr, char strtab[]) {
    printf("[%2d]\t", index);
    char name[20];
    memset(name, '\0', 20);//添加字符串结尾
    name[0] = strtab[elf64Shdr.sh_name];//利用表明偏移量取出第一个字符
    int i = 1;
    while (strtab[elf64Shdr.sh_name + i]  != 0) {//取出偏移量起始  0结束的所有字符
        name[i] = strtab[elf64Shdr.sh_name + i];
        i++;
    }
    printf("%-20s", name);
    printf("%-16s", getSectionTypeNameByType(elf64Shdr.sh_type));
    char flag[12];
    getSectionFlagNameByFlags(elf64Shdr.sh_flags, flag);
    printf("%-12s", flag);
    printf("0x%x \t", elf64Shdr.sh_addr);
    printf("0x%x \t", elf64Shdr.sh_offset);
    printf("0x%x \t", elf64Shdr.sh_size);
    printf("0x%x \t", elf64Shdr.sh_link);
    printf("0x%x \t", elf64Shdr.sh_info);
    printf("0x%x \t", elf64Shdr.sh_addralign);
    printf("0x%x \t", elf64Shdr.sh_entsize);
    printf("\n");
}
int main() {
    parseElf();
    return 0;
}
void printfElf32_PhdrMessage(FILE *elf, int offset, int e_phnum) {
    // int fseek(FILE *stream, long int offset, int whence) 设置流 stream 的文件位置为给定的偏移 offset，参数 offset 意味着从给定的 whence 位置查找的字节数。
    // fseek(elf, 0, SEEK_SET);
    // 将文件位置标识移动到程序头部位置
    fseek(elf, offset, SEEK_SET);
    // long int ftell(FILE *stream) 返回给定流 stream 的当前文件位置
    printf("Program header from %ld bytes\n", ftell(elf));
    printf("The Program Header Message:\n");
    Elf64_Phdr *phdr = static_cast<Elf64_Phdr *>(malloc(e_phnum * sizeof(Elf64_Phdr)));
    if (e_phnum == fread(phdr, sizeof(Elf64_Phdr), e_phnum, elf)) {
        Elf64_Phdr *p = phdr;
        printf("Type\t\tOffset\t\tVirtAddr\tPhysAddr\tFileSiz\t\tMemSiz\t\tFlg\tAl\n");
        for (int i = 0; i < e_phnum; ++i, p++) {
            printf("%-10x\t%-#6x\t\t%-#6x\t\t%-#6x\t\t%-#5x\t\t%-#5x\t\t%-#x\t%-2d\n", \
                p->p_type, p->p_offset, \
                p->p_vaddr, p->p_paddr, \
                p->p_filesz, p->p_memsz, \
                p->p_flags, p->p_align);
        }
    } else
        printf("Read program header fail\n");
    free(phdr);
    phdr = NULL;
}

/**
 *解析头部
 * @param hdr
 */
void parseElf() {
    FILE *pIobuf;
    if ((pIobuf = fopen("../sub.so", "r")) == NULL) {//打开文件
        printf("file open file");
        exit(0);
    }
    Elf64_Ehdr hdr;
    fread(&hdr, sizeof(Elf64_Ehdr), 1, pIobuf);//读取头部信息
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
    /**section header**/
    int sechnum = 0;
     sechnum = hdr.e_shnum;
    Elf64_Shdr section_header[sechnum] ;
    fseek(pIobuf,hdr.e_shoff,SEEK_SET);
    printf("\n/*****section header table****/\n");

    fread(section_header,sizeof( Elf64_Shdr),sechnum,pIobuf);
    printf("[Nr] Name          Type          Addr         Off      Size     ES Flg  Al \n");
    Elf64_Shdr str_shdr = section_header[hdr.e_shstrndx];
    char strtab[str_shdr.sh_size];
    //读取字符表
    fseek(pIobuf, str_shdr.sh_offset, SEEK_SET);
    fread(strtab, str_shdr.sh_size, 1, pIobuf);

    for(int i=0; i<sechnum; i++) {
        printElf64_Shdr(i, section_header[i], strtab);

    }
    printf("======Program header table Size %d======\n", hdr.e_phnum);
    printfElf32_PhdrMessage(pIobuf, hdr.e_phoff, hdr.e_phnum);
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



