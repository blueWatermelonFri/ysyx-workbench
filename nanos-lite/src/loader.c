#include <proc.h>
#include <elf.h>

#ifdef __LP64__
# define Elf_Ehdr Elf64_Ehdr
# define Elf_Phdr Elf64_Phdr
#else
# define Elf_Ehdr Elf32_Ehdr
# define Elf_Phdr Elf32_Phdr
#endif

size_t ramdisk_write(const void *buf, size_t offset, size_t len);
size_t ramdisk_read(void *buf, size_t offset, size_t len);

static uintptr_t loader(PCB *pcb, const char *filename) {
  extern const char ramdisk_start[];
  Elf32_Ehdr elf_header;
  Elf32_Phdr program_header;
  uint32_t segOffset, segVirtAddr, segFileSize, segMemSize;

  uint8_t * ph_addr;
  ramdisk_read(&elf_header, 0, sizeof(Elf32_Ehdr));
  // sizeof是个编译器的运算符？不是stdlib这些库的实现？

  // assert(*(uint32_t *)elf->e_ident == 0x7F454C46);
  if (elf_header.e_ident[EI_MAG0] != ELFMAG0 ||
      elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
      elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
      elf_header.e_ident[EI_MAG3] != ELFMAG3) {
      printf("Error: Not a ELF format file!\n");
      assert(0);
  }
  // e_phoff表示program header table file 在elf文件中的偏移
  ph_addr = (uint8_t *) (elf_header.e_phoff + ramdisk_start);

  // e_phnum表示program header table file里面有几个entry
  // phentsize表示program header table file中每个entry的大小
  // p_type表示这个entry对应的section的类型

  for(int i = 0; i<elf_header.e_phnum; i++){
    memcpy(&program_header, ph_addr + elf_header.e_phentsize * i, sizeof(Elf32_Phdr));
    if(program_header.p_type == PT_LOAD){
      segOffset = program_header.p_offset;
      segFileSize = program_header.p_filesz;
      segMemSize =  program_header.p_memsz;
      segVirtAddr =  program_header.p_vaddr;
      // MemSize >= FileSize 通常是因为bss段，https://stackoverflow.com/questions/27958743/difference-between-p-filesz-and-p-memsz-of-elf32-phdr
      // memcpy((uint8_t *) segVirtAddr, (uint8_t *) (segOffset + ramdisk_start), segFileSize);
      ramdisk_read((void *) segVirtAddr, segOffset, segFileSize);
      memset((uint8_t *) (segVirtAddr + segFileSize), segMemSize-segFileSize, 0);

    }
  }


  return elf_header.e_ehsize;
}

void naive_uload(PCB *pcb, const char *filename) {
  uintptr_t entry = loader(pcb, filename);
  Log("Jump to entry = %p", entry);
  ((void(*)())entry) ();
}

