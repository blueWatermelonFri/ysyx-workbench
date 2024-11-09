#include <stdio.h>
#include <stdlib.h>
#include <elf.h>

void read_elf_symbols(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("无法打开文件");
        exit(EXIT_FAILURE);
    }

    Elf32_Ehdr elf_header;
    fread(&elf_header, 1, sizeof(Elf32_Ehdr), file);

    // 验证 ELF 文件格式
    if (elf_header.e_ident[EI_MAG0] != ELFMAG0 ||
        elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
        elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
        elf_header.e_ident[EI_MAG3] != ELFMAG3) {
        fprintf(stderr, "不是有效的 ELF 文件\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    // 定位节头表
    fseek(file, elf_header.e_shoff, SEEK_SET);

    // 读取节头表
    Elf32_Shdr *section_headers = malloc(sizeof(Elf32_Shdr) * elf_header.e_shnum);
    fread(section_headers, sizeof(Elf32_Shdr), elf_header.e_shnum, file);

    // 找到符号表和字符串表的索引
    int symtab_index = -1;
    int strtab_index = -1;
    for (int i = 0; i < elf_header.e_shnum; i++) {
        if (section_headers[i].sh_type == SHT_SYMTAB) {
            symtab_index = i;
        }
        if (section_headers[i].sh_type == SHT_STRTAB && i != elf_header.e_shstrndx) {
            strtab_index = i;
        }
    }

    if (symtab_index == -1 || strtab_index == -1) {
        fprintf(stderr, "找不到符号表或字符串表\n");
        free(section_headers);
        fclose(file);
        exit(EXIT_FAILURE);
    }

    // 读取符号表
    Elf32_Shdr symtab_header = section_headers[symtab_index];
    Elf32_Sym *symbols = malloc(symtab_header.sh_size);
    fseek(file, symtab_header.sh_offset, SEEK_SET);
    fread(symbols, 1, symtab_header.sh_size, file);

    // 读取字符串表
    Elf32_Shdr strtab_header = section_headers[strtab_index];
    char *strtab = malloc(strtab_header.sh_size);
    fseek(file, strtab_header.sh_offset, SEEK_SET);
    fread(strtab, 1, strtab_header.sh_size, file);

    // 打印符号表信息
    int num_symbols = symtab_header.sh_size / sizeof(Elf32_Sym);
    for (int i = 0; i < num_symbols; i++) {
        Elf32_Sym sym = symbols[i];
        if(ELF32_ST_TYPE(sym.st_info) == STT_FUNC){
            const char *name = &strtab[sym.st_name];
            printf("符号名: %s, begin: 0x%x, end: %x\n", name, sym.st_value, sym.st_value + sym.st_size - 4);
        }
    }

    // 清理
    free(symbols);
    free(strtab);
    free(section_headers);
    fclose(file);
}

int main() {
    const char *filename = "/home/myuser/ysyx/ysyx-workbench/am-kernels/tests/cpu-tests/build/add-riscv32-nemu.elf";  // 替换为你的 ELF 文件名
    read_elf_symbols(filename);
    return 0;
}
