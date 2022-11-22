#include "s21_string.h"

void tc_s21_memcmp() {
  s21_size_t n1 = 12, n2 = 8;
  char *str1 = "Hello there.", *str2 = "Don't underestimate my power!",
       *str3 = "Don't try it.";

  s21_memcmp(str1, str1, n1);
  s21_memcmp(str2, str3, n2);
}

int main(void) {
  tc_s21_memcmp();
  return 0;
}
