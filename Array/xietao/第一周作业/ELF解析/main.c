#include <stdio.h>
#include <cxxabi.h>
#include <stdlib.h>
#include <string.h>
#define EI_NIDENT (16)
typedef u_int64_t Elf64_Addr;
typedef u_int16_t Elf64_Half;
typedef int16_t Elf64_SHalf;
typedef u_int64_t Elf64_Off;
typedef int32_t Elf64_Sword;
typedef u_int32_t Elf64_Word;
typedef u_int64_t Elf64_Xword;
typedef int64_t Elf64_Sxword;
typedef uint16_t Elf64_Section;
typedef struct elf64_hdr {
    unsigned char e_ident[16];        /* ELF "magic number" */
    Elf64_Half e_type;
    Elf64_Half e_machine;
    Elf64_Word e_version;
    Elf64_Addr e_entry;                /* Entry point virtual address */
    Elf64_Off e_phoff;                /* Program header table file offset */
    Elf64_Off e_shoff;                /* Section header table file offset */
    Elf64_Word e_flags;
    Elf64_Half e_ehsize;
    Elf64_Half e_phentsize;
    Elf64_Half e_phnum;
    Elf64_Half e_shentsize;
    Elf64_Half e_shnum;
    Elf64_Half e_shstrndx;
} Elf64_Ehdr;

typedef struct elf64_shdr {
    Elf64_Word sh_name;                /* Section name, index in string tbl */
    Elf64_Word sh_type;                /* Type of section */
    Elf64_Xword sh_flags;                /* Miscellaneous section attributes */
    Elf64_Addr sh_addr;                /* Section virtual addr at execution */
    Elf64_Off sh_offset;                /* Section file offset */
    Elf64_Xword sh_size;                /* Size of section in bytes */
    Elf64_Word sh_link;                /* Index of another section */
    Elf64_Word sh_info;                /* Additional section information */
    Elf64_Xword sh_addralign;        /* Section alignment */
    Elf64_Xword sh_entsize;        /* Entry size if section holds table */
} Elf64_Shdr;


typedef struct {
    Elf64_Word st_name;        /* Symbol name (string tbl index) */
    unsigned char st_info;        /* Symbol type and binding */
    unsigned char st_other;        /* Symbol visibility */
    Elf64_Section st_shndx;        /* Section index */
    Elf64_Addr st_value;        /* Symbol value */
    Elf64_Xword st_size;        /* Symbol size */
} Elf64_Sym;
int getNumber(int a){
    int number = 0;
    while(a != 0){
        a = a/10;
        number++;
    }
    return number;
}
int main() {
    FILE *fp = NULL;
    int size = sizeof(Elf64_Ehdr);
    Elf64_Ehdr *hr=(Elf64_Ehdr*)malloc(sizeof(Elf64_Ehdr));
    fp = fopen("../text/libnative-lib.so", "r");
    if (fp){
        rewind(fp);
        fread(hr,size,1,fp);

//        for (int i = 0; i < 16; ++i) {
//            printf("%02x", hr->e_ident[i]);
//        }
//        printf("\n");
//        printf("Type:                           \t%d\n", hr->e_type);//整形输出
//        printf("Machine:                        \t%d\n", hr->e_machine);  /* Architecture */
//        printf("Version:                        \t%#02x\n", hr->e_version);
//        printf("Entry point address:            \t%#02x\n", hr->e_entry);
//        printf("Start of program headers:       \t%d(bytes)\n", hr->e_phoff);
//        printf("Start of section headers:       \t%d(bytes)\n", hr->e_shoff);
//        printf("Flags:                          \t%#02x\n", hr->e_flags);
//        printf("Size of this header:            \t%d(bytes)\n", hr->e_ehsize);
//        printf("Size of program headers:        \t%d(bytes)\n", hr->e_phentsize);
//        printf("Number of program headers:      \t%d\n", hr->e_phnum);
//        printf("Size of section headers:        \t%d(bytes)\n", hr->e_shentsize);
//        printf("Number of section headers:      \t%d\n", hr->e_shnum);//段表描述符数量
//        printf("Section header string table index:\t%d\n", hr->e_shstrndx);
    }
    fseek(fp,hr->e_shoff,SEEK_SET);
    int sectionNum = hr->e_shnum;//段表描述符数量
    Elf64_Shdr shdr[sectionNum];
    for (int i =0;i<sectionNum;++i){
        fread(shdr+i,sizeof(Elf64_Shdr),1,fp);
    }
    Elf64_Shdr shStringdr = shdr[hr->e_shstrndx];//字符串表
    int stringSize = shStringdr.sh_size;//字符串表的长度

    char shStringtab[stringSize];//用来存储字符串内容的字符数组
    fseek(fp, shStringdr.sh_offset, SEEK_SET);
    fread(shStringtab, stringSize, 1, fp);
//    for (int i = 0; i < stringSize; ++i) {
//            printf("%c", shStringtab[i]);
//    }
    printf("[Nr] Name             Type          Addr         Off      Size     ES Flg  Al");
    for (int j = 0; j < sectionNum; ++j) {

    printf("\n[%d]  %s              %2x            %08x     %06x    %06x   %02x %02x  %02x "\
               , j,
           shStringtab + shdr[j].sh_name,
           shdr[j].sh_type,
           shdr[j].sh_addr,\
               shdr[j].sh_offset,
           shdr[j].sh_size,
           shdr[j].sh_entsize,\
               shdr[j].sh_flags,
           shdr[j].sh_addralign);
    }


    //下面是解析.symtab符号表
    int syNumber = 0;//符号表中的个数
    Elf64_Shdr *syDuan;
    for (int i = 0; i < sectionNum; i++){
        if(strcmp((const char*)(shStringtab + shdr[i].sh_name), ".symtab") == 0){
            syDuan = (Elf64_Shdr *)&shdr[i];
            syNumber = (shdr[i].sh_size / shdr[i].sh_entsize);
            break;
        }
    }
    Elf64_Shdr *dynsym;
    for (int i = 0; i < sectionNum; i++){
        if(strcmp((const char*)(shStringtab + shdr[i].sh_name), ".strtab") == 0){
            dynsym = (Elf64_Shdr *)&shdr[i];
            break;
        }
    }
    char dynsymTab[stringSize];//用来存储dynsym字符串表的字符数组
    int dynsymTabSize = dynsym->sh_size;//dynsym字符串表的长度
    fseek(fp, dynsym->sh_offset, SEEK_SET);
    fread(dynsymTab, dynsymTabSize, 1, fp);
    for (int i = 0; i < dynsymTabSize; ++i) {
            printf("%c", dynsymTab[i]);
    }


    Elf64_Sym symS[syNumber];
    fseek(fp,syDuan->sh_offset,SEEK_SET);
    for (int i =0;i<syNumber;++i){
        fread(symS+i,sizeof(Elf64_Sym),1,fp);
    }

    printf("\n");
    printf("[Nr] Name                     shndx      value     sizel");

    for (int j = 0; j < syNumber; ++j) {

        printf("\n[%d]  %s                  %06x    %06x   %02x "\
               , j,
               dynsymTab + symS[j].st_name,
//               symS[j].st_info,
//               symS[j].st_other,\
               symS[j].st_shndx,
               symS[j].st_value,\
               symS[j].st_size);
    }
    free(hr);
    fclose(fp);
    return 0;
}