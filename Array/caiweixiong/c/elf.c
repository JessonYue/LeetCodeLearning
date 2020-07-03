//
// Created by Vashon on 2020/6/22.
//

#include "elf.h"
#include "elf_utils.h"
#include <stdlib.h>
#include <string.h>

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
    unsigned char buff[16];     // 临时缓冲区，用于检测文件类型与文件字长
    // void rewind(FILE *stream) 设置文件位置为给定流 stream 的文件的开头
    rewind(file);
    // 从给定流 stream 读取数据到 ptr 所指向的数组中，成功，则返回读取的数量：nmemb
    // size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)
    if (1 == fread(buff, 16 * sizeof(char), 1, file)) {
        if (ELFMAG0 == buff[EI_MAG0]
            && ELFMAG1 == buff[EI_MAG1]
            && ELFMAG2 == buff[EI_MAG2]
            && ELFMAG3 == buff[EI_MAG3]) {  // elf 文件类型
            switch (buff[EI_CLASS]) {
                case ELFCLASSNONE:  // 未知字长，不做解析
                    printf("\tClass:                            \tInvalid class\n");
                    break;
                case ELFCLASS32:
                    printfElf32_Message(file);
                    break;
                case ELFCLASS64:    // 暂时不支持64位字长解析，待完善
                    printf("\tClass:                            \t64-bit objects\n");
                    break;
                default:            // 未知字长，不做解析
                    printf("\tClass:                            \tELF class num %x\n", buff[EI_CLASS]);
            }
        } else {
            printf("This is not elf file\n");
        }
    } else {
        printf("Read file fail\n");
    }
}

void printfElf32_Message(FILE *elf) {
    rewind(elf);            // 读取之前记得将文件位置标识重置
    Elf32_Ehdr elf32Ehdr;   // elf 头部表
    if (1 == fread(&elf32Ehdr, sizeof(Elf32_Ehdr), 1, elf)) {
        printfElf32_EhdrMessage(elf32Ehdr);
        if (0 == elf32Ehdr.e_phnum)
            printf("\nElf file program header is null\n");
        else {
            printf("\n--------------------------------------\n");
            printfElf32_PhdrMessage(elf, elf32Ehdr.e_phoff, elf32Ehdr.e_phnum);
        }
        if (0 == elf32Ehdr.e_shnum)
            printf("\nElf file section header is null\n");
        else {
            printf("\n--------------------------------------\n");
            printfElf32_ShdrMessage(elf, elf32Ehdr.e_shoff, elf32Ehdr.e_shnum, elf32Ehdr.e_shstrndx);
        }
    } else {
        printf("Read elf header fail\n");
    }
}

void printfElf32_EhdrMessage(Elf32_Ehdr ehdr) {
    printf("ELF Header:\n");
    printf("\tMagic: ");
    unsigned char *e_ident = ehdr.e_ident;
    for (int i = 0; i < EI_NIDENT; ++i) {       // i == 4 : 字长，i == 5 : 字节序，i == 6 : elf版本
        printf("%02x ", e_ident[i]);    // Class:ELF32，Data:little/big endian，Version:1 (current)，OS/ABI，ABI Version
    }
    printf("\n");
    // Class
    switch (e_ident[EI_CLASS]) {
        case ELFCLASSNONE:
            printf("\tClass:                            \tInvalid class\n");
            break;
        case ELFCLASS32:
            printf("\tClass:                            \t32-bit objects\n");
            break;
        case ELFCLASS64:
            printf("\tClass:                            \t64-bit objects\n");
            break;
        default:
            printf("\tClass:                            \tELF class num %x\n", e_ident[EI_CLASS]);
    }
    // Data
    switch (e_ident[EI_DATA]) {
        case ELFDATANONE:
            printf("\tData:                            \tInvalid data encoding\n");
            break;
        case ELFDATA2LSB:
            printf("\tData:                            \t2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("\tData:                            \t2's complement, big endian\n");
            break;
        default:
            printf("\tData:                            \tELF data num %x\n", e_ident[EI_DATA]);
    }
    printf("\tVersion:                          \t%x (current)\n", e_ident[EI_VERSION]);
    // OS/ABI
    switch (e_ident[EI_OSABI]) {
        case ELFOSABI_NONE:
            printf("\tOS/ABI:                            \tUNIX System V\n");
            break;
        case ELFOSABI_HPUX:
            printf("\tOS/ABI:                            \tHP-UX\n");
            break;
        case ELFOSABI_NETBSD:
            printf("\tOS/ABI:                            \tNetBSD\n");
            break;
        case ELFOSABI_GNU:
            printf("\tOS/ABI:                            \tObject uses GNU ELF extensions\n");
            break;
        case ELFOSABI_SOLARIS:
            printf("\tOS/ABI:                            \tSun Solaris\n");
            break;
        case ELFOSABI_AIX:
            printf("\tOS/ABI:                            \tIBM AIX\n");
            break;
        case ELFOSABI_IRIX:
            printf("\tOS/ABI:                            \tSGI Irix\n");
            break;
        case ELFOSABI_FREEBSD:
            printf("\tOS/ABI:                            \tFreeBSD\n");
            break;
        case ELFOSABI_TRU64:
            printf("\tOS/ABI:                            \tCompaq TRU64 UNIX\n");
            break;
        case ELFOSABI_MODESTO:
            printf("\tOS/ABI:                            \tNovell Modesto\n");
            break;
        case ELFOSABI_OPENBSD:
            printf("\tOS/ABI:                            \tOpenBSD\n");
            break;
        case ELFOSABI_ARM_AEABI:
            printf("\tOS/ABI:                            \tARM EABI\n");
            break;
        case ELFOSABI_ARM:
            printf("\tOS/ABI:                            \tARM\n");
            break;
        case ELFOSABI_STANDALONE:
            printf("\tOS/ABI:                            \tStandalone (embedded) application\n");
            break;
        default:
            printf("\tOS/ABI:                            \tELF OS/ABI num %x\n", e_ident[EI_OSABI]);
    }
    printf("\tABI Version:                      \t%x\n", e_ident[EI_ABIVERSION]);
    // Type
    switch (ehdr.e_type) {
        case ET_NONE:
            printf("\tType:                             \tNo file type\n");
            break;
        case ET_REL:
            printf("\tType:                             \tRelocatable file\n");
            break;
        case ET_EXEC:
            printf("\tType:                             \tExecutable file\n");
            break;
        case ET_DYN:
            printf("\tType:                             \tShared object file\n");
            break;
        case ET_CORE:
            printf("\tType:                             \tCore file\n");
            break;
        case ET_NUM:
            printf("\tType:                             \tNumber of defined types\n");
            break;
        case ET_LOOS:
            printf("\tType:                             \tOS-specific range start\n");
            break;
        case ET_HIOS:
            printf("\tType:                             \tOS-specific range end\n");
            break;
        case ET_LOPROC:
            printf("\tType:                             \tProcessor-specific range start\n");
            break;
        case ET_HIPROC:
            printf("\tType:                             \tProcessor-specific range end\n");
            break;
        default:
            printf("\tType:                             \tELF type num %x\n", ehdr.e_type);
    }
    // Machine
    switch (ehdr.e_machine) {
        case EM_NONE:
            printf("\tMachine:                          \tNo machine\n");
            break;
        case EM_M32:
            printf("\tMachine:                          \tAT&T WE 32100\n");
            break;
        case EM_SPARC:
            printf("\tMachine:                          \tSUN SPARC\n");
            break;
        case EM_386:
            printf("\tMachine:                          \tIntel 80386\n");
            break;
        case EM_68K:
            printf("\tMachine:                          \tMotorola m68k family\n");
            break;
        case EM_88K:
            printf("\tMachine:                          \tMotorola m88k family\n");
            break;
        case EM_IAMCU:
            printf("\tMachine:                          \tIntel MCU\n");
            break;
        case EM_860:
            printf("\tMachine:                          \tIntel 80860\n");
            break;
        case EM_MIPS:
            printf("\tMachine:                          \tMIPS R3000 big-endian\n");
            break;
        case EM_S370:
            printf("\tMachine:                          \tIBM System/370\n");
            break;
        case EM_MIPS_RS3_LE:
            printf("\tMachine:                          \tMIPS R3000 little-endian\n");
            break;
        case EM_PARISC:
            printf("\tMachine:                          \tHPPA\n");
            break;
        case EM_VPP500:
            printf("\tMachine:                          \tFujitsu VPP500\n");
            break;
        case EM_SPARC32PLUS:
            printf("\tMachine:                          \tSun's \"v8plus\n");
            break;
        case EM_960:
            printf("\tMachine:                          \tIntel 80960\n");
            break;
        case EM_PPC:
            printf("\tMachine:                          \tPowerPC\n");
            break;
        case EM_PPC64:
            printf("\tMachine:                          \tPowerPC 64-bit\n");
            break;
        case EM_S390:
            printf("\tMachine:                          \tIBM S390\n");
            break;
        case EM_SPU:
            printf("\tMachine:                          \tIBM SPU/SPC\n");
            break;
        case EM_V800:
            printf("\tMachine:                          \tNEC V800 series\n");
            break;
        case EM_FR20:
            printf("\tMachine:                          \tFujitsu FR20\n");
            break;
        case EM_RH32:
            printf("\tMachine:                          \tTRW RH-32\n");
            break;
        case EM_RCE:
            printf("\tMachine:                          \tMotorola RCE\n");
            break;
        case EM_ARM:
            printf("\tMachine:                          \tARM\n");
            break;
        case EM_FAKE_ALPHA:
            printf("\tMachine:                          \tDigital Alpha\n");
            break;
        case EM_SH:
            printf("\tMachine:                          \tHitachi SH\n");
            break;
        case EM_SPARCV9:
            printf("\tMachine:                          \tSPARC v9 64-bit\n");
            break;
        case EM_TRICORE:
            printf("\tMachine:                          \tSiemens Tricore\n");
            break;
        case EM_ARC:
            printf("\tMachine:                          \tArgonaut RISC Core\n");
            break;
        case EM_H8_300:
            printf("\tMachine:                          \tHitachi H8/300\n");
            break;
        case EM_H8_300H:
            printf("\tMachine:                          \tHitachi H8/300H\n");
            break;
        case EM_H8S:
            printf("\tMachine:                          \tHitachi H8S\n");
            break;
        case EM_H8_500:
            printf("\tMachine:                          \tHitachi H8/500\n");
            break;
        case EM_IA_64:
            printf("\tMachine:                          \tIntel Merced\n");
            break;
        case EM_MIPS_X:
            printf("\tMachine:                          \tStanford MIPS-X\n");
            break;
        case EM_COLDFIRE:
            printf("\tMachine:                          \tMotorola Coldfire\n");
            break;
        case EM_68HC12:
            printf("\tMachine:                          \tMotorola M68HC12\n");
            break;
        case EM_MMA:
            printf("\tMachine:                          \tFujitsu MMA Multimedia Accelerator\n");
            break;
        case EM_PCP:
            printf("\tMachine:                          \tSiemens PCP\n");
            break;
        case EM_NCPU:
            printf("\tMachine:                          \tSony nCPU embeeded RISC\n");
            break;
        case EM_NDR1:
            printf("\tMachine:                          \tDenso NDR1 microprocessor\n");
            break;
        case EM_STARCORE:
            printf("\tMachine:                          \tMotorola Start*Core processor\n");
            break;
        case EM_ME16:
            printf("\tMachine:                          \tToyota ME16 processor\n");
            break;
        case EM_ST100:
            printf("\tMachine:                          \tSTMicroelectronic ST100 processor\n");
            break;
        case EM_TINYJ:
            printf("\tMachine:                          \tAdvanced Logic Corp. Tinyj emb.fam\n");
            break;
        case EM_X86_64:
            printf("\tMachine:                          \tAMD x86-64 architecture\n");
            break;
        case EM_PDSP:
            printf("\tMachine:                          \tSony DSP Processor\n");
            break;
        case EM_PDP10:
            printf("\tMachine:                          \tDigital PDP-10\n");
            break;
        case EM_PDP11:
            printf("\tMachine:                          \tDigital PDP-11\n");
            break;
        case EM_FX66:
            printf("\tMachine:                          \tSiemens FX66 microcontroller\n");
            break;
        case EM_ST9PLUS:
            printf("\tMachine:                          \tSTMicroelectronics ST9+ 8/16 mc\n");
            break;
        case EM_ST7:
            printf("\tMachine:                          \tSTmicroelectronics ST7 8 bit mc\n");
            break;
        case EM_68HC16:
            printf("\tMachine:                          \tMotorola MC68HC16 microcontroller\n");
            break;
        case EM_68HC11:
            printf("\tMachine:                          \tMotorola MC68HC11 microcontroller\n");
            break;
        case EM_68HC08:
            printf("\tMachine:                          \tMotorola MC68HC08 microcontroller\n");
            break;
        case EM_68HC05:
            printf("\tMachine:                          \tMotorola MC68HC05 microcontroller\n");
            break;
        case EM_SVX:
            printf("\tMachine:                          \tSilicon Graphics SVx\n");
            break;
        case EM_ST19:
            printf("\tMachine:                          \tSTMicroelectronics ST19 8 bit mc\n");
            break;
        case EM_VAX:
            printf("\tMachine:                          \tDigital VAX\n");
            break;
        case EM_CRIS:
            printf("\tMachine:                          \tAxis Communications 32-bit emb.proc\n");
            break;
        case EM_JAVELIN:
            printf("\tMachine:                          \tInfineon Technologies 32-bit emb.proc\n");
            break;
        case EM_FIREPATH:
            printf("\tMachine:                          \tElement 14 64-bit DSP Processor\n");
            break;
        case EM_ZSP:
            printf("\tMachine:                          \tLSI Logic 16-bit DSP Processor\n");
            break;
        case EM_MMIX:
            printf("\tMachine:                          \tDonald Knuth's educational 64-bit proc\n");
            break;
        case EM_HUANY:
            printf("\tMachine:                          \tHarvard University machine-independent object files\n");
            break;
        case EM_PRISM:
            printf("\tMachine:                          \tSiTera Prism\n");
            break;
        case EM_AVR:
            printf("\tMachine:                          \tAtmel AVR 8-bit microcontroller\n");
            break;
        case EM_FR30:
            printf("\tMachine:                          \tFujitsu FR30\n");
            break;
        case EM_D10V:
            printf("\tMachine:                          \tMitsubishi D10V\n");
            break;
        case EM_D30V:
            printf("\tMachine:                          \tMitsubishi D30V\n");
            break;
        case EM_V850:
            printf("\tMachine:                          \tNEC v850\n");
            break;
        case EM_M32R:
            printf("\tMachine:                          \tMitsubishi M32R\n");
            break;
        case EM_MN10300:
            printf("\tMachine:                          \tMatsushita MN10300\n");
            break;
        case EM_MN10200:
            printf("\tMachine:                          \tMatsushita MN10200\n");
            break;
        case EM_PJ:
            printf("\tMachine:                          \tpicoJava\n");
            break;
        case EM_OPENRISC:
            printf("\tMachine:                          \tOpenRISC 32-bit embedded processor\n");
            break;
        case EM_ARC_COMPACT:
            printf("\tMachine:                          \tARC International ARCompact\n");
            break;
        case EM_XTENSA:
            printf("\tMachine:                          \tTensilica Xtensa Architecture\n");
            break;
        case EM_VIDEOCORE:
            printf("\tMachine:                          \tAlphamosaic VideoCore\n");
            break;
        case EM_TMM_GPP:
            printf("\tMachine:                          \tThompson Multimedia General Purpose Proc\n");
            break;
        case EM_NS32K:
            printf("\tMachine:                          \tNational Semi. 32000\n");
            break;
        case EM_TPC:
            printf("\tMachine:                          \tTenor Network TPC\n");
            break;
        case EM_SNP1K:
            printf("\tMachine:                          \tTrebia SNP 1000\n");
            break;
        case EM_ST200:
            printf("\tMachine:                          \tSTMicroelectronics ST200\n");
            break;
        case EM_IP2K:
            printf("\tMachine:                          \tUbicom IP2xxx\n");
            break;
        case EM_MAX:
            printf("\tMachine:                          \tMAX processor\n");
            break;
        case EM_CR:
            printf("\tMachine:                          \tNational Semi. CompactRISC\n");
            break;
        case EM_F2MC16:
            printf("\tMachine:                          \tFujitsu F2MC16\n");
            break;
        case EM_MSP430:
            printf("\tMachine:                          \tTexas Instruments msp430\n");
            break;
        case EM_BLACKFIN:
            printf("\tMachine:                          \tAnalog Devices Blackfin DSP\n");
            break;
        case EM_SE_C33:
            printf("\tMachine:                          \tSeiko Epson S1C33 family\n");
            break;
        case EM_SEP:
            printf("\tMachine:                          \tSharp embedded microprocessor\n");
            break;
        case EM_ARCA:
            printf("\tMachine:                          \tArca RISC\n");
            break;
        case EM_UNICORE:
            printf("\tMachine:                          \tPKU-Unity & MPRC Peking Uni. mc series\n");
            break;
        case EM_EXCESS:
            printf("\tMachine:                          \teXcess configurable cpu\n");
            break;
        case EM_DXP:
            printf("\tMachine:                          \tIcera Semi. Deep Execution Processor\n");
            break;
        case EM_ALTERA_NIOS2:
            printf("\tMachine:                          \tAltera Nios II\n");
            break;
        case EM_CRX:
            printf("\tMachine:                          \tNational Semi. CompactRISC CRX\n");
            break;
        case EM_XGATE:
            printf("\tMachine:                          \tMotorola XGATE\n");
            break;
        case EM_C166:
            printf("\tMachine:                          \tInfineon C16x/XC16x\n");
            break;
        case EM_M16C:
            printf("\tMachine:                          \tRenesas M16C\n");
            break;
        case EM_DSPIC30F:
            printf("\tMachine:                          \tMicrochip Technology dsPIC30F\n");
            break;
        case EM_CE:
            printf("\tMachine:                          \tFreescale Communication Engine RISC\n");
            break;
        case EM_M32C:
            printf("\tMachine:                          \tRenesas M32C\n");
            break;
        case EM_TSK3000:
            printf("\tMachine:                          \tAltium TSK3000\n");
            break;
        case EM_RS08:
            printf("\tMachine:                          \tFreescale RS08\n");
            break;
        case EM_SHARC:
            printf("\tMachine:                          \tAnalog Devices SHARC family\n");
            break;
        case EM_ECOG2:
            printf("\tMachine:                          \tCyan Technology eCOG2\n");
            break;
        case EM_SCORE7:
            printf("\tMachine:                          \tSunplus S+core7 RISC\n");
            break;
        case EM_DSP24:
            printf("\tMachine:                          \tNew Japan Radio (NJR) 24-bit DSP\n");
            break;
        case EM_VIDEOCORE3:
            printf("\tMachine:                          \tBroadcom VideoCore III\n");
            break;
        case EM_LATTICEMICO32:
            printf("\tMachine:                          \tRISC for Lattice FPGA\n");
            break;
        case EM_SE_C17:
            printf("\tMachine:                          \tSeiko Epson C17\n");
            break;
        case EM_TI_C6000:
            printf("\tMachine:                          \tTexas Instruments TMS320C6000 DSP\n");
            break;
        case EM_TI_C2000:
            printf("\tMachine:                          \tTexas Instruments TMS320C2000 DSP\n");
            break;
        case EM_TI_C5500:
            printf("\tMachine:                          \tTexas Instruments TMS320C55x DSP\n");
            break;
        case EM_TI_ARP32:
            printf("\tMachine:                          \tTexas Instruments App. Specific RISC\n");
            break;
        case EM_TI_PRU:
            printf("\tMachine:                          \tTexas Instruments Prog. Realtime Unit\n");
            break;
        case EM_MMDSP_PLUS:
            printf("\tMachine:                          \tSTMicroelectronics 64bit VLIW DSP\n");
            break;
        case EM_CYPRESS_M8C:
            printf("\tMachine:                          \tCypress M8C\n");
            break;
        case EM_R32C:
            printf("\tMachine:                          \tRenesas R32C\n");
            break;
        case EM_TRIMEDIA:
            printf("\tMachine:                          \tNXP Semi. TriMedia\n");
            break;
        case EM_QDSP6:
            printf("\tMachine:                          \tQUALCOMM DSP6\n");
            break;
        case EM_8051:
            printf("\tMachine:                          \tIntel 8051 and variants\n");
            break;
        case EM_STXP7X:
            printf("\tMachine:                          \tSTMicroelectronics STxP7x\n");
            break;
        case EM_NDS32:
            printf("\tMachine:                          \tAndes Tech. compact code emb. RISC\n");
            break;
        case EM_ECOG1X:
            printf("\tMachine:                          \tCyan Technology eCOG1X\n");
            break;
        case EM_MAXQ30:
            printf("\tMachine:                          \tDallas Semi. MAXQ30 mc\n");
            break;
        case EM_XIMO16:
            printf("\tMachine:                          \tNew Japan Radio (NJR) 16-bit DSP\n");
            break;
        case EM_MANIK:
            printf("\tMachine:                          \tM2000 Reconfigurable RISC\n");
            break;
        case EM_CRAYNV2:
            printf("\tMachine:                          \tCray NV2 vector architecture\n");
            break;
        case EM_RX:
            printf("\tMachine:                          \tRenesas RX\n");
            break;
        case EM_METAG:
            printf("\tMachine:                          \tImagination Tech. META\n");
            break;
        case EM_MCST_ELBRUS:
            printf("\tMachine:                          \tMCST Elbrus\n");
            break;
        case EM_ECOG16:
            printf("\tMachine:                          \tCyan Technology eCOG16\n");
            break;
        case EM_CR16:
            printf("\tMachine:                          \tNational Semi. CompactRISC CR16\n");
            break;
        case EM_ETPU:
            printf("\tMachine:                          \tFreescale Extended Time Processing Unit\n");
            break;
        case EM_SLE9X:
            printf("\tMachine:                          \tInfineon Tech. SLE9X\n");
            break;
        case EM_L10M:
            printf("\tMachine:                          \tIntel L10M\n");
            break;
        case EM_K10M:
            printf("\tMachine:                          \tIntel K10M\n");
            break;
        case EM_AARCH64:
            printf("\tMachine:                          \tARM AARCH64\n");
            break;
        case EM_AVR32:
            printf("\tMachine:                          \tAmtel 32-bit microprocessor\n");
            break;
        case EM_STM8:
            printf("\tMachine:                          \tSTMicroelectronics STM8\n");
            break;
        case EM_TILE64:
            printf("\tMachine:                          \tTileta TILE64\n");
            break;
        case EM_TILEPRO:
            printf("\tMachine:                          \tTilera TILEPro\n");
            break;
        case EM_MICROBLAZE:
            printf("\tMachine:                          \tXilinx MicroBlaze\n");
            break;
        case EM_CUDA:
            printf("\tMachine:                          \tNVIDIA CUDA\n");
            break;
        case EM_TILEGX:
            printf("\tMachine:                          \tTilera TILE-Gx\n");
            break;
        case EM_CLOUDSHIELD:
            printf("\tMachine:                          \tCloudShield\n");
            break;
        case EM_COREA_1ST:
            printf("\tMachine:                          \tKIPO-KAIST Core-A 1st gen\n");
            break;
        case EM_COREA_2ND:
            printf("\tMachine:                          \tKIPO-KAIST Core-A 2nd gen\n");
            break;
        case EM_ARC_COMPACT2:
            printf("\tMachine:                          \tSynopsys ARCompact V2\n");
            break;
        case EM_OPEN8:
            printf("\tMachine:                          \tOpen8 RISC\n");
            break;
        case EM_RL78:
            printf("\tMachine:                          \tRenesas RL78\n");
            break;
        case EM_VIDEOCORE5:
            printf("\tMachine:                          \tBroadcom VideoCore V\n");
            break;
        case EM_78KOR:
            printf("\tMachine:                          \tRenesas 78KOR\n");
            break;
        case EM_56800EX:
            printf("\tMachine:                          \tFreescale 56800EX DSC\n");
            break;
        case EM_BA1:
            printf("\tMachine:                          \tBeyond BA1\n");
            break;
        case EM_BA2:
            printf("\tMachine:                          \tBeyond BA2\n");
            break;
        case EM_XCORE:
            printf("\tMachine:                          \tXMOS xCORE\n");
            break;
        case EM_MCHP_PIC:
            printf("\tMachine:                          \tMicrochip 8-bit PIC(r)\n");
            break;
        case EM_KM32:
            printf("\tMachine:                          \tKM211 KM32\n");
            break;
        case EM_KMX32:
            printf("\tMachine:                          \tKM211 KMX32\n");
            break;
        case EM_EMX16:
            printf("\tMachine:                          \tKM211 KMX16\n");
            break;
        case EM_EMX8:
            printf("\tMachine:                          \tKM211 KMX8\n");
            break;
        case EM_KVARC:
            printf("\tMachine:                          \tKM211 KVARC\n");
            break;
        case EM_CDP:
            printf("\tMachine:                          \tPaneve CDP\n");
            break;
        case EM_COGE:
            printf("\tMachine:                          \tCognitive Smart Memory Processor\n");
            break;
        case EM_COOL:
            printf("\tMachine:                          \tBluechip CoolEngine\n");
            break;
        case EM_NORC:
            printf("\tMachine:                          \tNanoradio Optimized RISC\n");
            break;
        case EM_CSR_KALIMBA:
            printf("\tMachine:                          \tCSR Kalimba\n");
            break;
        case EM_Z80:
            printf("\tMachine:                          \tZilog Z80\n");
            break;
        case EM_VISIUM:
            printf("\tMachine:                          \tControls and Data Services VISIUMcore\n");
            break;
        case EM_FT32:
            printf("\tMachine:                          \tFTDI Chip FT32\n");
            break;
        case EM_MOXIE:
            printf("\tMachine:                          \tMoxie processor\n");
            break;
        case EM_AMDGPU:
            printf("\tMachine:                          \tAMD GPU\n");
            break;
        case EM_RISCV:
            printf("\tMachine:                          \tRISC-V\n");
            break;
        case EM_BPF:
            printf("\tMachine:                          \tLinux BPF -- in-kernel virtual machine\n");
            break;
        default:
            printf("\tMachine:                          \tELF machine num %x\n", ehdr.e_machine);
    }
    // Version
    switch (ehdr.e_version) {
        case EV_NONE:
            printf("\tVersion:                          \tInvalid ELF version\n");
            break;
        case EV_CURRENT:
            printf("\tVersion:                          \t0x%x (Current version)\n", ehdr.e_version);
            break;
        default:
            printf("\tVersion:                          \tELF version num %x\n", ehdr.e_version);
    }
    printf("\tEntry point address:              \t0x%x\n", ehdr.e_entry);                       // 入口点的虚拟地址
    printf("\tStart of program headers:         \t%d (bytes into file)\n", ehdr.e_phoff);       // 程序头部表偏移量
    printf("\tStart of section headers:         \t%d (bytes into file)\n", ehdr.e_shoff);       // 节头部表偏移量
    printf("\tFlags:                            \t0x%x\n", ehdr.e_flags);                       // 保存与文件相关的，特定于处理器的标志
    printf("\tSize of this header:              \t%d (bytes)\n", ehdr.e_ehsize);                // ELF 头大小(字节)
    printf("\tSize of program headers:          \t%d (bytes)\n", ehdr.e_phentsize);             // 程序头部条目大小
    printf("\tNumber of program headers:        \t%d\n", ehdr.e_phnum);                         // 程序头部条目数量
    printf("\tSize of section headers:          \t%d (bytes)\n", ehdr.e_shentsize);             // 节头部条目大小
    printf("\tNumber of section headers:        \t%d\n", ehdr.e_shnum);                         // 节头部条目数量
    printf("\tSection header string table index:\t%d\n", ehdr.e_shstrndx);                      // 节头部字符串表的索引
}

void printfElf32_PhdrMessage(FILE *elf, int offset, int count) {
    // int fseek(FILE *stream, long int offset, int whence) 设置流 stream 的文件位置为给定的偏移 offset，参数 offset 意味着从给定的 whence 位置查找的字节数。
    // fseek(elf, 0, SEEK_SET);
    // 将文件位置标识移动到程序头部位置
    fseek(elf, offset, SEEK_SET);
    // long int ftell(FILE *stream) 返回给定流 stream 的当前文件位置
    printf("Program header from %ld bytes\n", ftell(elf));
    printf("The Program Header Message:\n");
    Elf32_Phdr *phdr = malloc(count * sizeof(Elf32_Phdr));
    if (count == fread(phdr, sizeof(Elf32_Phdr), count, elf)) {
        Elf32_Phdr *p = phdr;
        printf("Type\t\tOffset\t\tVirtAddr\tPhysAddr\tFileSiz\t\tMemSiz\t\tFlg\tAl\n");
        for (int i = 0; i < count; ++i, p++) {
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

void printfElf32_ShdrMessage(FILE *elf, int offset, int count, uint16_t shstrndx) {
    fseek(elf, offset, SEEK_SET);
    printf("Section header from %ld bytes\n", ftell(elf));
    printf("The Section Header Message:\n");
    Elf32_Shdr *shdr = malloc(count * sizeof(Elf32_Shdr));
    Elf32_Sym sym;  // 符号表
    if (count == fread(shdr, sizeof(Elf32_Shdr), count, elf)) {
        Elf32_Shdr shstr = shdr[shstrndx];
        Elf32_Shdr *s = shdr;
        char srcName[shstr.sh_size];
        char destName[24];
        char typeName[16];
        char flag[12];
        fseek(elf, shstr.sh_offset, SEEK_SET);      // 将文件偏移到节表字符串表的位置
        fread(srcName, shstr.sh_size, 1, elf);  // 读取劫镖字符串表

        printf("\t[Nr]\tName\t\t\tType\t\tAddr\t\tOff\tSize\tES\tFlg\tLk\tInf\tAl\n");
        for (int i = 0; i < count; ++i, s++) {
            getSectionNameByName(s->sh_name, srcName, destName);
            getSectionTypeNameByType(s->sh_type, typeName);
            getSectionFlagNameByFlags(s->sh_flags, flag);
            printf("\t[%2d]\t%-24s%-12s\t%08x\t%06x\t%06x\t%-2d\t%-s\t%-2d\t%-2d\t%-2d\n", \
               i, destName, typeName, s->sh_addr, \
               s->sh_offset, s->sh_size, s->sh_entsize, \
               flag, s->sh_link, s->sh_info, s->sh_addralign);
        }
    } else
        printf("Read program header fail\n");
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