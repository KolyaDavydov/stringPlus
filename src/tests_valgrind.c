#include <stdio.h>

#include "s21_string.h"

// <=== TEST CASES: s21_memchr ===>

void tc_s21_memchr1() {
  char *str1 = "Gd morning";
  int i = 111;
  s21_memchr(str1, i, s21_strlen(str1));
}

void tc_s21_memchr2() {
  char *str1 = s21_NULL;
  int i = 111;
  char *a = s21_memchr(str1, i, s21_strlen(str1));
  printf("%c", *a);
}

// <=== TEST CASES: s21_memcmp ===>

void tc_s21_memcmp() {
  s21_size_t n1 = 12, n2 = 8;
  char *str1 = "Hello there.", *str2 = "Don't underestimate my power!",
       *str3 = "Don't try it.";

  s21_memcmp(str1, str1, n1);
  s21_memcmp(str2, str3, n2);
  s21_memchr(0, 0, 0);
}

// <=== TEST CASES: s21_memcpy ===>

void tc_s21_memcpy() {
  s21_size_t n1 = 15, n2 = 5, n3 = 7;
  char s21_buf1[16] = {0}, s21_buf2[16] = "Hello there.",
       s21_buf3[32] = "Hello   Kenobi. General";
  char src1[16] = "General Kenobi.", src2[16] = "There";

  s21_memcpy(s21_buf1, src1, n1);
  s21_memcpy(s21_buf2, src2, n2);
  s21_memcpy(s21_buf3, s21_buf3 + 16, n3);
}

// <=== TEST CASES: s21_memmove ===>

void tc_s21_memmove() {
  s21_size_t n1 = 4, n2 = 32, n3 = 10;
  char s21_buf[64] = "It's over Anakin, I have the high ground.";
  s21_memmove(s21_buf, s21_buf + 5, n1);
  s21_memmove(s21_buf, s21_buf + 5, n2);
  s21_memmove(s21_buf + 5, s21_buf, n3);
}

// <=== TEST CASES: s21_memset ===>

void tc_s21_memset() {
  int i = 100;
  char buff[100] = "Spider Man  love a bananas";
  s21_memset(buff, 75, 101);
  s21_memset(buff, 101, 100);
  s21_memset(buff, i, 100);
}

// <=== TEST CASES: s21_strcat ===>

void tc_s21_strcat() {
  char buff1[100] = "Spider Man love a bananas";
  char buff2[100] = " and blue jeans";
  s21_strcat(buff1, buff2);
}

// <=== TEST CASES: s21_strncat ===>

void tc_s21_strncat() {
  s21_size_t i = 10;
  char buff1[100] = "Spider Man love a bananas";
  char buff2[100] = " and blue jeans";
  s21_strncat(buff1, buff2, i);
  s21_strncat(buff1, "and cats", i);
}

// <=== TEST CASES: s21_strchr ===>

void tc_s21_strchr() {
  int i = 10;
  char buff1[100] = "Spider Man love a bananas";
  char buff2[100] = " and blue jeans";
  s21_strchr(buff1, 111);
  s21_strchr(buff2, i);
}

// <=== TEST CASES: s21_strcmp ===>

void tc_s21_strcmp() {
  char buff1[100] = "Spider Man love a bananas";
  char buff2[100] = " and blue jeans";
  s21_strcmp(buff1, buff2);
  s21_strcmp(buff1, "Spider Man love a bananas");
}

// <=== TEST CASES: s21_strncmp ===>

void tc_s21_strncmp() {
  size_t a = 5;
  char buff1[100] = "Spider Man love a bananas";
  char buff2[100] = " and blue jeans";
  s21_strncmp(buff1, buff2, a);
  s21_strncmp(buff1, "Spshider Man love a bananas", a);
}

// <=== TEST CASES: s21_strcpy ===>

void tc_s21_strcpy() {
  char buff1[100] = "Spider Man love a bananas";
  char buff2[100] = " and blue jeans";
  s21_strcpy(buff1, buff2);
  s21_strcpy(buff1, "Spshider Man love a bananas");
}

// <=== TEST CASES: s21_strncpy ===>

void tc_s21_strncpy() {
  s21_size_t i = 10;
  char buff1[100] = "Spider Man love a bananas";
  char buff2[100] = " and blue jeans";
  s21_strncpy(buff1, buff2, i);
  s21_strncpy(buff1, "Spshider Man love a bananas", i);
}

// <=== TEST CASES: s21_strcspn ===>

void tc_s21_strcspn() {
  char buff1[100] = "Spider Man love a bananas";
  char buff2[100] = " and blue jeans";
  s21_strcspn(buff1, buff2);
  s21_strcspn(buff1, "o");
}

// <=== TEST CASES: s21_strerror ===>

void tc_s21_strerror() { s21_strerror(0); }

// <=== TEST CASES: s21_strlen ===>

void tc_s21_strlen() {
  char buff1[100] = "Spider Man love a bananas";
  char buff2[100] = " and blue jeans";
  s21_strlen(buff1);
  s21_strlen(buff2);
}

// <=== TEST CASES: s21_strpbrk ===>

void tc_s21_strpbrk() {
  char buff1[100] = "Spider Man love a bananas";
  char buff2[100] = " and blue jeans";
  s21_strpbrk(buff1, buff2);
}

// <=== TEST CASES: s21_strrchr ===>

void tc_s21_strrchr() {
  int i = 67;
  char buff1[100] = "Spider Man love a bananas";
  char buff2[100] = " and blue jeans";
  s21_strrchr(buff1, i);
  s21_strrchr(buff2, 97);
}

// <=== TEST CASES: s21_strspn ===>

void tc_s21_strspn() {
  char buff1[100] = "Spider Man love a bananasi";
  char buff2[100] = "Spider Mlova";
  s21_strspn(buff1, buff2);
}

// <=== TEST CASES: s21_strstr ===>

void tc_s21_strstr() {
  char buff1[100] = "Spider Man love a bananasi";
  char buff2[100] = "er";
  s21_strstr(buff1, buff2);
}

// <=== TEST CASES: s21_strtok ===>

void tc_s21_strtok() {
  char buff1[100] = "Spider Man love a bananasi";
  char buff2[100] = "era";
  char *a = s21_strtok(buff1, buff2);
  while (a != s21_NULL) {
    a = s21_strtok(s21_NULL, buff2);
  }
  a = s21_strtok(s21_NULL, buff2);
}

// <=== TEST CASES: s21_to_upper ===>

void tc_s21_upper() {
  char buff[100] = "Spider Man love a bananasi 123 /// 0";
  char *a = s21_to_upper(buff);
  if (a) free(a);
}

// <=== TEST CASES: s21_to_lower ===>

void tc_s21_lower() {
  char buff[100] = "SPIDER MAN LOVE A BANANASI /// 0";
  char *a = s21_to_lower(buff);
  if (a) free(a);
}

// <=== TEST CASES: s21_insert ===>

void tc_s21_insert() {
  char buff[100] = "qwe";
  char arr[100] = "wqe";
  s21_size_t i = 25;
  char *a = s21_insert(buff, arr, i);
  printf("%s", a);
  if (a) free(a);
}

// <=== TEST CASES: s21_trim ===>

void tc_s21_trim() {
  char str[] = "        abc         ";
  char *trim_ch = s21_NULL;
  char *got = s21_trim(str, trim_ch);
  printf("%s", got);
  // if (got) free(got);
}

int main(void) {
  tc_s21_memchr1();
  tc_s21_memchr2();
  // tc_s21_memcmp();
  // tc_s21_memcpy();
  // tc_s21_memmove();
  // tc_s21_memset();
  // tc_s21_strcat();
  // tc_s21_strncat();
  // tc_s21_strchr();
  // tc_s21_strcmp();
  // tc_s21_strncmp();
  // tc_s21_strcpy();
  // tc_s21_strncpy();
  // tc_s21_strcspn();
  // tc_s21_strerror();
  // tc_s21_strlen();
  // tc_s21_strpbrk();
  // tc_s21_strrchr();
  // tc_s21_strspn();
  // tc_s21_strstr();
  // tc_s21_strtok();
  // tc_s21_upper();
  // tc_s21_lower();
  // tc_s21_insert();
  // tc_s21_trim();
  return 0;
}
