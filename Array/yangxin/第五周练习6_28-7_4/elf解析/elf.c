//
// Created by 12 on 2020/6/22.
//

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "elf.h"

void printElfMagicNumber(Elf64_Ehdr *elf_Head) {
    printf("ELF MagicNumber %x%c%c%c", elf_Head->e_ident[EI_MAG0], elf_Head->e_ident[EI_MAG1],
           elf_Head->e_ident[EI_MAG2],
           elf_Head->e_ident[EI_MAG3]);
    printf("\n");
}

void printEI_CLASS(Elf64_Ehdr *elf_Head) {
    switch (elf_Head->e_ident[EI_CLASS]) {
        case ELFCLASSNONE:
            printf("EI_CLASS Invalid class");
            break;
        case ELFCLASS32:
            printf("EI_CLASS 32-bit objects");
            break;
        case ELFCLASS64:
            printf("EI_CLASS 64-bit objects");
            break;
    }
    printf("\n");
}

void printEI_DATA(Elf64_Ehdr *elf_Head) {
    switch (elf_Head->e_ident[EI_DATA]) {
        case ELFDATANONE:
            printf("EI_DATA Invalid data encoding");
            break;
        case ELFDATA2LSB:
            printf("EI_DATA 2's complement, little endian");
            break;
        case ELFDATA2MSB:
            printf("EI_DATA 2's complement, big endian");
            break;
    }
    printf("\n");
}

void printEI_VERSION(Elf64_Ehdr *elf_Head) {
    printf("EI_VERSION 0x%x", elf_Head->e_ident[EI_VERSION]);
    printf("\n");
}

void printEI_OSABI(Elf64_Ehdr *elf_Head) {
    switch (elf_Head->e_ident[EI_OSABI]) {
        case ELFOSABI_NONE:
            printf("EI_OSABI UNIX System V ABI");
            break;
//        case ELFOSABI_SYSV:
//            printf("EI_OSABI Alias.");
            break;
        case ELFOSABI_HPUX:
            printf("EI_OSABI HP-UX");
            break;
        case ELFOSABI_NETBSD:
            printf("EI_OSABI NetBSD.");
            break;
        case ELFOSABI_GNU:
            printf("EI_OSABI Object uses GNU ELF extensions.Compatibility alias.");
            break;
//        case ELFOSABI_LINUX:
//            printf("EI_OSABI ");
//            break;
        case ELFOSABI_SOLARIS:
            printf("EI_OSABI Sun Solaris.");
            break;
        case ELFOSABI_AIX:
            printf("EI_OSABI IBM AIX.");
            break;
        case ELFOSABI_IRIX:
            printf("EI_OSABI SGI Irix.");
            break;
        case ELFOSABI_FREEBSD:
            printf("EI_OSABI FreeBSD.");
            break;
        case ELFOSABI_TRU64:
            printf("EI_OSABI Compaq TRU64 UNIX.");
            break;
        case ELFOSABI_MODESTO:
            printf("EI_OSABI Novell Modesto.");
            break;
        case ELFOSABI_OPENBSD:
            printf("EI_OSABI OpenBSD.");
            break;
        case ELFOSABI_ARM_AEABI:
            printf("EI_OSABI ARM EABI");
            break;
        case ELFOSABI_ARM:
            printf("EI_OSABI ARM");
            break;
        case ELFOSABI_STANDALONE:
            printf("EI_OSABI Standalone (embedded) application");
            break;
        default:
            printf("EI_OSABI val 0x%x", elf_Head->e_ident[EI_OSABI]);
    }

    printf("\n");
}

void printEI_ABIVERSION(Elf64_Ehdr *elf_Head) {
    printf("EI_ABIVERSION 0x%x", elf_Head->e_ident[EI_ABIVERSION]);
    printf("\n");
}

void printEI_PAD(Elf64_Ehdr *elf_Head) {
    printf("EI_PAD ");
    for (int i = EI_PAD; i < EI_NIDENT; i++) {
        printf("0x%x", elf_Head->e_ident[i]);
    }
    printf("\n");
}

void printE_type(Elf64_Ehdr *elf_Head) {
    printf("E_type ");
    switch (elf_Head->e_type) {
        case ET_NONE:
            printf("No file type");
            break;
        case ET_REL:
            printf("Relocatable file");
            break;
        case ET_EXEC:
            printf("Executable file");
            break;
        case ET_DYN:
            printf("Shared object file");
            break;
        case ET_CORE:
            printf("Core file");
            break;
        case ET_NUM:
            printf("Number of defined types");
            break;
        case ET_LOOS:
            printf("OS-specific range start");
            break;
        case ET_HIOS:
            printf("OS-specific range end");
            break;
        case ET_LOPROC:
            printf("Processor-specific range start");
            break;
        case ET_HIPROC:
            printf("Processor-specific range end");
            break;
        default:
            printf("val 0x%x", elf_Head->e_type);
    }
    printf("\n");
}

void printE_machine(Elf64_Ehdr *elf_Head) {
    printf("E_machine ");
    switch (elf_Head->e_machine) {
        case EM_NONE:
            printf("No machine");
            break;
        case EM_M32:
            printf("AT&T WE 32100");
            break;
        case EM_SPARC:
            printf("SUN SPARC");
            break;
        case EM_386:
            printf("Intel 80386");
            break;
        case EM_68K:
            printf("Motorola m68k family");
            break;
        case EM_88K:
            printf("Motorola m88k family");
            break;
        case EM_IAMCU:
            printf("Intel MCU");
            break;
        case EM_860:
            printf("Intel 80860");
            break;
        case EM_MIPS:
            printf("MIPS R3000 big-endian");
            break;
        case EM_S370:
            printf("IBM System/370");
            break;
        case EM_MIPS_RS3_LE:
            printf("MIPS R3000 little-endian");
            break;
        case EM_PARISC:
            printf("HPPA");
            break;
        case EM_VPP500:
            printf("Fujitsu VPP500");
            break;
        case EM_SPARC32PLUS:
            printf("Sun's \"v8plus");
            break;
        case EM_960:
            printf("Intel 80960");
            break;
        case EM_PPC:
            printf("PowerPC");
            break;
        case EM_PPC64:
            printf("PowerPC 64-bit");
            break;
        case EM_S390:
            printf("IBM S390");
            break;
        case EM_SPU:
            printf("IBM SPU/SPC");
            break;
        case EM_V800:
            printf("NEC V800 series");
            break;
        case EM_FR20:
            printf("Fujitsu FR20");
            break;
        case EM_RH32:
            printf("TRW RH-32");
            break;
        case EM_RCE:
            printf("Motorola RCE");
            break;
        case EM_ARM:
            printf("ARM");
            break;
        case EM_FAKE_ALPHA:
            printf("Digital Alpha");
            break;
        case EM_SH:
            printf("Hitachi SH");
            break;
        case EM_SPARCV9:
            printf("SPARC v9 64-bit");
            break;
        case EM_TRICORE:
            printf("Siemens Tricore");
            break;
        case EM_ARC:
            printf("Argonaut RISC Core");
            break;
        case EM_H8_300:
            printf("Hitachi H8/300");
            break;
        case EM_H8_300H:
            printf("Hitachi H8/300H");
            break;
        case EM_H8S:
            printf("Hitachi H8S");
            break;
        case EM_H8_500:
            printf("Hitachi H8/500");
            break;
        case EM_IA_64:
            printf("Intel Merced");
            break;
        case EM_MIPS_X:
            printf("Stanford MIPS-X");
            break;
        case EM_COLDFIRE:
            printf("Motorola Coldfire");
            break;
        case EM_68HC12:
            printf("Motorola M68HC12");
            break;
        case EM_MMA:
            printf("Fujitsu MMA Multimedia Accelerator");
            break;
        case EM_PCP:
            printf("Siemens PCP");
            break;
        case EM_NCPU:
            printf("Sony nCPU embeeded RISC");
            break;
        case EM_NDR1:
            printf("Denso NDR1 microprocessor");
            break;
        case EM_STARCORE:
            printf("Motorola Start*Core processor");
            break;
        case EM_ME16:
            printf("Toyota ME16 processor");
            break;
        case EM_ST100:
            printf("STMicroelectronic ST100 processor");
            break;
        case EM_TINYJ:
            printf("Advanced Logic Corp. Tinyj emb.fam");
            break;
        case EM_X86_64:
            printf("AMD x86-64 architecture");
            break;
        case EM_PDSP:
            printf("Sony DSP Processor");
            break;
        case EM_PDP10:
            printf("Digital PDP-10");
            break;
        case EM_PDP11:
            printf("Digital PDP-11");
            break;
        case EM_FX66:
            printf("Siemens FX66 microcontroller");
            break;
        case EM_ST9PLUS:
            printf("STMicroelectronics ST9+ 8/16 mc");
            break;
        case EM_ST7:
            printf("STmicroelectronics ST7 8 bit mc");
            break;
        case EM_68HC16:
            printf("Motorola MC68HC16 microcontroller");
            break;
        case EM_68HC11:
            printf("Motorola MC68HC11 microcontroller");
            break;
        case EM_68HC08:
            printf("Motorola MC68HC08 microcontroller");
            break;
        case EM_68HC05:
            printf("Motorola MC68HC05 microcontroller");
            break;
        case EM_SVX:
            printf("Silicon Graphics SVx");
            break;
        case EM_ST19:
            printf("STMicroelectronics ST19 8 bit mc");
            break;
        case EM_VAX:
            printf("Digital VAX");
            break;
        case EM_CRIS:
            printf("Axis Communications 32-bit emb.proc");
            break;
        case EM_JAVELIN:
            printf("Infineon Technologies 32-bit emb.proc");
            break;
        case EM_FIREPATH:
            printf("Element 14 64-bit DSP Processor");
            break;
        case EM_ZSP:
            printf("LSI Logic 16-bit DSP Processor");
            break;
        case EM_MMIX:
            printf("Donald Knuth's educational 64-bit proc");
            break;
        case EM_HUANY:
            printf("Harvard University machine-independent object files");
            break;
        case EM_PRISM:
            printf("SiTera Prism");
            break;
        case EM_AVR:
            printf("Atmel AVR 8-bit microcontroller");
            break;
        case EM_FR30:
            printf("Fujitsu FR30");
            break;
        case EM_D10V:
            printf("Mitsubishi D10V");
            break;
        case EM_D30V:
            printf("Mitsubishi D30V");
            break;
        case EM_V850:
            printf("NEC v850");
            break;
        case EM_M32R:
            printf("Mitsubishi M32R");
            break;
        case EM_MN10300:
            printf("Matsushita MN10300");
            break;
        case EM_MN10200:
            printf("Matsushita MN10200");
            break;
        case EM_PJ:
            printf("picoJava");
            break;
        case EM_OPENRISC:
            printf("OpenRISC 32-bit embedded processor");
            break;
        case EM_ARC_COMPACT:
            printf("ARC International ARCompact");
            break;
        case EM_XTENSA:
            printf("Tensilica Xtensa Architecture");
            break;
        case EM_VIDEOCORE:
            printf("Alphamosaic VideoCore");
            break;
        case EM_TMM_GPP:
            printf("Thompson Multimedia General Purpose Proc");
            break;
        case EM_NS32K:
            printf("National Semi. 32000");
            break;
        case EM_TPC:
            printf("Tenor Network TPC");
            break;
        case EM_SNP1K:
            printf("Trebia SNP 1000");
            break;
        case EM_ST200:
            printf("STMicroelectronics ST200");
            break;
        case EM_IP2K:
            printf("Ubicom IP2xxx");
            break;
        case EM_MAX:
            printf("MAX processor");
            break;
        case EM_CR:
            printf("National Semi. CompactRISC");
            break;
        case EM_F2MC16:
            printf("Fujitsu F2MC16");
            break;
        case EM_MSP430:
            printf("Texas Instruments msp430");
            break;
        case EM_BLACKFIN:
            printf("Analog Devices Blackfin DSP");
            break;
        case EM_SE_C33:
            printf("Seiko Epson S1C33 family");
            break;
        case EM_SEP:
            printf("Sharp embedded microprocessor");
            break;
        case EM_ARCA:
            printf("Arca RISC");
            break;
        case EM_UNICORE:
            printf("PKU-Unity & MPRC Peking Uni. mc series");
            break;
        case EM_EXCESS:
            printf("eXcess configurable cpu");
            break;
        case EM_DXP:
            printf("Icera Semi. Deep Execution Processor");
            break;
        case EM_ALTERA_NIOS2:
            printf("Altera Nios II");
            break;
        case EM_CRX:
            printf("National Semi. CompactRISC CRX");
            break;
        case EM_XGATE:
            printf("Motorola XGATE");
            break;
        case EM_C166:
            printf("Infineon C16x/XC16x");
            break;
        case EM_M16C:
            printf("Renesas M16C");
            break;
        case EM_DSPIC30F:
            printf("Microchip Technology dsPIC30F");
            break;
        case EM_CE:
            printf("Freescale Communication Engine RISC");
            break;
        case EM_M32C:
            printf("Renesas M32C");
            break;
        case EM_TSK3000:
            printf("Altium TSK3000");
            break;
        case EM_RS08:
            printf("Freescale RS08");
            break;
        case EM_SHARC:
            printf("Analog Devices SHARC family");
            break;
        case EM_ECOG2:
            printf("Cyan Technology eCOG2");
            break;
        case EM_SCORE7:
            printf("Sunplus S+core7 RISC");
            break;
        case EM_DSP24:
            printf("New Japan Radio (NJR) 24-bit DSP");
            break;
        case EM_VIDEOCORE3:
            printf("Broadcom VideoCore III");
            break;
        case EM_LATTICEMICO32:
            printf("RISC for Lattice FPGA");
            break;
        case EM_SE_C17:
            printf("Seiko Epson C17");
            break;
        case EM_TI_C6000:
            printf("Texas Instruments TMS320C6000 DSP");
            break;
        case EM_TI_C2000:
            printf("Texas Instruments TMS320C2000 DSP");
            break;
        case EM_TI_C5500:
            printf("Texas Instruments TMS320C55x DSP");
            break;
        case EM_TI_ARP32:
            printf("Texas Instruments App. Specific RISC");
            break;
        case EM_TI_PRU:
            printf("Texas Instruments Prog. Realtime Unit");
            break;
        case EM_MMDSP_PLUS:
            printf("STMicroelectronics 64bit VLIW DSP");
            break;
        case EM_CYPRESS_M8C:
            printf("Cypress M8C");
            break;
        case EM_R32C:
            printf("Renesas R32C");
            break;
        case EM_TRIMEDIA:
            printf("NXP Semi. TriMedia");
            break;
        case EM_QDSP6:
            printf("QUALCOMM DSP6");
            break;
        case EM_8051:
            printf("Intel 8051 and variants");
            break;
        case EM_STXP7X:
            printf("STMicroelectronics STxP7x");
            break;
        case EM_NDS32:
            printf("Andes Tech. compact code emb. RISC");
            break;
        case EM_ECOG1X:
            printf("Cyan Technology eCOG1X");
            break;
        case EM_MAXQ30:
            printf("Dallas Semi. MAXQ30 mc");
            break;
        case EM_XIMO16:
            printf("New Japan Radio (NJR) 16-bit DSP");
            break;
        case EM_MANIK:
            printf("M2000 Reconfigurable RISC");
            break;
        case EM_CRAYNV2:
            printf("Cray NV2 vector architecture");
            break;
        case EM_RX:
            printf("Renesas RX");
            break;
        case EM_METAG:
            printf("Imagination Tech. META");
            break;
        case EM_MCST_ELBRUS:
            printf("MCST Elbrus");
            break;
        case EM_ECOG16:
            printf("Cyan Technology eCOG16");
            break;
        case EM_CR16:
            printf("National Semi. CompactRISC CR16");
            break;
        case EM_ETPU:
            printf("Freescale Extended Time Processing Unit");
            break;
        case EM_SLE9X:
            printf("Infineon Tech. SLE9X");
            break;
        case EM_L10M:
            printf("Intel L10M");
            break;
        case EM_K10M:
            printf("Intel K10M");
            break;
        case EM_AARCH64:
            printf("ARM AARCH64");
            break;
        case EM_AVR32:
            printf("Amtel 32-bit microprocessor");
            break;
        case EM_STM8:
            printf("STMicroelectronics STM8");
            break;
        case EM_TILE64:
            printf("Tileta TILE64");
            break;
        case EM_TILEPRO:
            printf("Tilera TILEPro");
            break;
        case EM_MICROBLAZE:
            printf("Xilinx MicroBlaze");
            break;
        case EM_CUDA:
            printf("NVIDIA CUDA");
            break;
        case EM_TILEGX:
            printf("Tilera TILE-Gx");
            break;
        case EM_CLOUDSHIELD:
            printf("CloudShield");
            break;
        case EM_COREA_1ST:
            printf("KIPO-KAIST Core-A 1st gen");
            break;
        case EM_COREA_2ND:
            printf("KIPO-KAIST Core-A 2nd gen");
            break;
        case EM_ARC_COMPACT2:
            printf("Synopsys ARCompact V2");
            break;
        case EM_OPEN8:
            printf("Open8 RISC");
            break;
        case EM_RL78:
            printf("Renesas RL78");
            break;
        case EM_VIDEOCORE5:
            printf("Broadcom VideoCore V");
            break;
        case EM_78KOR:
            printf("Renesas 78KOR");
            break;
        case EM_56800EX:
            printf("Freescale 56800EX DSC");
            break;
        case EM_BA1:
            printf("Beyond BA1");
            break;
        case EM_BA2:
            printf("Beyond BA2");
            break;
        case EM_XCORE:
            printf("XMOS xCORE");
            break;
        case EM_MCHP_PIC:
            printf("Microchip 8-bit PIC(r)");
            break;
        case EM_KM32:
            printf("KM211 KM32");
            break;
        case EM_KMX32:
            printf("KM211 KMX32");
            break;
        case EM_EMX16:
            printf("KM211 KMX16");
            break;
        case EM_EMX8:
            printf("KM211 KMX8");
            break;
        case EM_KVARC:
            printf("KM211 KVARC");
            break;
        case EM_CDP:
            printf("Paneve CDP");
            break;
        case EM_COGE:
            printf("Cognitive Smart Memory Processor");
            break;
        case EM_COOL:
            printf("Bluechip CoolEngine");
            break;
        case EM_NORC:
            printf("Nanoradio Optimized RISC");
            break;
        case EM_CSR_KALIMBA:
            printf("CSR Kalimba");
            break;
        case EM_Z80:
            printf("Zilog Z80");
            break;
        case EM_VISIUM:
            printf("Controls and Data Services VISIUMcore");
            break;
        case EM_FT32:
            printf("FTDI Chip FT32");
            break;
        case EM_MOXIE:
            printf("Moxie processor");
            break;
        case EM_AMDGPU:
            printf("AMD GPU");
            break;
        case EM_RISCV:
            printf("RISC-V");
            break;
        case EM_BPF:
            printf("Linux BPF -- in-kernel virtual machine");
            break;
        default:
            printf("val 0X%x", elf_Head->e_machine);
    }
    printf("\n");
}

void printE_version(Elf64_Ehdr *elf_Head) {
    printf("E_version 0x%x", elf_Head->e_version);
    printf("\n");
}

//程序入口
void printE_entry(Elf64_Ehdr *elf_Head) {
    printf("E_entry 0x%x", elf_Head->e_entry);
    printf("\n");
}

//程序头表（program header table）在文件中的偏移量(以字节计数)
void printE_phoff(Elf64_Ehdr *elf_Head) {
    printf("E_phoff 0x%x", elf_Head->e_phoff);
    printf("\n");
}

// section 头表（section header table）在文件中的偏移量(以字节计数)
void printE_shoff(Elf64_Ehdr *elf_Head) {
    printf("E_shoff 0x%x", elf_Head->e_shoff);
    printf("\n");
}

//该成员保存着相关文件的特定处理器标志
void printE_flags(Elf64_Ehdr *elf_Head) {
    printf("E_flags 0x%x", elf_Head->e_flags);
    printf("\n");
}

void printE_ehsize(Elf64_Ehdr *elf_Head) {
    printf("E_ehsize 0x%x", elf_Head->e_ehsize);
    printf("\n");
}

//该成员保存着在文件的程序头表（program header table）中一个入口的大小(以字节计数)
void printE_phentsize(Elf64_Ehdr *elf_Head) {
    printf("E_phentsize 0x%x", elf_Head->e_phentsize);
    printf("\n");
}

//该成员保存着在程序头表中入口的个数
void printE_phnum(Elf64_Ehdr *elf_Head) {
    printf("E_phnum 0x%x", elf_Head->e_phnum);
    printf("\n");
}

// section 头的大小(以字节计数)
void printE_shentsize(Elf64_Ehdr *elf_Head) {
    printf("E_shentsize 0x%x", elf_Head->e_shentsize);
    printf("\n");
}

//  section header table 中的入口数目
void printE_shnum(Elf64_Ehdr *elf_Head) {
    printf("E_shnum 0x%x", elf_Head->e_shnum);
    printf("\n");
}

//  该成员保存着跟 section 名字字符表相关入口的 section 头表(section headertable)索引
void printE_shstrndx(Elf64_Ehdr *elf_Head) {
    printf("E_shstrndx 0x%x", elf_Head->e_shstrndx);
    printf("\n");
}

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
    char name[24];
    memset(name, '\0', 24);
    name[0] = strtab[elf64Shdr.sh_name];
    int i = 1;
    while (strtab[elf64Shdr.sh_name + i]  != 0) {
        name[i] = strtab[elf64Shdr.sh_name + i];
        i++;
    }
    printf("%-24s", name);
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

void printfElf32_PhdrMessage(FILE *elf, int offset, int e_phnum) {
    // int fseek(FILE *stream, long int offset, int whence) 设置流 stream 的文件位置为给定的偏移 offset，参数 offset 意味着从给定的 whence 位置查找的字节数。
    // fseek(elf, 0, SEEK_SET);
    // 将文件位置标识移动到程序头部位置
    fseek(elf, offset, SEEK_SET);
    // long int ftell(FILE *stream) 返回给定流 stream 的当前文件位置
    printf("Program header from %ld bytes\n", ftell(elf));
    printf("The Program Header Message:\n");
    Elf32_Phdr *phdr = malloc(e_phnum * sizeof(Elf32_Phdr));
    if (e_phnum == fread(phdr, sizeof(Elf32_Phdr), e_phnum, elf)) {
        Elf32_Phdr *p = phdr;
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

int main() {
    char *path = "C:/Users/12/Desktop/program/abc";

    FILE *fastfp = fopen(path, "r");
    if (fastfp == NULL) {
        printf("打开文件失败");
        return 0;
    }
    int buf_size = sizeof(Elf64_Ehdr);
    //elf头部数据结构体
    Elf64_Ehdr *elf_Head = malloc(buf_size);
    fread(elf_Head, buf_size, 1, fastfp);
    printf("=====ELF Head=====\n");
    printElfMagicNumber(elf_Head);
    printEI_CLASS(elf_Head);
    printEI_DATA(elf_Head);
    printEI_VERSION(elf_Head);
    printEI_OSABI(elf_Head);
    printEI_ABIVERSION(elf_Head);
    printEI_PAD(elf_Head);
    printE_type(elf_Head);
    printE_machine(elf_Head);
    printE_version(elf_Head);
    printE_entry(elf_Head);
    printE_phoff(elf_Head);
    printE_shoff(elf_Head);
    printE_flags(elf_Head);
    printE_ehsize(elf_Head);
    printE_phentsize(elf_Head);
    printE_phnum(elf_Head);
    printE_shentsize(elf_Head);
    printE_shnum(elf_Head);
    printE_shstrndx(elf_Head);

    printf("======Elf64_Shdr size %d======\n", elf_Head->e_shnum);
    //节区结构体数组
    Elf64_Shdr elf_Shdr[elf_Head->e_shnum];
    //读取节区
    fseek(fastfp, elf_Head->e_shoff, SEEK_SET);
    fread(elf_Shdr, elf_Head->e_shentsize, elf_Head->e_shnum, fastfp);
    Elf64_Shdr str_shdr = elf_Shdr[elf_Head->e_shstrndx];
    char strtab[str_shdr.sh_size];
    //读取字符表
    fseek(fastfp, str_shdr.sh_offset, SEEK_SET);
    fread(strtab, str_shdr.sh_size, 1, fastfp);
    printf("[Nr]\tName\t\t\tType\t\tAddr\t    Offset\tSize\tES\tFlg\tLk\tInf\tAl\n");
    for (int i = 0; i < elf_Head->e_shnum; i++) {
        printElf64_Shdr(i, elf_Shdr[i], strtab);
    }
    printf("======Program header table Size %d======\n", elf_Head->e_phnum);
    printfElf32_PhdrMessage(fastfp, elf_Head->e_phoff, elf_Head->e_phnum);
    free(elf_Head);
    return 0;
}