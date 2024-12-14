#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int printf(const char *fmt, ...) {
      va_list ap;
     char *s;
     char d_s[64];
     int d;
     va_start(ap, fmt);
     int j = 0;
     while (*fmt){
         if(*(fmt++) == '%'){
           switch (*fmt++) {
             case 's':              /* string */
                 s = va_arg(ap, char *);
                 for(size_t k=0; s[k]; k++){
                   putch(s[k]);
                   j++;
                 }
                 break;
             case 'd':              /* int */
                 d = va_arg(ap, int);
                 s = itoa(d, d_s);
                 printf("%s\n", s);
                 for(size_t k=0; s[k]; k++){
                   putch(s[k]);
                   j++;
                 }
                 break;
              case '%':              /* escape % */
                 putch('%');
                 j++;
                 break;
              default:              /* %后面没有构成格式化字符串的话，打印% */
                 putch('%');
                 j++;
                 break;
           }
         }
         else{
           putch(*(fmt-1));
                 j++;

         }
     }

    va_end(ap);
    return j;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}

int sprintf(char *out, const char *fmt, ...) {
     va_list ap;
     char *s;
     char d_s[64];
     int d;
     va_start(ap, fmt);
     int j = 0;
     while (*fmt){
         if(*(fmt++) == '%'){
           switch (*fmt++) {
             case 's':              /* string */
                 s = va_arg(ap, char *);
                 for(size_t k=0; s[k]; k++){
                   out[j++] = s[k];
                 }
                 break;
             case 'd':              /* int */
                 d = va_arg(ap, int);
                 s = itoa(d, d_s);
                 for(size_t k=0; s[k]; k++){
                   out[j++] = s[k];
                 }
                 break;
              case '%':              /* escape % */
                 out[j++] = '%';
                 break;
              default:              /* %后面没有构成格式化字符串的话，打印% */
                 out[j++] = '%';
                 break;
           }
         }
         else{
           out[j++] = *(fmt-1);
         }
     }

     va_end(ap);
    out[j] = '\0';
    // return strlen(j);
    return j;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
