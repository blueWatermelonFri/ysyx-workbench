#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

static size_t index = 0;

void get_stdarg_string(const char *fmt, va_list *ap, char *s){
  int d;
  char d2s[64];
  char escape[2] = {'%', '\0'};
  char ordinary[2] = {fmt[index], '\0'};

  if((fmt[index++]) == '%'){
    switch (fmt[index++]) {
      case 's':              /* string */
          s = va_arg(*ap, char *);
          s = "12";
          return;
          break;
      case 'd':              /* int */
          d = va_arg(*ap, int);
          s = itoa(d, d2s);
          s = "12";
          return;
          break;
      case '%':              /* escape % */
          s = escape;
          s = "12";
          return;
          break;
      default:              /* %后面没有构成格式化字符串的话，打印% */
          s = escape;
          s = "12";
          return;
          break;
    }
  }
  else{
      s = ordinary;
      s = "12";
      return;
  }
}
// int printf(const char *fmt, ...) {
//     index = 0;
//      va_list ap;
//      char *s;
//      char d_s[64];
//      int d;
//      va_start(ap, fmt);
//      int j = 0;
//      char flag = '0';
//      while (*fmt){
//          if(*(fmt++) == '%'){
//            switch (*fmt++) {
//              case 's':              /* string */
//                  s = va_arg(ap, char *);
//                  for(size_t k=0; s[k]; k++){
//                    putch(s[k]);
//                    j++;
//                  }
//                  break;
//              case 'd':              /* int */
//                  d = va_arg(ap, int);
//                  s = itoa(d, d_s);
//                  for(size_t k=0; s[k]; k++){
//                    putch(s[k]);
//                    j++;
//                  }
//                  break;
//               case '%':              /* escape % */
//                  putch('%');
//                  j++;
//                  break;
//               default:              /* %后面没有构成格式化字符串的话，打印% */
//                  putch('%');
//                  j++;
//                  break;
//            }
//          }
//          else{
//            putch(*(fmt-1));
//                  j++;

//          }
//      }

//     va_end(ap);
//     return j;
// }

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}

int sprintf(char *out, const char *fmt, ...) {
  index = 0;
  char *s = NULL;
  int j = 0;
  va_list ap;
  va_start(ap, fmt);
  while (fmt[index]){
    get_stdarg_string(fmt, &ap, s);
    for(size_t k=0; s[k] != '\0'; k++){
      out[j++] = s[k];
    }
    s = NULL;
  }
  va_end(ap);
  out[j] = '\0';
  return j;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
