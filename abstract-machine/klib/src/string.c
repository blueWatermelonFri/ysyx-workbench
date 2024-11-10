#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  size_t i = 0;

  while(s[i] != '\0') i++;
  return i;
}

char *strcpy(char *dst, const char *src) {
  size_t i;
  
  for (i = 0; src[i] != '\0'; i++)
    dst[i] = src[i];
  dst[i] = '\0';
  return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
    size_t i;

    for (i = 0; i < n && src[i] != '\0'; i++)
        dst[i] = src[i];
    for ( ; i < n; i++)
        dst[i] = '\0';

    return dst;

}

char *strcat(char *dst, const char *src) {
  size_t dest_len = strlen(dst);
  size_t i;

  for (i = 0 ; src[i] != '\0' ; i++)
      dst[dest_len + i] = src[i];
  dst[dest_len + i] = '\0';

  return dst;

}

int strcmp(const char *s1, const char *s2) {
  const unsigned char *p1 = (const unsigned char *) s1;
  const unsigned char *p2 = (const unsigned char *) s2;
  unsigned int c1, c2;

  do
    {
      c1 = (unsigned char) *p1++;
      c2 = (unsigned char) *p2++;
      if (c1 == '\0')
	      return c1 - c2;
    }
  while (c1 == c2);

  return c1 - c2;
}

int strncmp(const char *s1, const char *s2, size_t n) {
  panic("Not implemented");
}

void *memset(void *s, int c, size_t n) {
  char *p1 = (char *) s;
  size_t i;
  for(i = 0; i < n; i++){
    p1[i] = (char) c;
  }
  return s;
}

void *memmove(void *dst, const void *src, size_t n) {
  panic("Not implemented");
}

void *memcpy(void *out, const void *in, size_t n) {
  panic("Not implemented");
}

int memcmp(const void *s1, const void *s2, size_t n) {
  
  if(n == 0) return 0;

  const unsigned char *p1 = (const unsigned char *) s1;
  const unsigned char *p2 = (const unsigned char *) s2;
  unsigned int c1, c2;

  do
    { 
      n --;
      c1 = (unsigned char) *p1++;
      c2 = (unsigned char) *p2++;

    }
  while (c1 == c2 && n > 0);

  return c1 - c2;
}

#endif
