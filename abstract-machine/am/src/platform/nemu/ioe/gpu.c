#include <am.h>
#include <nemu.h>
#include <stdio.h>
#define SYNC_ADDR (VGACTL_ADDR + 4)

  // VGACTL_ADDR = vgactl_port_base[0]表示屏幕的宽度和高度
  // vgactl_port_base[0] = (screen_width() << 16) | screen_height();
void __am_gpu_init() {
  // int i;
  // int h = *(volatile uint32_t *)(VGACTL_ADDR) & 0x0000ffff;  // 
  // int w = (*(volatile uint32_t *)(VGACTL_ADDR) >> 16) & 0x0000ffff;  // 

  // uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;
  // for (i = 0; i < w * h; i ++) fb[i] = i;
  // outl(SYNC_ADDR, 1);
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = (*(volatile uint32_t *)(VGACTL_ADDR) >> 16) & 0x0000ffff,
    .height = (*(volatile uint32_t *)(VGACTL_ADDR)) & 0x0000ffff ,
    .vmemsz = 0
  };
}

// 框架里很多io_write 都默认把sync设置为false
void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  if (ctl->sync) {
    int x = ctl->x, y = ctl->y, w = ctl->w, h = ctl->h;
    uint32_t *tmp = (uint32_t *)ctl->pixels;
    int offset = y * 400 + x;

    for(int j = 0; j < h; j++){
      for(int i = 0; i < w; i++) {
        *(volatile uint32_t *)(FB_ADDR + (offset + j * 400 + i) * sizeof(uint32_t)) = tmp[j * w + i];
      }
    }
    outl(SYNC_ADDR, 1);
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
