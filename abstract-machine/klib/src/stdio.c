#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

static size_t index = 0;

// padding string by flag and width
// negtive 表示为负数的时候，填充需要做一些特殊处理
void format_padding(char *d2s, char *s, char flag, unsigned int width){

  int offset = 0;
  int negtive = d2s[0] == '-'; // 如果恰好是-开头的字符串呢
  int str_len = strlen(d2s);

  if(width != 0){
    if(str_len < width){
      for(int i = 0; i < width - str_len; i++){
        s[offset++] = flag;
      }
    }
  }
  strcpy(s + offset, d2s);

  // 如果为负数，则需要将负号和第一个0交换位置
  if(negtive && flag == '0'){
    s[0] = '-';
    s[offset] = '0';
  }
  return;
}

static inline int is_format_specifier(char c){
  return c != 'c' && c != 's' && c != 'd' && c != 'x' && c != 'X' && c != 'u' && c != 'f' && c != 'F' &&c != 'o';
}

void get_stdarg_string(const char *fmt, va_list *ap, char *s){
  // 每添加一种specifier，都要更新is_format_specifier函数
  int d;
  unsigned int x = 0;
  char flag = ' ';
  unsigned int width = 0;
  char d2s[64];
  char *temp = NULL;
  char c = '\0';
  char escape[2] = {'%', '\0'};
  char ordinary[2] = {fmt[index], '\0'};

  if((fmt[index++]) == '%'){
    while(fmt[index]){
      switch (fmt[index++]) {
        case 's':              /* string */
            temp = va_arg(*ap, char *);
            // strcpy(s, temp);
            format_padding(temp, s, flag, width);
            return;
            break;
        case 'c':              /* char */
            c = va_arg(*ap, int);
            d2s[0] = (char)c;
            d2s[1] = '\0';
            format_padding(d2s, s, flag, width);
            return;
            break;
        case 'd':              /* int */
            d = va_arg(*ap, int);
            itoa(d, d2s);
            format_padding(d2s, s, flag, width);
            return;
            break;
        case 'u':              /* int */
            x = va_arg(*ap, unsigned int);
            utostring(x, d2s);
            format_padding(d2s, s, flag, width);
            return;
            break;            
        case 'x':              /* int */
            x = va_arg(*ap, unsigned int);
            hex2str(x, d2s, 0);
            format_padding(d2s, s, flag, width);
            return;
            break;
        case 'X':              /* int */
            x = va_arg(*ap, unsigned int);
            hex2str(x, d2s, 1);
            format_padding(d2s, s, flag, width);
            return;
            break;
        case '%':              /* escape % */
            strcpy(s, escape);
            return;
            break;
        case '0':              /* escape % */
            panic_on((fmt[index]) == '0', "Error:field width should not begin with 0");
            flag = '0';
            while(is_format_specifier(fmt[index])){
              width = width * 10 + (fmt[index] - '0');
              index ++;
            }
            break;
        default:              /* %后面没有构成格式化字符串的话，表明字符串有问题*/
            panic_on((fmt[index]) == '0', "Error:field width should not begin with 0");
            while(is_format_specifier(fmt[index])){
              width = width * 10 + (fmt[index] - '0');
              index ++;
            }
            break;
      }
    }
  }
  else{
    strcpy(s, ordinary);
    return;
  }
}

int printf(const char *fmt, ...) {
  index = 0;
  char temp[1024];  // 如何改进，因为64是固定的
  int j = 0;
  va_list ap;
  va_start(ap, fmt);
  while (fmt[index]){
    get_stdarg_string(fmt, &ap, temp);
    for(size_t k=0; temp[k] != '\0'; k++){
      putch(temp[k]);
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
  index = 0;
  char temp[64];  // 如何改进，因为64是固定的
  int j = 0;
  va_list ap;
  va_start(ap, fmt);
  while (fmt[index]){
    get_stdarg_string(fmt, &ap, temp);
    for(size_t k=0; temp[k] != '\0'; k++){
      out[j++] = temp[k];
    }
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
