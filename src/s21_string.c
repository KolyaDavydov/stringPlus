#include "s21_string.h"

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
    10. Compares at most the first n bytes of str1 and str2.

    Implementes by: Almeta Terry
**/
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  for(s21_size_t i = 0; i < n && result == 0; i++) {
    result = *(str1 + i) - *(str2 + i);
  }
  return result;
}