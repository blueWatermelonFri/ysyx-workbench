#include <proc.h>
#include <elf.h>

#ifdef __LP64__
# define Elf_Ehdr Elf64_Ehdr
# define Elf_Phdr Elf64_Phdr
#else
# define Elf_Ehdr Elf32_Ehdr
# define Elf_Phdr Elf32_Phdr
#endif

static uintptr_t loader(PCB *pcb, const char *filename) {
  extern const char ramdisk_start[];
  Elf32_Ehdr elf_header;
  memcpy(&elf_header, ramdisk_start, sizeof(Elf32_Ehdr));
  // assert(*(uint32_t *)elf->e_ident == 0x7F454C46);
  if (elf_header.e_ident[EI_MAG0] != ELFMAG0 ||
      elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
      elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
      elf_header.e_ident[EI_MAG3] != ELFMAG3) {

      assert(0);
  }
        printf("%x\n", elf_header.e_ident[EI_MAG0]);
      printf("%x\n", elf_header.e_ident[EI_MAG1]);
      printf("%x\n", elf_header.e_ident[EI_MAG2]);
      printf("%x\n", elf_header.e_ident[EI_MAG3]);
  return elf_header.e_ehsize;
}

void naive_uload(PCB *pcb, const char *filename) {
  uintptr_t entry = loader(pcb, filename);
  Log("Jump to entry = %p", entry);
  ((void(*)())entry) ();
}

