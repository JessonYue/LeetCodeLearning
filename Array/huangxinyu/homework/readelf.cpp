#include <iostream>
#include <elf.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

const static char *ei_class[] = {"ELFCLASSNONE", "ELFCLASS32", "ELFCLASS64"};
const static char *ei_data[] = {"ELFDATANONE", "ELFDATA2LSB", "ELFDATA2MSB"};
const static char *e_version[] = {"EV_NONE", "EV_CURRENT"};

int readElfEhdr(int fd, Elf64_Ehdr *elf64Ehdr) {
    size_t readed = read(fd, elf64Ehdr, sizeof(Elf64_Ehdr));
    return readed == sizeof(Elf64_Ehdr);
}

int printElfEhdr(Elf64_Ehdr *elf64Ehdr) {
    printf("---------- Elf_Ehdr ----------\n");
    if (elf64Ehdr->e_ident[EI_MAG0] == ELFMAG0 && elf64Ehdr->e_ident[EI_MAG1] == ELFMAG1 &&
        elf64Ehdr->e_ident[EI_MAG2] == ELFMAG2 && elf64Ehdr->e_ident[EI_MAG3] == ELFMAG3
            ) {
        printf("EI_CLASS       = %s\n", ei_class[elf64Ehdr->e_ident[EI_CLASS]]);
        printf("EI_DATA        = %s\n", ei_data[elf64Ehdr->e_ident[EI_DATA]]);
        printf("EI_VERSION     = %d\n", elf64Ehdr->e_ident[EI_VERSION]);
        printf("EI_OSABI       = %d\n", elf64Ehdr->e_ident[EI_ABIVERSION]);
        printf("EI_ABIVERSION  = %d\n", elf64Ehdr->e_ident[EI_ABIVERSION]);
        printf("EI_PAD         = %d\n", elf64Ehdr->e_ident[EI_PAD]);
        printf("EI_NIDENT      = %d\n", elf64Ehdr->e_ident[EI_NIDENT]);
        printf("e_type         = %d\n", elf64Ehdr->e_type);
        printf("e_machine      = %u\n", elf64Ehdr->e_machine);
        printf("e_version      = %-s\n", e_version[elf64Ehdr->e_version]);
        printf("e_entry        = 0x%08x\n", (int) elf64Ehdr->e_entry);
        printf("e_ehsize       = 0x%x\n", elf64Ehdr->e_ehsize);
        printf("e_phoff        = 0x%x\n", (int) elf64Ehdr->e_phoff);
        printf("e_shoff        = 0x%x\n", (int) elf64Ehdr->e_shoff);
        printf("e_flags        = %d\n", elf64Ehdr->e_flags);
        printf("e_phentsize    = %d\n", elf64Ehdr->e_phentsize);
        printf("e_phum         = %d\n", elf64Ehdr->e_phnum);
        printf("e_shentsize    = %d\n", elf64Ehdr->e_shentsize);
        printf("e_shnum        = %d\n", elf64Ehdr->e_shnum);
        printf("e_shstrndx     = 0x%x\n", elf64Ehdr->e_shstrndx);
    } else {
        cout << "不是elf文件" << endl;
        return -1;
    }
    return 0;
}

int readElfPhdr(int fd, Elf64_Ehdr *elf64Ehdr, Elf64_Phdr *elf64Phdr) {
    lseek(fd, elf64Ehdr->e_phoff, SEEK_SET);
    for (int i = 0; i < elf64Ehdr->e_phnum; i++) {
        int n = read(fd, &elf64Phdr, sizeof(Elf64_Phdr));
        if (n != elf64Ehdr->e_phentsize) {
            return -1;
        }
    }
    return 0;
}

int printElfPhdr(Elf64_Phdr *elf64Phdr, Elf64_Ehdr *elf64Ehdr) {
    printf("------- Elf_Phdr -------\n");
    for (int i = 0; i < elf64Ehdr->e_phnum; i++) {
        printf("\n");
        Elf64_Phdr *phdr = &elf64Phdr[i];
        printf("Type                : %u\n", phdr->p_type);//p_type[phdr_->p_type]);
        printf("Offset              : %lu\n", phdr->p_offset);
        printf("Virtual Address     : 0x%x\n", (int) phdr->p_vaddr);
        printf("Physical Address    : 0x%x\n", (int) phdr->p_paddr);
        printf("File Size           : %lu\n", phdr->p_filesz);
        printf("Memory Size         : %lu\n", phdr->p_memsz);
        printf("Flags               : %u\n", phdr->p_flags);
        printf("Align               : %lu\n", phdr->p_align);
    }
}

int readElfShdr(int fd, Elf64_Shdr *elf64Shdr, Elf64_Ehdr *elf64Ehdr) {
    lseek(fd, elf64Ehdr->e_shoff, SEEK_SET);
    for (size_t i = 0; i < elf64Ehdr->e_shnum; i++) {
        size_t n = read(fd, (void *) (&elf64Shdr[i]), sizeof(Elf64_Shdr));

        if (n != elf64Ehdr->e_shentsize) {
            return -1;
        }
    }
    return 0;
}

int printElfShdr(Elf64_Shdr *elf64Shdr, Elf64_Ehdr *elf64Ehdr) {
    printf("------- Elf_Shdr -------\n");
    printf("Name                : %u\n", elf64Shdr->sh_name);
    printf("Type                : %d\n", elf64Shdr->sh_type);

    char flag[49];
    uint32_t flags = elf64Shdr->sh_flags;
    printf("Flag                : %d\n", flags);
    printf("Address             : 0x%x\n", (int) elf64Shdr->sh_addr);
    printf("Offset              : %lu\n", elf64Shdr->sh_offset);
    printf("Size                : %lu\n", elf64Shdr->sh_size);
    printf("Link                : %u\n", elf64Shdr->sh_link);
    printf("Info                : %u\n", elf64Shdr->sh_info);
    printf("Align               : %lu\n", elf64Shdr->sh_addralign);
    printf("Entsize             : %lu\n", elf64Shdr->sh_entsize);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        cout << "请输入文件名" << endl;
        cout << "格式: ./elfParse fileName" << endl;
        return -1;
    }
    const char *path = argv[1];
    Elf64_Ehdr elf64Ehdr;
    int fd = open(path, O_RDONLY);
    int ret = readElfEhdr(fd, &elf64Ehdr);
    if (ret < 0) {
        cout << "读取 elf ehdr失败" << endl;
        return ret;
    }
    ret = printElfEhdr(&elf64Ehdr);
    if (ret < 0) {
        return 0;
    }

    Elf64_Phdr *elf64Phdr = (Elf64_Phdr *) malloc(elf64Ehdr.e_phnum * elf64Ehdr.e_phentsize);
    ret = readElfPhdr(fd, &elf64Ehdr, elf64Phdr);
    if (ret < 0) {
        return ret;
    }
    ret = printElfPhdr(elf64Phdr, &elf64Ehdr);
    if (ret < 0) {
        return ret;
    }
    Elf64_Shdr *elf64Shdr = (Elf64_Shdr *) malloc(elf64Ehdr.e_shnum * elf64Ehdr.e_shstrndx);
    ret = readElfShdr(fd, elf64Shdr, &elf64Ehdr);
    if (ret < 0) {
        return ret;
    }
    printElfShdr(elf64Shdr, &elf64Ehdr);
    cout << "Hello, World!" << endl;
    return 0;
}