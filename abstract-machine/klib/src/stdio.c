#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int printf(const char *fmt, ...) {
  panic("Not implemented");
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}

int sprintf(char *out, const char *fmt, ...) {
    va_list ap;
    char *s;
    char d_s[128];

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
                itoa(d, d_s);
                for(size_t k=0; d_s[k]; k++){
                  out[j++] = d_s[k];
                }
                break;
          }
        }
        else{
          out[j++] = *(fmt-1);
        }
    }
        
    
    va_end(ap);
    out[j] = '\0';
    return strlen(out);
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif



void foo(char *fmt, ...)   /* '...' is C syntax for a variadic function */
{
    va_list ap;
    int d;
    char c;
    char *s;

    va_start(ap, fmt);
    while (*fmt){
  
        if(*(fmt++) == '%'){
            
        switch (*fmt++) {
        case 's':              /* string */
            s = va_arg(ap, char *);
            printf("string %s\n", s);
            break;
        case 'd':              /* int */
            d = va_arg(ap, int);
            printf("int %d\n", d);
            break;
        case 'c':              /* char */
            /* need a cast here since va_arg only
              takes fully promoted types */
            c = (char) va_arg(ap, int);
            printf("char %c\n", c);
            break;
        }
    }


    }
        
    
    va_end(ap);
}
