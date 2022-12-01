#include <string.h>

#include "s21_string.h"
#include "stdio.h"

// <=== TEST CASES: s21_memcmp ===>

void tc_s21_memchr() {
  char *str1 = "Gd morning";
  int i = 111;
  s21_memchr(str1, i, s21_strlen(str1));
  s21_memchr(str1, 75, 1);
  s21_memchr(0, 0, 0);
}

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

int main(void) {
  tc_s21_memchr();
  tc_s21_memcmp();
  tc_s21_memcpy();
  tc_s21_memmove();
  tc_s21_memset();
  tc_s21_strcat();
  tc_s21_strncat();
  return 0;
}
