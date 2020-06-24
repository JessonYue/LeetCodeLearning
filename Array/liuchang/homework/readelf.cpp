//
// Created by 刘畅 on 2020/6/23.
//

#include "elfread.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <elf.h>
#include <file.h>

static uint32_t SecTableStrIndx = 0;

/**elf 文件头和section表解析和检查***/
int check_elf_head(FILE *file) {
    FILE *file_elf = file;
    int i = 0;
    int MagNum = 0;
    unsigned long file_size = 0;
    int sechnum = 0;
    uint32_t symsize = 0;
    uint32_t symoff = 0;
    uint32_t nSyms = 0, kk = 0;
    struct Elf32_Ehdr *Elf_header = NULL;
    struct Elf32_Shdr *Section_header = NULL;
    struct Elf32_Sym *Symbol_tab = NULL;

    //file_elf = fopen(path,"r");

    /*文件大小*/
    fseek(file_elf, 0, SEEK_END);
    file_size = ftell(file_elf);
    fseek(file_elf, 0, SEEK_SET);
    printf("file total size is:%ld bytes\n", file_size);
    fread(Elf_header, sizeof(struct Elf32_Ehdr), 1, file_elf);

    printf("\nSection Name String Table index: %d\n", SecTableStrIndx);

    /**ELF header解析**/
    printf("Magic:\t");
    for (MagNum = 0; MagNum < 16; MagNum++) {
        printf("%02x ", Elf_header->e_ident[MagNum]);
    }

    /**确认是否为elf格式**/
    if ((Elf_header->e_ident[0] == '\x7f') && (Elf_header->e_ident[1] == ELFMAG1) \
 && (Elf_header->e_ident[2] == ELFMAG2) && (Elf_header->e_ident[3] == ELFMAG3)) {
        printf("\nThis is ELF file!\n");
    } else {
        printf("\n NOT ELF file!\n");
        return -1;
    }

    printf("\n");
    printf("Type:                           \t%d\n", Elf_header->e_type);
    printf("Machine:                        \t%d\n", Elf_header->e_machine);  /* Architecture */
    printf("Version:                        \t%#02x\n", Elf_header->e_version);
    printf("Entry point address:            \t%#02x\n", Elf_header->e_entry);
    printf("Start of program headers:       \t%d(bytes)\n", Elf_header->e_phoff);
    printf("Start of section headers:       \t%d(bytes)\n", Elf_header->e_shoff);
    printf("Flags:                          \t%#02x\n", Elf_header->e_flags);
    printf("Size of this header:            \t%d(bytes)\n", Elf_header->e_ehsize);
    printf("Size of program headers:        \t%d(bytes)\n", Elf_header->e_phentsize);
    printf("Number of program headers:      \t%d\n", Elf_header->e_phnum);
    printf("Size of section headers:        \t%d(bytes)\n", Elf_header->e_shentsize);
    printf("Number of section headers:      \t%d\n", Elf_header->e_shnum);
    printf("Section header string table index:\t%d\n", Elf_header->e_shstrndx);
    if (Elf_header->e_ehsize != sizeof(*Elf_header)) {
        printf("\nELF file header size is err\n!");
        return -1;
    }
    if (Elf_header->e_type != ET_REL && Elf_header->e_type != ET_EXEC) {
        printf("file type is err!__FUNCTION__ %s __LINE__ %d\n", __FUNCTION__, __LINE__);
    }

    /**section header**/
    sechnum = Elf_header->e_shnum;
    fseek(file_elf, Elf_header->e_shoff, SEEK_SET);
    printf("\n/*****section header table****/\n");
    fread(Section_header, sizeof(struct Elf32_Shdr), sechnum, file_elf);
    printf("[Nr] Name          Type          Addr         Off      Size     ES Flg  Al");

    for (i = 0; i < sechnum; i++) {
        printf("\n[%d]  %x              %2x            %08x     %06x    %06x   %02x %02x  %02x "\
, i, Section_header->sh_name, Section_header->sh_type, Section_header->sh_addr, \
               Section_header->sh_offset, Section_header->sh_size, Section_header->sh_entsize, \
               Section_header->sh_flags, Section_header->sh_addralign);

        if (Section_header->sh_type == 2)/*if symtab*/
        {
            symsize = Section_header->sh_size;
            symoff = Section_header->sh_offset;
            nSyms = symsize / (Section_header->sh_entsize);
            fseek(file_elf, symoff, SEEK_SET);
            fread(Symbol_tab, sizeof(struct Elf32_Sym), nSyms, file_elf);
        }
        Section_header++;
    }

    printf("\n\n*******symbol table******");
    printf("\nid	size        other    bind\n");

    return 0;
}



int main() {
    char *path = "G:/workspace/testA/app.out";
    FILE *file_elf = NULL;
    file_elf = fopen(path, "rb");
    check_elf_head(file_elf);
}

