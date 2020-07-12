//
// Created by Administrator on 2020/7/1 0001.
//

#include <cstdlib>
#include <cstring>
#include "ELFParse.h"


int main() {
    FILE *fp = NULL;
    fp = fopen("E:\\drem\\LeetCodeLearning\\Array\\luobiao\\BaseDataStructure\\libnative-lib.so","rw+");

    if (fp == NULL) {
        printf("open file fail.");
        return 0;
    }

    file_header(fp);

    Elf32_Ehdr* elf_head;
    printf("----get_elf_shdr---start-------\n");
    Elf32_Shdr* elf32_shdr = get_elf_shdr(fp, *elf_head);
    printf("get_elf_shdr ------end");
    fclose(fp);

    return 0;
}

void file_header(FILE *fp) {

}

Elf32_Shdr *get_elf_shdr(FILE *fp, Elf32_Ehdr elf_head) {
    printf("-------start-------\n");
    Elf32_Shdr* elf32_shdr = static_cast<Elf32_Shdr *>(malloc(sizeof(Elf32_Shdr) * elf_head.e_shnum));
    printf("-------start-------\n");
    if (elf32_shdr == NULL) {
        printf("shdr malloc failed\n");
    }
    memset(elf32_shdr,0,sizeof(Elf32_Shdr));

    int result = 0;
    result = fseek(fp, elf_head.e_shoff, SEEK_SET);
    if (result != 0) {
        printf("shdr fseek ERROR\n");
        free(elf32_shdr);
        return NULL;
    }

    result = fread(elf32_shdr, sizeof(Elf32_Shdr), elf_head.e_shnum, fp);
    if (result == 0) {
        printf("READ ERROR\n");
        free(elf32_shdr);
        return NULL;
    }

    printf("-------end-------\n");
    return elf32_shdr;
}







