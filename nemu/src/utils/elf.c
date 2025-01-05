#include <common.h>
#include <elf.h>

//bug 这个大小定得太死了
uint32_t ftrace_func_begin[2048];
uint32_t ftrace_func_end[2048];
uint32_t ftrace_func_count = 0;
char ftrace_func_name[2048][128];

void init_elf(const char *filename) {
    FILE *file = fopen(filename, "rb");
    // printf("%s\n", *filename)
    if (file == NULL) {
        perror("Can not open ELF file!");
        exit(EXIT_FAILURE);
    }
    
    size_t         ret;
    Elf32_Ehdr elf_header;

    ret = fread(&elf_header, 1, sizeof(Elf32_Ehdr), file);
    if (ret != sizeof(Elf32_Ehdr)) {
        fprintf(stderr, "fread() failed: %zu\n", ret);
        exit(EXIT_FAILURE);
    }

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
    ret = fread(section_headers, sizeof(Elf32_Shdr), elf_header.e_shnum, file);
    if (ret != elf_header.e_shnum) {
        fprintf(stderr, "fread() failed: %zu\n", ret);
        exit(EXIT_FAILURE);
    }

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
    ret = fread(symbols, 1, symtab_header.sh_size, file);
    if (ret != symtab_header.sh_size) {
        fprintf(stderr, "fread() failed: %zu\n", ret);
        exit(EXIT_FAILURE);
    }

    // 读取字符串表
    Elf32_Shdr strtab_header = section_headers[strtab_index];
    char *strtab = malloc(strtab_header.sh_size);
    fseek(file, strtab_header.sh_offset, SEEK_SET);
    ret = fread(strtab, 1, strtab_header.sh_size, file);
    if (ret != strtab_header.sh_size) {
        fprintf(stderr, "fread() failed: %zu\n", ret);
        exit(EXIT_FAILURE);
    }
    
    // 打印符号表信息
    int num_symbols = symtab_header.sh_size / sizeof(Elf32_Sym);
    for (int i = 0; i < num_symbols; i++) {
        Elf32_Sym sym = symbols[i];
        if(ELF32_ST_TYPE(sym.st_info) == STT_FUNC){
            if(sym.st_size != 0){
                strcpy(ftrace_func_name[ftrace_func_count], &strtab[sym.st_name]);
                ftrace_func_begin[ftrace_func_count] = sym.st_value;
                ftrace_func_end[ftrace_func_count] = sym.st_value + sym.st_size - 4;
                ftrace_func_count ++;
            }
        }
    }

    // for(int i = 0 ; i < ftrace_func_count; i++){
    //     printf("%s  ", ftrace_func_name[i]);
    //     printf("%x  ", ftrace_func_begin[i]);
    //     printf("%x \n", ftrace_func_end[i]);
    // }
    // 清理
    free(symbols);
    free(strtab);
    free(section_headers);
    fclose(file);
}