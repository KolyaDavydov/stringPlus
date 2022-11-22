#include "s21_string.h"

void tc_s21_memcmp() {
  s21_size_t n1 = 12, n2 = 8;
  char *str1 = "Hello there.", *str2 = "Don't underestimate my power!",
       *str3 = "Don't try it.";

  s21_memcmp(str1, str1, n1);
  s21_memcmp(str2, str3, n2);
}

void tc_s21_memcpy() {
  s21_size_t n1 = 15, n2 = 5, n3 = 7;
  char s21_buf1[16] = {0}, s21_buf2[16] = "Hello there.",
       s21_buf3[32] = "Hello   Kenobi. General";
  char src1[16] = "General Kenobi.", src2[16] = "There";

  s21_memcpy(s21_buf1, src1, n1);
  s21_memcpy(s21_buf2, src2, n2);
  s21_memcpy(s21_buf3, s21_buf3 + 16, n3);
}

int main(void) {
  tc_s21_memcmp();
  tc_s21_memcpy();
  return 0;
}
