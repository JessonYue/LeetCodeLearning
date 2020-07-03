//
// Created by Administrator on 2020/7/1 0001.
//

#ifndef BASEDATASTRUCTURE_ELFPARSE_H
#define BASEDATASTRUCTURE_ELFPARSE_H

#include <cstdint>
#include <cstdio>

#define EI_NIDENT (16)

typedef uint16_t Elf32_Half;


typedef uint32_t Elf32_Word;


typedef uint32_t Elf32_Addr;

typedef uint32_t Elf32_Off;

typedef struct
{
    unsigned char	e_ident[EI_NIDENT];
    Elf32_Half	e_type;
    Elf32_Half	e_machine;
    Elf32_Word	e_version;
    Elf32_Addr	e_entry;
    Elf32_Off	e_phoff;
    Elf32_Off	e_shoff;
    Elf32_Word	e_flags;
    Elf32_Half	e_ehsize;
    Elf32_Half	e_phentsize;
    Elf32_Half	e_phnum;
    Elf32_Half	e_shentsize;
    Elf32_Half	e_shnum;
    Elf32_Half	e_shstrndx;
} Elf32_Ehdr;


typedef struct
{
    Elf32_Word	sh_name;		/* Section name (string tbl index) */
    Elf32_Word	sh_type;		/* Section type */
    Elf32_Word	sh_flags;		/* Section flags */
    Elf32_Addr	sh_addr;		/* Section virtual addr at execution */
    Elf32_Off	sh_offset;		/* Section file offset */
    Elf32_Word	sh_size;		/* Section size in bytes */
    Elf32_Word	sh_link;		/* Link to another section */
    Elf32_Word	sh_info;		/* Additional section information */
    Elf32_Word	sh_addralign;		/* Section alignment */
    Elf32_Word	sh_entsize;		/* Entry size if section holds table */
} Elf32_Shdr;
void file_header(FILE * fp);
Elf32_Shdr * get_elf_shdr(FILE * fp, Elf32_Ehdr elf_head);

class ELFParse {

};


#endif //BASEDATASTRUCTURE_ELFPARSE_H
