#include "s21_string.h"

/**
    1. Searches for the first occurrence of the character c (an unsigned char)
    in the first n bytes of the string pointed to, by the argument str.

    Implemented by: Almeta Terry
**/
void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *res = s21_NULL;
  const unsigned char *ptr = str;
  for (int i = 0; i < (int)n; i++) {
    if (*ptr == (unsigned char)c) {
      res = (void *)ptr;
    } else {
      ptr++;
    }
  }
  return res;
}

/**
    2. Compares the first n bytes of str1 and str2.

    Implemented by: Tania Kiara
**/
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0;
  for (s21_size_t i = 0; i < n && !result; i++) {
    unsigned char ch1 = *(unsigned char *)(str1 + i);
    unsigned char ch2 = *(unsigned char *)(str2 + i);
    if (ch1 != ch2) result = ch1 - ch2;
  }
  return result;
}

/**
    3. Copies n characters from src to dest.

    Implemented by: Tania Kiara
**/
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *to = dest;
  for (s21_size_t i = 0; i < n; i++) to[i] = ((unsigned char *)src)[i];
  return to;
}

/**
    4. Another function to copy n characters from src to dest.

    Implemented by: Tania Kiara
**/
void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  unsigned char *to = dest;
  void *result = to;

  if (src != dest && n != 0) {
    if (dest > src && dest - src < (int)n) {
      for (int i = n - 1; i >= 0; i--) to[i] = ((unsigned char *)src)[i];
      result = dest;
    } else if (src > dest && src - dest < (int)n) {
      for (s21_size_t i = 0; i < n; i++) to[i] = ((unsigned char *)src)[i];
      result = dest;
    } else {
      s21_memcpy(dest, src, n);
    }
  }

  return result;
}

/**
    5. Copies the character c (an unsigned char) to the first n characters of
    the string pointed to, by the argument str.

    Implemented by: Almeta Terry
**/
void *s21_memset(void *str, int c, s21_size_t n) {
  char *ptr = str;
  for (s21_size_t i = 0; i < n; i++) *(ptr + i) = c;
  return ptr;
}

/**
    6. Appends the string pointed to, by src to the end of the string pointed to
    by dest.

    Implemented by: Almeta Terry
**/
char *s21_strcat(char *dest, const char *src) {
  char *tmp = dest;
  while (*dest != '\0') dest++;
  while (*src != '\0') *dest++ = *src++;
  *dest = '\0';
  return tmp;
}

/**
    7. Appends the string pointed to, by src to the end of the string pointed
    to, by dest up to n characters long.

    Implemented by: Almeta Terry
**/

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *tmp = dest;
  while (*dest != '\0') dest++;
  while (n-- > 0) *dest++ = *src++;
  return tmp;
}

/**
    8. Searches for the first occurrence of the character c (an unsigned char)
    in the string pointed to, by the argument str.

    Implemented by: Almeta Terry
**/

char *s21_strchr(const char *str, int c) {
  char *ptr = s21_NULL;
  while (1) {
    if (*str == (char)c) {
      ptr = (char *)str;
      break;
    }
    if (*str == '\0') break;
    str++;
  }
  return ptr;
}

/**
    9. Compares the string pointed to, by str1 to the string pointed to by str2.

    Implemented by: Almeta Terry
**/

int s21_strcmp(const char *str1, const char *str2) {
  while (*str1)
    if (*str1++ != *str2++) break;
  return *str1 - *str2;
}

/**
    10. Compares at most the first n bytes of str1 and str2.

    Implementes by: Almeta Terry
**/
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  for (s21_size_t i = 0; i < n && result == 0; i++)
    result = *(str1 + i) - *(str2 + i);
  return result;
}

/**
    11. Copies the string pointed to, by src to dest.

    Implementes by: Almeta Terry
**/
char *s21_strcpy(char *dest, const char *src) {
  char *tmp = dest;
  while (*src != '\0') *dest++ = *src++;
  *dest = '\0';
  return tmp;
}

/**
    12. Copies up to n characters from the string pointed to, by src to dest.

    Implementes by: Almeta Terry
**/
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *tmp = dest;
  s21_size_t tmp_n = 0;
  while (tmp_n < n) {
    if (*src != '\0')
      *dest++ = *src++;
    else
      *dest++ = '\0';
    tmp_n++;
  }
  return tmp;
}

/**
    13. Calculates the length of the initial segment of str1 which consists
    entirely of characters not in str2.

    Implementes by: Almeta Terry
**/
s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t counter = 0;
  while (*str1 != '\0' && !s21_strchr(str2, *str1++)) counter++;
  return counter;
}

/**
    14. Searches an internal array for the error number errnum and returns a
    pointer to an error message string. You need to declare macros containing
    arrays of error messages for mac and linux operating systems. Error
    descriptions are available in the original library. Checking the current
    OS is carried out using directives.

    Implementes by: Almeta Terry
**/

// макросы (ERROR_NUM и LIST_ERROR) содержащие массивы строк
// в зависимости от ОС (linux  или mac)
// объявлены в заголовочном файле, там же с помощью деректив
// определяется текущая операционная система

char *s21_strerror(int errnum) {
  static char error[1024] = {'\0'};
  char *error_list[] = LIST_ERROR;
  if (errnum >= 0 && errnum < ERROR_NUM) {
    s21_strcpy(error, error_list[errnum]);
  } else {
    char tmp_num[50] = {0};  // для хранения числа в виде строки
#if defined(__linux__)
    s21_strcpy(error, "Unknown error ");
#elif (__APPLE__)
    s21_strcpy(error, "Unknown error: ");
#endif
    // ЛИБО ЗДЕСЬ МОЖНО БУДЕТ ВОСПОЛЬЗОТЬСЯ ФУНКЦИЕЙ S21_sprintf()
    s21_strcat(error, int_to_str(tmp_num, errnum));
  }
  return error;
}

// ВСПОМОГАТЕЛЬНАЯ ФУНКЦИЯ, ЕСЛИ СДЛЕАЕМ sprintf, то можно сократить
// ALMETA TERRY
char *int_to_str(char *tmp_num, int errnum) {
  int num = errnum;
  int pow_of_ten = 1;
  int minus = 0;  // если число отрицаткльное то будет = 1
  if (num < 0) {
    minus = 1;
    num = -num;
  }
  if (num == 0) {
    tmp_num[0] = '0';
    tmp_num[1] = '\0';
  } else {
    while (pow_of_ten <= num) {
      pow_of_ten *= 10;
    }
    pow_of_ten /= 10;
    int position;  // разряд числа
    if (minus == 0) {
      position = 0;
    } else {
      tmp_num[0] = '-';
      position = 1;
    }
    while (pow_of_ten != 0) {
      tmp_num[position] = '0' + num / pow_of_ten;
      num = num - num / pow_of_ten * pow_of_ten;
      pow_of_ten /= 10;
      position++;
    }
    tmp_num[position] = '\0';
  }
  return tmp_num;
}

/**
    15. Computes the length of the string str up to but not including the
    terminating null character.

    Implementes by: Almeta Terry
**/
s21_size_t s21_strlen(const char *str) {
  s21_size_t length = 0;
  while (*(str++) != 0) length++;
  return length;
}

/**
    16. Finds the first character in the string str1 that matches any
character specified in str2.

    Implementes by: Almeta Terry
**/
char *s21_strpbrk(const char *str1, const char *str2) {
  char *ptr = s21_NULL;
  int flag = 0;
  while (*str1 != '\0' && flag == 0) {
    for (s21_size_t i = 0; i < s21_strlen(str2); i++) {
      if (*str1 == str2[i]) {
        flag = 1;
        ptr = (char *)str1;
      }
    }
    str1++;
  }
  return ptr;
}

/**
    17. Searches for the last occurrence of the character c (an unsigned char)
    in the string pointed to by the argument str.

    Implementes by: Almeta Terry
**/
char *s21_strrchr(const char *str, int c) {
  char *ptr = s21_NULL;
  for (s21_size_t i = 0; i < s21_strlen(str) + 1; i++) {
    if (str[i] == (unsigned char)c) ptr = (char *)&str[i];
  }
  return ptr;
}

/**
    18. Calculates the length of the initial segment of str1 which consists
    entirely of characters in str2.

    Implementes by: Almeta Terry
**/
s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t counter = 0;
  while (*str1 != '\0' && s21_strchr(str2, *str1++)) counter++;
  return counter;
}

/**
    19. Finds the first occurrence of the entire string needle (not including
    the terminating null character) which appears in the string haystack.

    Implementes by: Almeta Terry
**/
char *s21_strstr(const char *haystack, const char *needle) {
  s21_size_t i = 0, j = 0;
  char *ptr = s21_NULL;
  if (needle[0] == '\0') ptr = (char *)haystack;
  while (haystack[i] != '\0') {
    while (haystack[i + j] != '\0' && haystack[i + j] == needle[j]) {
      if (needle[j + 1] == '\0') ptr = (char *)(haystack + i);
      ++j;
    }
    ++i;
  }
  return ptr;
}

/**
    20. Breaks string str into a series of tokens separated by delim.

    Implementes by: Aqua Nelida
**/
char *s21_strtok(char *str, const char *delim) {
  static char *arr = s21_NULL;
  int flag = 0;
  int check = 0;
  int ch = 0;

  if (!str) {
    str = arr;
    if (arr) {
      flag = 1;
      ch = *str;
    } else {
      arr = s21_NULL;
      flag = 0;
    }
  } else {
    if (*str == '\0') str = s21_NULL;
    if (*delim == '\0') check = 1;
    if (!str || *delim == '\0') {
      flag = 0;
    } else {
      flag = 1;
      ch = *str;
      if (s21_strpbrk(str, delim) == s21_NULL) flag = 0;
    }
  }

  while (s21_strchr(delim, ch) && flag != 0) {
    if ((ch = *++str) == '\0') {
      flag = 0;
    }
  }

  if (flag != 0) {
    arr = str + s21_strcspn(str, delim);
    if (*arr != '\0') {
      *arr = '\0';
    }
  } else if ((check != 1 && ch == 0) || *str == '\0') {
    str = 0;
  }

  return str;
}

/**
    21. Reads formatted input from a string.

    Implemented by: Tania Kiara
**/
int s21_sscanf(const char *str, const char *format, ...) {
  int result = -1;
  int bytes_scanned = 0;

  if (str != s21_NULL && format != s21_NULL && s21_strlen(str) != 0) {
    va_list vl;
    char *src = (char *)str;
    char *fmt = (char *)format;

    va_start(vl, format);
    while (*(fmt)) {
      if (is_spec_start(*fmt)) {
        sp_t spec = {0};
        fmt += parse_spec(&spec, fmt);
        int res = exec_spec(&spec, &vl, src, bytes_scanned, &result);
        src += res;
        bytes_scanned += res;
        while (is_space(*src)) {
          ++src;
          bytes_scanned++;
        }
      } else if (!skip_char(*fmt)) {
        if (*fmt != *src) break;
        fmt++;
        src++;
        bytes_scanned++;
      } else {
        fmt++;
      }
    }
    va_end(vl);
  }

  return result;
}
