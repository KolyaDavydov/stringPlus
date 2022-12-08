#include <check.h>
#include <stdio.h>
#include <string.h>

#include "s21_string.h"

#define BUFF_SIZE 512

/**
    --------------------------------------------------
            <========== TEST CASES ==========>
    --------------------------------------------------
**/

// <=== TEST CASES: s21_memchr ===>

START_TEST(tc001_memchr) {
  s21_size_t n = 12;
  void *str = "Hello there.";
  char ch = 'l';
  ck_assert_pstr_eq(memchr(str, ch, n), s21_memchr(str, ch, n));
}
END_TEST

START_TEST(tc002_memchr) {
  s21_size_t n = 2;
  void *str = "Hello there.";
  char ch = 't';
  ck_assert_pstr_eq(memchr(str, ch, n), s21_memchr(str, ch, n));
}
END_TEST

START_TEST(tc003_memchr) {
  s21_size_t n = 20;
  void *str = "Hello there.";
  char ch = 'u';
  ck_assert_pstr_eq(memchr(str, ch, n), s21_memchr(str, ch, n));
}
END_TEST

// <=== TEST CASES: s21_memcmp ===>

START_TEST(tc004_memcmp) {
  s21_size_t n = 12;
  void *str1 = "Hello there.";
  void *str2 = "Hello there.";
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(tc005_memcmp) {
  s21_size_t n = 8;
  void *str1 = "Don't underestimate my power!";
  void *str2 = "Don't try it.";
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

// <=== TEST CASES: s21_memcpy ===>

START_TEST(tc006_memcpy) {
  s21_size_t n = 15;
  char buf[16] = {0};
  char s21_buf[16] = {0};
  char src[16] = "General Kenobi.";
  ck_assert_pstr_eq(memcpy(buf, src, n), s21_memcpy(s21_buf, src, n));
}
END_TEST

START_TEST(tc007_memcpy) {
  s21_size_t n = 5;
  char buf[16] = "Hello there.";
  char s21_buf[16] = "Hello there.";
  char src[16] = "There";
  ck_assert_pstr_eq(memcpy(buf, src, n), s21_memcpy(s21_buf, src, n));
}
END_TEST

START_TEST(tc008_memcpy) {
  s21_size_t n = 7;
  char buf[32] = "Hello   Kenobi. General";
  char s21_buf[32] = "Hello   Kenobi. General";
  ck_assert_pstr_eq(memcpy(buf, buf + 16, n),
                    s21_memcpy(s21_buf, s21_buf + 16, n));
}
END_TEST

// <=== TEST CASES: s21_memmove ===>

START_TEST(tc009_memmove) {
  s21_size_t n = 4;
  char buf[64] = "It's over Anakin, I have the high ground.";
  char s21_buf[64] = "It's over Anakin, I have the high ground.";
  ck_assert_pstr_eq(memmove(buf, buf + 5, n),
                    s21_memmove(s21_buf, s21_buf + 5, n));
}
END_TEST

START_TEST(tc010_memmove) {
  s21_size_t n = 32;
  char buf[64] = "It's over Anakin, I have the high ground.";
  char s21_buf[64] = "It's over Anakin, I have the high ground.";
  ck_assert_pstr_eq(memmove(buf, buf + 5, n),
                    s21_memmove(s21_buf, s21_buf + 5, n));
}
END_TEST

START_TEST(tc011_memmove) {
  s21_size_t n = 10;
  char buf[64] = "It's over Anakin, I have the high ground.";
  char s21_buf[64] = "It's over Anakin, I have the high ground.";
  ck_assert_pstr_eq(memmove(buf + 5, buf, n),
                    s21_memmove(s21_buf + 5, s21_buf, n));
}
END_TEST

// <=== TEST CASES: s21_memset ===>

START_TEST(tc015_memset) {
  s21_size_t n = 12;
  char ch = '\0';
  char str[100] = "sdsdf";
  ck_assert_str_eq(memset(str, ch, n), s21_memset(str, ch, n));
}
END_TEST

START_TEST(tc016_memset) {
  s21_size_t n = 12;
  char ch = 'r';
  char str[100] = "sdsdf";
  ck_assert_str_eq(memset(str, ch, n), s21_memset(str, ch, n));
}
END_TEST

START_TEST(tc017_memset) {
  s21_size_t n = 12;
  char ch = '\0';
  char str_1[100] = "sdsdf";
  char str_2[100] = "sdsdf";
  ck_assert_str_eq(memset(str_1, ch, n), s21_memset(str_2, ch, n));
  ck_assert_pstr_eq(memset(str_1, ch, n), s21_memset(str_2, ch, n));
}
END_TEST

// <=== TEST CASES: s21_strcat ===>

START_TEST(tc018_strcat) {
  char dest[100] = "Hello ";
  char str[100] = "world!";
  ck_assert_str_eq(strcat(dest, str), s21_strcat(dest, str));
}
END_TEST

START_TEST(tc019_strcat) {
  char dest[100] = "Hello ";
  char str[100] = "world!";
  ck_assert_str_eq(strcat(dest, str), s21_strcat(dest, str));
}
END_TEST

START_TEST(tc020_strcat) {
  char dest[100] = "Hello ";
  char str[100] = "wor\n\tld!";
  ck_assert_str_eq(strcat(dest, str), s21_strcat(dest, str));
}
END_TEST

START_TEST(tc021_strcat) {
  char dest[100] = "Hello ";
  char str[100] = "";
  ck_assert_str_eq(strcat(dest, str), s21_strcat(dest, str));
}
END_TEST

// <=== TEST CASES: s21_strncat ===>

START_TEST(tc022_strncat) {
  s21_size_t n = 2;
  char dest[100] = "Hello ";
  char str[100] = "world!";
  char dest1[100] = "Hello ";
  ck_assert_str_eq(strncat(dest, str, n), s21_strncat(dest1, str, n));
}
END_TEST

START_TEST(tc023_strncat) {
  s21_size_t n = 3;
  char dest[100] = "Hello ";
  char str[100] = "world!";
  char dest1[100] = "Hello ";
  ck_assert_str_eq(strncat(dest, str, n), s21_strncat(dest1, str, n));
}
END_TEST

START_TEST(tc024_strncat) {
  s21_size_t n = 3;
  char dest[100] = "";
  char str[100] = "world!";
  char dest1[100] = "";
  ck_assert_str_eq(strncat(dest, str, n), s21_strncat(dest1, str, n));
}
END_TEST

START_TEST(tc025_strncat) {
  s21_size_t n = 3;
  char dest[100] = "";
  char str[100] = "HELLo";
  char dest1[100] = "";
  ck_assert_str_eq(strncat(dest, str, n), s21_strncat(dest1, str, n));
}
END_TEST

// <=== TEST CASES: s21_strchr ===>

START_TEST(tc026_strchr) {
  char chr = 'o';
  char str[100] = "HELLo";
  ck_assert_pstr_eq(strchr(str, chr), s21_strchr(str, chr));
}
END_TEST

START_TEST(tc027_strchr) {
  char chr = '1';
  char str[100] = "HELLo";
  ck_assert_pstr_eq(strchr(str, chr), s21_strchr(str, chr));
}
END_TEST

START_TEST(tc028_strchr) {
  char chr = '\0';
  char str[] = "HELLo";
  ck_assert_pstr_eq(strchr(str, chr), s21_strchr(str, chr));
}
END_TEST

// <=== TEST CASES: s21_strcmp ===>

START_TEST(tc029_strcmp) {
  char str1[30] = "S21_SCHOOL";
  char str2[30] = "S21_SCHOOL";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

START_TEST(tc030_strcmp) {
  char str1[30] = "S21_SCHOOL";
  char str2[30] = "S21_SChool";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

START_TEST(tc031_strcmp) {
  char str1[30] = "S21_\nSCHOOL";
  char str2[30] = "S21_\nSCHOOL";
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

// <=== TEST CASES: s21_strncmp ===>

START_TEST(tc032_strncmp) {
  s21_size_t n = 5;
  char str1[30] = "S21_SCHOOL";
  char str2[30] = "S21_SCHOOL";
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(tc033_strncmp) {
  s21_size_t n = 5;
  char str1[30] = "S21_SCHOOL   ";
  char str2[30] = "S21 _SCHOOL";
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(tc034_strncmp) {
  s21_size_t n = 5;
  char str1[30] = "S21 _SCHOOL";
  char str2[30] = "S21_SCHOOL";
  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

// <=== TEST CASES: s21_strcpy ===>

START_TEST(tc035_strcpy) {
  char dest1[30] = "S21_SCHOOL";
  char dest2[30] = "S21_SCHOOL";
  char str[30] = "Is back!";
  ck_assert_str_eq(strcpy(dest1, str), s21_strcpy(dest2, str));
}
END_TEST

START_TEST(tc036_strcpy) {
  char dest1[30] = "S21_SCHOOL";
  char dest2[30] = "S21_SCHOOL";
  char str[30] = "Is back! Is hard....";
  ck_assert_str_eq(strcpy(dest1, str), s21_strcpy(dest2, str));
}
END_TEST

START_TEST(tc037_strcpy) {
  char dest1[30] = "";
  char dest2[30] = "";
  char str[30] = "Is back! Is hard....";
  ck_assert_str_eq(strcpy(dest1, str), s21_strcpy(dest2, str));
}
END_TEST

// <=== TEST CASES: s21_strncpy ===>

START_TEST(tc038_strncpy) {
  s21_size_t n = 9;
  char dest1[30] = "S21_SCHOOL";
  char dest2[30] = "S21_SCHOOL";
  char str[30] = "Is back!";
  ck_assert_str_eq(strncpy(dest1, str, n), s21_strncpy(dest2, str, n));
}
END_TEST

START_TEST(tc039_strncpy) {
  s21_size_t n = 1;
  char dest1[30] = "S21_SCHOOL";
  char dest2[30] = "S21_SCHOOL";
  char str[30] = "Is back!";
  ck_assert_str_eq(strncpy(dest1, str, n), s21_strncpy(dest2, str, n));
}
END_TEST

START_TEST(tc040_strncpy) {
  s21_size_t n = 5;
  char dest1[30] = "";
  char dest2[30] = "";
  char str[30] = "Is back!";
  ck_assert_str_eq(strncpy(dest1, str, n), s21_strncpy(dest2, str, n));
}
END_TEST

// <=== TEST CASES: s21_strcspn ===>

START_TEST(tc041_strcspn) {
  char str1[30] = "S21_SCHOOL";
  char str2[30] = "S21_SCHOOL";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(tc042_strcspn) {
  char str1[30] = "S21_SCHOOL";
  char str2[30] = "L";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

START_TEST(tc043_strcspn) {
  char str1[30] = "S21_SCHOOL";
  char str2[30] = "ak47";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
}
END_TEST

// <=== TEST CASES: s21_strerror ===>

START_TEST(tc044_strerror) {
  int err = 0;
  ck_assert_str_eq(strerror(err), s21_strerror(err));
}
END_TEST

START_TEST(tc045_strerror) {
  int err = 60;
  ck_assert_str_eq(strerror(err), s21_strerror(err));
}
END_TEST

START_TEST(tc046_strerror) {
  int err = 300;
  ck_assert_str_eq(strerror(err), s21_strerror(err));
}
END_TEST

START_TEST(tc047_strerror) {
  int err = -1000;
  ck_assert_str_eq(strerror(err), s21_strerror(err));
}
END_TEST

// <=== TEST CASES: s21_strlen ===>

START_TEST(tc048_strlen) {
  char str[100] = "";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(tc049_strlen) {
  char str[100] = "Hello world!";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(tc050_strlen) {
  char str[100] = "Hello \0\t\nworld!";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

// <=== TEST CASES: s21_strpbrk ===>

START_TEST(tc051_strpbrk) {
  char str1[] = "Hello world";
  char str2[] = "W";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(tc052_strpbrk) {
  char str1[] = "HELLO WORLD";
  char str2[] = "C";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(tc053_strpbrk) {
  char str1[] = "";
  char str2[] = "";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

// <=== TEST CASES: s21_strrchr ===>

START_TEST(tc054_strrchr) {
  char str[] = "Hello world";
  char ch = 'o';
  ck_assert_pstr_eq(s21_strrchr(str, ch), strrchr(str, ch));
}
END_TEST

START_TEST(tc055_strrchr) {
  char str[] = "Hello world";
  char ch = '\0';
  ck_assert_pstr_eq(s21_strrchr(str, ch), strrchr(str, ch));
}
END_TEST

START_TEST(tc056_strrchr) {
  char str[] = "Hello world";
  char ch = 'W';
  ck_assert_pstr_eq(s21_strrchr(str, ch), strrchr(str, ch));
}
END_TEST

// <=== TEST CASES: s21_strspn ===>

START_TEST(tc057_strspn) {
  char str1[] = "";
  char str2[] = "";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(tc058_strspn) {
  char str1[] = "Hello world!";
  char str2[] = "";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(tc059_strspn) {
  char str1[] = "Hi";
  char str2[] = "HiHi";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

// <=== TEST CASES: s21_strstr ===>

START_TEST(tc060_strstr) {
  char str1[] = "HELLO world";
  char str2[] = "world";
  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(tc061_strstr) {
  char str1[] = "Hello world";
  char str2[] = "world ";
  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

START_TEST(tc062_strstr) {
  char str1[] = "Hello world";
  char str2[] = "";
  ck_assert_pstr_eq(s21_strstr(str1, str2), strstr(str1, str2));
}
END_TEST

// <=== TEST CASES: s21_strtok ===>

START_TEST(tc063_strtok) {
  char str1[] = "Hello/world/!!!";
  char str2[] = "Hello/world/!!!";
  char del[] = "/";
  char *ch1 = strtok(str1, del);
  char *ch2 = s21_strtok(str2, del);
  while (ch1 != s21_NULL) {
    ck_assert_pstr_eq(ch1, ch2);
    ch1 = strtok(s21_NULL, del);
    ch2 = s21_strtok(s21_NULL, del);
  }
}
END_TEST

START_TEST(tc064_strtok) {
  char str1[] = "Hello/world/!!!";
  char str2[] = "Hello/world/!!!";
  char del[] = "";
  char *ch1 = strtok(str1, del);
  char *ch2 = s21_strtok(str2, del);
  while (ch1 != s21_NULL) {
    ck_assert_pstr_eq(ch1, ch2);
    ch1 = strtok(s21_NULL, del);
    ch2 = s21_strtok(s21_NULL, del);
  }
}
END_TEST

START_TEST(tc065_strtok) {
  char str1[] = ". Hello /world/!!! ";
  char str2[] = ". Hello /world/!!! ";
  char del[] = ". ";

  char *ch1 = strtok(str1, del);
  char *ch2 = s21_strtok(str2, del);
  while (ch1 != s21_NULL) {
    ck_assert_pstr_eq(ch1, ch2);
    ch1 = strtok(s21_NULL, del);
    ch2 = s21_strtok(s21_NULL, del);
  }
}
END_TEST

START_TEST(tc066_strtok) {
  char str1[] = ". Hello /world/!!! ";
  char str2[] = ". Hello /world/!!! ";
  char del[] = "1";

  char *ch1 = strtok(str1, del);
  char *ch2 = s21_strtok(str2, del);
  ck_assert_pstr_eq(ch1, ch2);
  while (ch1 != s21_NULL) {
    ck_assert_pstr_eq(ch1, ch2);
    ch1 = strtok(s21_NULL, del);
    ch2 = s21_strtok(s21_NULL, del);
  }
  ck_assert_pstr_eq(ch1, ch2);
}
END_TEST

START_TEST(tc067_strtok) {
  char str1[] = ". Hello /world/!!! ";
  char str2[] = ". Hello /world/!!! ";
  char del[] = ". ";

  char *ch1 = strtok(str1, del);
  char *ch2 = s21_strtok(str2, del);
  ck_assert_pstr_eq(ch1, ch2);
  while (ch1 != s21_NULL) {
    ck_assert_pstr_eq(ch1, ch2);
    ch1 = strtok(s21_NULL, del);
    ch2 = s21_strtok(s21_NULL, del);
  }
  ck_assert_pstr_eq(ch1, ch2);
}

// <=== TEST CASES: s21_sscanf ===>

START_TEST(tc_sscanf_simpliest) {
  char *format = "%d";
  char *str = "95";
  int digit = 0;
  int s21_digit = 0;

  int res = sscanf(str, format, &digit);
  int s21_res = s21_sscanf(str, format, &s21_digit);
  ck_assert_int_eq(res, s21_res);
  ck_assert_int_eq(digit, s21_digit);
}
END_TEST

START_TEST(tc_sscanf_suppress) {
  char *format = "%*d:%d";
  char *str = "16:16";
  int digit = 0;
  int s21_digit = 0;

  int res = sscanf(str, format, &digit);
  int s21_res = s21_sscanf(str, format, &s21_digit);
  ck_assert_int_eq(res, s21_res);
  ck_assert_int_eq(digit, s21_digit);
}
END_TEST

START_TEST(tc_sscanf_non_matching_char_in_between) {
  char *format = "%c&%c";
  char *str = "m*m";
  char m1 = 0, m2 = 0;
  char s21_m1 = 0, s21_m2 = 0;

  int res = sscanf(str, format, &m1, &m2);
  int s21_res = s21_sscanf(str, format, &s21_m1, &s21_m2);
  ck_assert_int_eq(res, s21_res);
  ck_assert_int_eq(m1, s21_m1);
  ck_assert_int_eq(m2, s21_m2);
}
END_TEST

START_TEST(tc_sscanf_matching_substr_in_between) {
  char *format = "%c__hello__%c";
  char *str = "m__hello__m";
  char m1 = 0, m2 = 0;
  char s21_m1 = 0, s21_m2 = 0;

  int res = sscanf(str, format, &m1, &m2);
  int s21_res = s21_sscanf(str, format, &s21_m1, &s21_m2);
  ck_assert_int_eq(res, s21_res);
  ck_assert_int_eq(m1, s21_m1);
  ck_assert_int_eq(m2, s21_m2);
}
END_TEST

START_TEST(tc_sscanf_matching_substr_in_between_with_suppress) {
  char *format = "%*c__hello__%c";
  char *str = "m__hello__m";
  char m = 0;
  char s21_m = 0;

  int res = sscanf(str, format, &m);
  int s21_res = s21_sscanf(str, format, &s21_m);
  ck_assert_int_eq(res, s21_res);
  ck_assert_int_eq(m, s21_m);
}
END_TEST

START_TEST(tc_sscanf_simple_width) {
  char *format = "%3d";
  char *str = "1237";
  int d123 = 0;
  int s21_d123 = 0;

  int res = sscanf(str, format, &d123);
  int s21_res = s21_sscanf(str, format, &s21_d123);
  ck_assert_int_eq(res, s21_res);
  ck_assert_int_eq(d123, s21_d123);
}
END_TEST

START_TEST(tc_sscanf_wchars) {
  char *format = "%lc%lc";
  char *str = "wq";
  wchar_t ch1 = 0, ch2 = 0;
  wchar_t s21_ch1 = 0, s21_ch2 = 0;

  int res = sscanf(str, format, &ch1, &ch2);
  int s21_res = s21_sscanf(str, format, &s21_ch1, &s21_ch2);
  ck_assert_int_eq(res, s21_res);
  ck_assert_int_eq(ch1, s21_ch1);
  ck_assert_int_eq(ch2, s21_ch2);
}
END_TEST

START_TEST(tc_sscanf_simple_short) {
  char *format = "%hd";
  char *str = "255";
  short digit = 0;
  short s21_digit = 0;

  int res = sscanf(str, format, &digit);
  int s21_res = s21_sscanf(str, format, &s21_digit);
  ck_assert_int_eq(res, s21_res);
  ck_assert_int_eq(digit, s21_digit);
}
END_TEST

START_TEST(tc_sscanf_simple_short_short) {
  char *format = "%hhd";
  char *str = "255";
  char digit = 0;
  char s21_digit = 0;

  int res = sscanf(str, format, &digit);
  int s21_res = s21_sscanf(str, format, &s21_digit);
  ck_assert_int_eq(res, s21_res);
  ck_assert_int_eq(digit, s21_digit);
}
END_TEST

START_TEST(tc_sscanf_simple_long) {
  char *format = "%ld";
  char *str = "2147483647";
  long digit = 0;
  long s21_digit = 0;

  int res = sscanf(str, format, &digit);
  int s21_res = s21_sscanf(str, format, &s21_digit);
  ck_assert_int_eq(res, s21_res);
  ck_assert_int_eq(digit, s21_digit);
}
END_TEST

START_TEST(tc_sscanf_simple_longlong) {
  char *format = "%lld";
  char *str = "9223372036854775807";
  long long digit = 0;
  long long s21_digit = 0;

  int res = sscanf(str, format, &digit);
  int s21_res = s21_sscanf(str, format, &s21_digit);
  ck_assert_int_eq(res, s21_res);
  ck_assert_int_eq(digit, s21_digit);
}
END_TEST

START_TEST(tc_sscanf_simple_i_spec) {
  char *format = "%i";
  char *str = "067";
  int digit = 0;
  int s21_digit = 0;

  int res = sscanf(str, format, &digit);
  int s21_res = s21_sscanf(str, format, &s21_digit);
  ck_assert_int_eq(res, s21_res);
  ck_assert_int_eq(digit, s21_digit);
}
END_TEST

START_TEST(tc_sscanf_hex_i_spec) {
  char *format = "%i";
  char *str = "0x67";
  int digit = 0;
  int s21_digit = 0;

  int res = sscanf(str, format, &digit);
  int s21_res = s21_sscanf(str, format, &s21_digit);
  ck_assert_int_eq(res, s21_res);
  ck_assert_int_eq(digit, s21_digit);
}
END_TEST

START_TEST(tc_sscanf_simple_octal) {
  char *format = "%o";
  char *str = "67";
  int digit = 0;
  int s21_digit = 0;

  int res = sscanf(str, format, &digit);
  int s21_res = s21_sscanf(str, format, &s21_digit);
  ck_assert_int_eq(res, s21_res);
  ck_assert_int_eq(digit, s21_digit);
}
END_TEST

START_TEST(tc_sscanf_bad_octal) {
  char *format = "%o";
  char *str = "697";
  int digit = 0;
  int s21_digit = 0;

  int res = sscanf(str, format, &digit);
  int s21_res = s21_sscanf(str, format, &s21_digit);
  ck_assert_int_eq(res, s21_res);
  ck_assert_int_eq(digit, s21_digit);
}
END_TEST

START_TEST(tc_sscanf_simple_string) {
  char *format = "%s";
  char *src = "Hello there";
  char str[32] = {0};
  char s21_str[32] = {0};

  int res = sscanf(src, format, str);
  int s21_res = s21_sscanf(src, format, s21_str);
  ck_assert_int_eq(res, s21_res);
  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(tc_sscanf_two_strings) {
  char *format = "%*s%s";
  char *src = "Hello there";
  char str[32] = {0};
  char s21_str[32] = {0};

  int res = sscanf(src, format, str);
  int s21_res = s21_sscanf(src, format, s21_str);
  ck_assert_int_eq(res, s21_res);
  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(tc_sscanf_suppress_and_width_string) {
  char *format = "%*s%3s";
  char *src = "Hello there";
  char str[32] = {0};
  char s21_str[32] = {0};

  int res = sscanf(src, format, str);
  int s21_res = s21_sscanf(src, format, s21_str);
  ck_assert_int_eq(res, s21_res);
  ck_assert_str_eq(str, s21_str);
}
END_TEST

START_TEST(tc_sscanf_simple_unsigned) {
  char *format = "%u";
  char *str = "337";
  int digit = 0;
  int s21_digit = 0;

  int res = sscanf(str, format, &digit);
  int s21_res = s21_sscanf(str, format, &s21_digit);
  ck_assert_int_eq(res, s21_res);
  ck_assert_int_eq(digit, s21_digit);
}
END_TEST

START_TEST(tc_sscanf_unsigned_long) {
  char *format = "%lu";
  char *str = "4294967295";
  unsigned long digit = 0;
  unsigned long s21_digit = 0;

  int res = sscanf(str, format, &digit);
  int s21_res = s21_sscanf(str, format, &s21_digit);
  ck_assert_int_eq(res, s21_res);
  ck_assert_int_eq(digit, s21_digit);
}
END_TEST

START_TEST(tc_sscanf_unsigned_longlong) {
  char *format = "%llu";
  char *str = "18446744073709551615";
  unsigned long long digit = 0;
  unsigned long long s21_digit = 0;

  int res = sscanf(str, format, &digit);
  int s21_res = s21_sscanf(str, format, &s21_digit);
  ck_assert_int_eq(res, s21_res);
  ck_assert_int_eq(digit, s21_digit);
}
END_TEST

START_TEST(tc_sscanf_simple_hex) {
  char *format = "%x";
  char *str = "fff";
  int digit = 0;
  int s21_digit = 0;

  int res = sscanf(str, format, &digit);
  int s21_res = s21_sscanf(str, format, &s21_digit);
  ck_assert_int_eq(res, s21_res);
  ck_assert_int_eq(digit, s21_digit);
}
END_TEST

START_TEST(tc_sscanf_hex_long) {
  char *format = "%lx";
  char *str = "fff";
  long digit = 0;
  long s21_digit = 0;

  int res = sscanf(str, format, &digit);
  int s21_res = s21_sscanf(str, format, &s21_digit);
  ck_assert_int_eq(res, s21_res);
  ck_assert_int_eq(digit, s21_digit);
}
END_TEST

START_TEST(tc_sscanf_hex_longlong) {
  char *format = "%llx";
  char *str = "fffffffffff";
  long long digit = 0;
  long long s21_digit = 0;

  int res = sscanf(str, format, &digit);
  int s21_res = s21_sscanf(str, format, &s21_digit);
  ck_assert_int_eq(res, s21_res);
  ck_assert_int_eq(digit, s21_digit);
}
END_TEST

START_TEST(tc_sscanf_hex_short) {
  char *format = "%hx";
  char *str = "feed";
  long long digit = 0;
  long long s21_digit = 0;

  int res = sscanf(str, format, &digit);
  int s21_res = s21_sscanf(str, format, &s21_digit);
  ck_assert_int_eq(res, s21_res);
  ck_assert_int_eq(digit, s21_digit);
}
END_TEST

START_TEST(tc_sscanf_bad_hex) {
  char *format = "%x";
  char *str = "not_a_hex";
  long long digit = 0;
  long long s21_digit = 0;

  int res = sscanf(str, format, &digit);
  int s21_res = s21_sscanf(str, format, &s21_digit);
  ck_assert_int_eq(res, s21_res);
  ck_assert_int_eq(digit, s21_digit);
}
END_TEST

START_TEST(tc_sscanf_hex_cap_longlong) {
  char *format = "%llX";
  char *str = "0xFEED007";
  long long digit = 0;
  long long s21_digit = 0;

  int res = sscanf(str, format, &digit);
  int s21_res = s21_sscanf(str, format, &s21_digit);
  ck_assert_int_eq(res, s21_res);
  ck_assert_int_eq(digit, s21_digit);
}
END_TEST

START_TEST(tc_sscanf_simple_pointer) {
  char *format = "%p";
  char *str = "0x7ffeecd4b718";
  void *ptr = 0;
  void *s21_ptr = 0;

  int res = sscanf(str, format, &ptr);
  int s21_res = s21_sscanf(str, format, &s21_ptr);
  ck_assert_int_eq(res, s21_res);
  ck_assert_ptr_eq(ptr, s21_ptr);
}
END_TEST

START_TEST(tc_sscanf_signed_pointer) {
  char *format = "%p";
  char *str = "-0x7FECD4B718";
  void *ptr = 0;
  void *s21_ptr = 0;

  int res = sscanf(str, format, &ptr);
  int s21_res = s21_sscanf(str, format, &s21_ptr);
  ck_assert_int_eq(res, s21_res);
  ck_assert_ptr_eq(ptr, s21_ptr);
}
END_TEST

START_TEST(tc_sscanf_bad_pointer) {
  char *format = "%p";
  char *str = "not_a_pointer";
  void *ptr = 0;
  void *s21_ptr = 0;

  int res = sscanf(str, format, &ptr);
  int s21_res = s21_sscanf(str, format, &s21_ptr);
  ck_assert_int_eq(res, s21_res);
  ck_assert_ptr_eq(ptr, s21_ptr);
}
END_TEST

START_TEST(tc_sscanf_bytes_readed) {
  char *format = "%*s%n";
  char *str = "-0x800119dc79";
  int bytes = 0;
  int s21_bytes = 0;

  int res = sscanf(str, format, &bytes);
  int s21_res = s21_sscanf(str, format, &s21_bytes);
  ck_assert_int_eq(res, s21_res);
  ck_assert_int_eq(bytes, s21_bytes);
}
END_TEST

START_TEST(tc_sscanf_bytes_readed_short) {
  char *format = "%*s%hn";
  char *str = "-0x800119dc79";
  short bytes = 0;
  short s21_bytes = 0;

  int res = sscanf(str, format, &bytes);
  int s21_res = s21_sscanf(str, format, &s21_bytes);
  ck_assert_int_eq(res, s21_res);
  ck_assert_int_eq(bytes, s21_bytes);
}
END_TEST

START_TEST(tc_sscanf_bytes_readed_short_short) {
  char *format = "%*s%hhn";
  char *str = "-0x800119dc79";
  char bytes = 0;
  char s21_bytes = 0;

  int res = sscanf(str, format, &bytes);
  int s21_res = s21_sscanf(str, format, &s21_bytes);
  ck_assert_int_eq(res, s21_res);
  ck_assert_int_eq(bytes, s21_bytes);
}
END_TEST

START_TEST(tc_sscanf_bytes_readed_long) {
  char *format = "%*s%ln";
  char *str = "-0xfadfd800119dc79";
  long bytes = 0;
  long s21_bytes = 0;

  int res = sscanf(str, format, &bytes);
  int s21_res = s21_sscanf(str, format, &s21_bytes);
  ck_assert_int_eq(res, s21_res);
  ck_assert_int_eq(bytes, s21_bytes);
}
END_TEST

START_TEST(tc_sscanf_bytes_readed_longlong) {
  char *format = "%*s%lln";
  char *str = "-0xfadfd800119dc796789";
  long long bytes = 0;
  long long s21_bytes = 0;

  int res = sscanf(str, format, &bytes);
  int s21_res = s21_sscanf(str, format, &s21_bytes);
  ck_assert_int_eq(res, s21_res);
  ck_assert_int_eq(bytes, s21_bytes);
}
END_TEST

START_TEST(tc_sscanf_simple_float) {
  char *format = "%f";
  char *str = "22.2";
  float float_v = 0;
  float s21_float_v = 0;

  int res = sscanf(str, format, &float_v);
  int s21_res = s21_sscanf(str, format, &s21_float_v);
  ck_assert_int_eq(res, s21_res);
  ck_assert_float_eq(float_v, s21_float_v);
}
END_TEST

START_TEST(tc_sscanf_simple_double) {
  char *format = "%lf";
  char *str = "22234.2234567";
  double float_v = 0;
  double s21_float_v = 0;

  int res = sscanf(str, format, &float_v);
  int s21_res = s21_sscanf(str, format, &s21_float_v);
  ck_assert_int_eq(res, s21_res);
  ck_assert_double_eq(float_v, s21_float_v);
}
END_TEST

START_TEST(tc_sscanf_simple_long_double) {
  char *format = "%Lf";
  char *str = "2342322234.2345234567";
  long double float_v = 0;
  long double s21_float_v = 0;

  int res = sscanf(str, format, &float_v);
  int s21_res = s21_sscanf(str, format, &s21_float_v);
  ck_assert_int_eq(res, s21_res);
  ck_assert_ldouble_eq(float_v, s21_float_v);
}
END_TEST

START_TEST(tc_sscanf_pos_exponent) {
  char *format = "%lG";
  char *str = "1.2345e+5";
  double float_v = 0;
  double s21_float_v = 0;

  int res = sscanf(str, format, &float_v);
  int s21_res = s21_sscanf(str, format, &s21_float_v);
  ck_assert_int_eq(res, s21_res);
  ck_assert_double_eq(float_v, s21_float_v);
}
END_TEST

START_TEST(tc_sscanf_float_underflow) {
  char *format = "%lG";
  char *str = "1e-500000";
  double float_v = 0;
  double s21_float_v = 0;

  int res = sscanf(str, format, &float_v);
  int s21_res = s21_sscanf(str, format, &s21_float_v);
  ck_assert_int_eq(res, s21_res);
  ck_assert_double_eq(float_v, s21_float_v);
}
END_TEST

START_TEST(tc_sscanf_neg_exponent) {
  char *format = "%E";
  char *str = "0.444e-5";
  float float_v = 0;
  float s21_float_v = 0;

  int res = sscanf(str, format, &float_v);
  int s21_res = s21_sscanf(str, format, &s21_float_v);
  ck_assert_int_eq(res, s21_res);
  ck_assert_float_eq(float_v, s21_float_v);
}
END_TEST

START_TEST(tc_sscanf_inf_float) {
  char *format = "%f";
  char *str = "inf";
  float float_v = 0;
  float s21_float_v = 0;

  int res = sscanf(str, format, &float_v);
  int s21_res = s21_sscanf(str, format, &s21_float_v);
  ck_assert_int_eq(res, s21_res);
  ck_assert_float_eq(float_v, s21_float_v);
}
END_TEST

START_TEST(tc_sscanf_nan_float) {
  char *format = "%e";
  char *str = "NAN";
  float float_v = 0;
  float s21_float_v = 0;

  int res = sscanf(str, format, &float_v);
  int s21_res = s21_sscanf(str, format, &s21_float_v);
  ck_assert_int_eq(res, s21_res);
  ck_assert_float_nan(float_v);
  ck_assert_float_nan(s21_float_v);
}
END_TEST

START_TEST(tc_sscanf_nan_float_alter) {
  char *format = "%g";
  char *str = "NaN";
  float float_v = 0;
  float s21_float_v = 0;

  int res = sscanf(str, format, &float_v);
  int s21_res = s21_sscanf(str, format, &s21_float_v);
  ck_assert_int_eq(res, s21_res);
  ck_assert_float_nan(float_v);
  ck_assert_float_nan(s21_float_v);
}
END_TEST

START_TEST(tc_sscanf_spec_char) {
  char *format = "%*d%%%d";
  char *str = "21%42";
  int digit = 0;
  int s21_digit = 0;

  int res = sscanf(str, format, &digit);
  int s21_res = s21_sscanf(str, format, &s21_digit);
  ck_assert_int_eq(res, s21_res);
  ck_assert_int_eq(digit, s21_digit);
}
END_TEST

// <=== TEST CASES: s21_sprintf ===>

void makefreeArr(char *str1, char *str2, int arrsize) {
  for (int i = 0; i < arrsize; i++) {
    str1[i] = 0;
    str2[i] = 0;
  }
}

START_TEST(s21_Ssprintf_test) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};

  sprintf(str1, "%s", "Hello");
  s21_sprintf(str2, "%s", "Hello");
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%.1s", "Hello");
  s21_sprintf(str2, "%.1s", "Hello");
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%7s", "Hello");
  s21_sprintf(str2, "%7s", "Hello");
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%-10s", "Hello");
  s21_sprintf(str2, "%-10s", "Hello");
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);
}
END_TEST

START_TEST(s21_Csprintf_test) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};

  sprintf(str1, "%1c %c", 'H', 'z');
  s21_sprintf(str2, "%1c %c", 'H', 'z');
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 50);

  sprintf(str1, "%10c %2c", 'H', 'z');
  s21_sprintf(str2, "%10c %2c", 'H', 'z');
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 50);

  sprintf(str1, "%-1c %-c", 'H', 'z');
  s21_sprintf(str2, "%-1c %-c", 'H', 'z');
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 50);
}
END_TEST

START_TEST(s21_Fsprintf_test) {
  char str1[255] = {'\0'};
  char str2[255] = {'\0'};

  sprintf(str1, "%12.16f %10.17f", 100000000000.14, 100000000000.14);
  s21_sprintf(str2, "%12.16f %10.17f", 100000000000.14, 100000000000.14);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%f", 100000.4);
  s21_sprintf(str2, "%f", 100000.4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%.16f", -100000.4);
  s21_sprintf(str2, "%.16f", -100000.4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%-1f", 100000.4);
  s21_sprintf(str2, "%-1f", 100000.4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%f", -100000.4);
  s21_sprintf(str2, "%f", -100000.4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%+f %+f", -100000.4, 1000.231);
  s21_sprintf(str2, "%+f %+f", -100000.4, 1000.231);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%-20f", 100000.4);
  s21_sprintf(str2, "%-20f", 100000.4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%-+20f", 100000.4);
  s21_sprintf(str2, "%-+20f", 100000.4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%-20f", -100000.4);
  s21_sprintf(str2, "%-20f", -100000.4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%+20f", 100000.4);
  s21_sprintf(str2, "%+20f", 100000.4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%+20f", -100000.4);
  s21_sprintf(str2, "%+20f", -100000.4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  float key = 10000;
  sprintf(str1, "%+20f", key);
  s21_sprintf(str2, "%+20f", key);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  int r2 = sprintf(str2, "%+34.10f%.10i%15.1d%25.10s", 25.3456, 1234, 4567,
                   "HELLOMYDEARFRIEND");
  int r1 = s21_sprintf(str1, "%+34.10f%.10i%15.1d%25.10s", 25.3456, 1234, 4567,
                       "HELLOMYDEARFRIEND");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r2, r1);
  makefreeArr(str1, str2, 255);
}
END_TEST

START_TEST(s21_IDsprintf_test) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};

  sprintf(str1, "%.d", 4);
  s21_sprintf(str2, "%.d", 4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 30);

  sprintf(str1, "%.10d%%\n", 4);
  s21_sprintf(str2, "%.10d%%\n", 4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 30);

  sprintf(str1, "%d%%\n", -4);
  s21_sprintf(str2, "%d%%\n", -4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 30);

  sprintf(str1, "%-+10d%%\n", 4);
  s21_sprintf(str2, "%-+10d%%\n", 4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 30);

  sprintf(str1, "%-10d%%\n", -4);
  s21_sprintf(str2, "%-10d%%\n", -4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 30);

  sprintf(str1, "%+10d%%\n", 4);
  s21_sprintf(str2, "%+10d%%\n", 4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 30);

  sprintf(str1, "%+10d%%\n", -4);
  s21_sprintf(str2, "%+10d%%\n", -4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 30);

  sprintf(str1, "%+10.5d%%\n", -4);
  s21_sprintf(str2, "%+10.5d%%\n", -4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 30);

  long int var_long = 100;
  sprintf(str1, "%ld%%\n", var_long);
  s21_sprintf(str2, "%ld%%\n", var_long);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 30);

  short var_short = 123;
  sprintf(str1, "%hd%%\n", var_short);
  s21_sprintf(str2, "%hd%%\n", var_short);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 30);

  int r2 = sprintf(str2, "%+-25.3d%25.15d%10.f%15d", 252, 243, 256.34, 15);
  int r1 = s21_sprintf(str1, "%+-25.3d%25.15d%10.f%15d", 252, 243, 256.34, 15);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r2, r1);
  makefreeArr(str1, str2, 150);

  sprintf(str1, "%.i", 4);
  s21_sprintf(str2, "%.i", 4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 30);

  sprintf(str1, "%.10i%%\n", 4);
  s21_sprintf(str2, "%.10i%%\n", 4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 30);

  sprintf(str1, "% i%%\n", -4);
  s21_sprintf(str2, "% i%%\n", -4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 30);

  sprintf(str1, "%-+10i%%\n", 4);
  s21_sprintf(str2, "%-+10i%%\n", 4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 30);

  sprintf(str1, "%-10i%%\n", -4);
  s21_sprintf(str2, "%-10i%%\n", -4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 30);

  sprintf(str1, "%+10i\n", 4);
  s21_sprintf(str2, "%+10i\n", 4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 30);

  sprintf(str1, "%+10i\n", -4);
  s21_sprintf(str2, "%+10i\n", -4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 30);

  sprintf(str1, "%+10.5i\n", -4);
  s21_sprintf(str2, "%+10.5i\n", -4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 30);

  sprintf(str1, "%li%%\n", var_long);
  s21_sprintf(str2, "%li%%\n", var_long);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 30);
}
END_TEST

START_TEST(s21_Usprintf_test) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};

  sprintf(str1, "%2.5u%%\n", 4);
  s21_sprintf(str2, "%2.5u%%\n", 4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%2.5u%%\n", -4);
  s21_sprintf(str2, "%2.5u%%\n", -4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%10.5u%%\n", 4);
  s21_sprintf(str2, "%10.5u%%\n", 4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%-10u%%\n", 421);
  s21_sprintf(str2, "%-10u%%\n", 421);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  short unsigned key_h = 421;
  sprintf(str1, "%-10hu%%\n", key_h);
  s21_sprintf(str2, "%-10hu%%\n", key_h);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  long unsigned key_l = 421;
  sprintf(str1, "%-10lu%%\n", key_l);
  s21_sprintf(str2, "%-10lu%%\n", key_l);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);
  char c[255] = {'\0'}, d[255] = {'\0'};
  s21_sprintf(c, "%10.s %10ls %-10ls %-3ls %.ls %.3ls %.10ls", "hello",
              L"hello", L"hello", L"hello", L"hello", L"hello", L"hello");
  sprintf(d, "%10.s %10ls %-10ls %-3ls %.ls %.3ls %.10ls", "hello", L"hello",
          L"hello", L"hello", L"hello", L"hello", L"hello");
  ck_assert_str_eq(c, d);
  makefreeArr(c, d, 100);
}
END_TEST

START_TEST(s21_eEsprintf_test) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  long double val = 15.35;
  long double val1 = 15.0000035;
  long double val2 = 15.00000000000000035;
  long double val3 = -15.35;

  sprintf(str1, "%#.16Le\n", val);
  s21_sprintf(str2, "%#.16Le\n", val);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%.0Le\n", val);
  s21_sprintf(str2, "%.0Le\n", val);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%.Le\n", val1);
  s21_sprintf(str2, "%.Le\n", val1);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%.15Le\n", val2);
  s21_sprintf(str2, "%.15Le\n", val2);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%10.16Le\n", val3);
  s21_sprintf(str2, "%10.16Le\n", val3);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%+10.6Le\n", val3);
  s21_sprintf(str2, "%+10.6Le\n", val3);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%-+*.*e\n", 10, 1, 15.01);
  s21_sprintf(str2, "%-+*.*e\n", 10, 1, 15.01);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%.16LE\n", val);
  s21_sprintf(str2, "%.16LE\n", val);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%.0LE\n", val);
  s21_sprintf(str2, "%.0LE\n", val);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%.LE\n", val1);
  s21_sprintf(str2, "%.LE\n", val1);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%.15LE\n", val2);
  s21_sprintf(str2, "%.15LE\n", val2);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%10.16LE\n", val3);
  s21_sprintf(str2, "%10.16LE\n", val3);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%+10.6LE\n", val3);
  s21_sprintf(str2, "%+10.6LE\n", val3);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%-+#*.*E\n", 10, 1, 15.01);
  s21_sprintf(str2, "%-+#*.*E\n", 10, 1, 15.01);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);
}
END_TEST

START_TEST(s21_Osprintf_test) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};

  sprintf(str1, "%#2.5o%%\n", 4);
  s21_sprintf(str2, "%#2.5o%%\n", 4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%#2.5o%%\n", -4);
  s21_sprintf(str2, "%#2.5o%%\n", -4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%10.5o%%\n", 4);
  s21_sprintf(str2, "%10.5o%%\n", 4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%-10o%%\n", 421);
  s21_sprintf(str2, "%-10o%%\n", 421);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  short unsigned key_h = 421;
  sprintf(str1, "%-10ho%%\n", key_h);
  s21_sprintf(str2, "%-10ho%%\n", key_h);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  long unsigned key_l = 421;
  sprintf(str1, "%#-10lo%%\n", key_l);
  s21_sprintf(str2, "%-#10lo%%\n", key_l);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);
}
END_TEST

START_TEST(s21_xXsprintf_test) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};

  sprintf(str1, "%2.5x%%\n", 4);
  s21_sprintf(str2, "%2.5x%%\n", 4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%2.5x%%\n", -4);
  s21_sprintf(str2, "%2.5x%%\n", -4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%10.5x%%\n", 4);
  s21_sprintf(str2, "%10.5x%%\n", 4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%-10x%%\n", 421);
  s21_sprintf(str2, "%-10x%%\n", 421);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  short unsigned key_h = 421;
  sprintf(str1, "%-10hx%%\n", key_h);
  s21_sprintf(str2, "%-10hx%%\n", key_h);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  long unsigned key_l = 421;
  sprintf(str1, "%#-10lx%%\n", key_l);
  s21_sprintf(str2, "%-#10lx%%\n", key_l);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%2.5X%%\n", 4);
  s21_sprintf(str2, "%2.5X%%\n", 4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%2.5X%%\n", -4);
  s21_sprintf(str2, "%2.5X%%\n", -4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%10.5X%%\n", 4);
  s21_sprintf(str2, "%10.5X%%\n", 4);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%#-10X%%\n", 421);
  s21_sprintf(str2, "%#-10X%%\n", 421);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%-10hX%%\n", key_h);
  s21_sprintf(str2, "%-10hX%%\n", key_h);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  sprintf(str1, "%-10lX%%\n", key_l);
  s21_sprintf(str2, "%-10lX%%\n", key_l);
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);
}
END_TEST

START_TEST(s21_Psprintf_test) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};

  char *format = "%p";
  ck_assert_int_eq(sprintf(str1, format, format),
                   s21_sprintf(str2, format, format));
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  format = "%15p";
  ck_assert_int_eq(sprintf(str1, format, format),
                   s21_sprintf(str2, format, format));
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);

  format = "%.5p";
  ck_assert_int_eq(sprintf(str1, format, format),
                   s21_sprintf(str2, format, format));
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);
}
END_TEST

START_TEST(s21_Nsprintf_test) {
  char str1[100] = {'\0'};
  char str2[100] = {'\0'};
  int ptr = 0;
  char *format = "Hello\n asd%n\n";
  ck_assert_int_eq(sprintf(str1, format, &ptr),
                   s21_sprintf(str2, format, &ptr));
  ck_assert_str_eq(str1, str2);
  makefreeArr(str1, str2, 100);
}
END_TEST

/* ------===== This part for testing sprintf and sscanf =====------ */
/* ------=====                   START                  =====------ */

// sprintf ->

START_TEST(sprintf_simple_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple value %d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_precise_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%5d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_minus_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_plus_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+12d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_padding_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%012i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_star_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0*d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_star_precision_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0.*i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_many_flags_many_ints) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char format[] = "%0.*i %d %4.*i %013d %d";
  int val = 69;
  ck_assert_int_eq(
      s21_sprintf(str1, format, 5, val, -10431, 13, 5311, 0, -581813581),
      sprintf(str2, format, 5, val, -10431, 13, 5311, 0, -581813581));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_flags_long_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+5.31li";
  long int val = 698518581899;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_flags_short_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16.9hi";
  short int val = 6958;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_flags_another_long_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0.*ld";
  long val = 8581385185;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_zero_precision_zero_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.0d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_space_flag_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% 5.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hu";
  unsigned short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lu";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lu, %u, %hu, %.5u, %5.u";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%o";
  ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_hash) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#o";
  int val = 57175;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hd";
  short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo";
  long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo, %o, %ho, %.5o, %5.o";
  long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo";
  long int val = 84518;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, 0),
                   sprintf(str2, format, (unsigned)0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.15x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-10x%x%X%#x%#X%5.5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val, val, val, val, val),
                   sprintf(str2, format, val, val, val, val, val, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-5.10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#x";
  unsigned val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#x";
  unsigned val = 18571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#hx";
  unsigned short val = 12352;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#lx";
  unsigned long val = 18571757371571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_one_longer_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#2x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_two_longer_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#30x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%c";
  char val = 'X';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_one_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% -5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.3c%c%c%c%c Hello! ABOBA";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                   sprintf(str2, format, val, 'c', 'a', 'b', 'b'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.3c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.15s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-15.9s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s%s%s%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  char *s1 = "";
  char *s2 = "87418347813748913749871389480913";
  char *s3 = "HAHAABOBASUCKER";
  ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                   sprintf(str2, format, val, s1, s2, s3));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ptr) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ptr_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ptr_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_null_ptr) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%p";
  char *ptr = s21_NULL;
  ck_assert_int_eq(s21_sprintf(str1, format, ptr), sprintf(str2, format, ptr));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_width_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *val = "kjafdiuhfjahfjdahf";
  char *format = "%120s";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_n_specifier) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int ret = 0;
  char *format = "Hello, my sexy little aboba abobushka abobina %n";
  ck_assert_int_eq(s21_sprintf(str1, format, &ret),
                   sprintf(str2, format, &ret));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Lf";
  long double val = 513515.131513515151351;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%10Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.0Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision_huge_negative) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Lf";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Lf";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% f";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% .0f %.lf %Lf %f %lf %Lf";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 9851.51351;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_precision_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.0Le";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_precision_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.Le";
  long double val = 15.000009121;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_e_precision_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Le";
  long double val = 0.000000000000000123;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_precision_huge_negative) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Le";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Le";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%015E";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%15e";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% .0e %.le %Le %e %le %Le";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 0.094913941;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_E_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.17LE";
  long double val = 4134121;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_all_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_empty_format_and_parameters) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'),
                   sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%s", "Drop Sega PLS"),
                   sprintf(str2, "%s", "Drop Sega PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"),
      sprintf(str2, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100),
                   sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%i", -0), sprintf(str2, "%i", -0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%i%i%i%i", -999, 0, 666, -100),
                   sprintf(str2, "%i%i%i%i", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_float) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0001),
                   sprintf(str2, "%f", 0.0001));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_float) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(
      s21_sprintf(str1, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001),
      sprintf(str2, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_unsigned_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "%u", 100),
                   sprintf(str2, "%u", (unsigned)100));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_unsigned_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100),
                   sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0,
                           (unsigned)666, (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_char_with_alignment_left) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'), sprintf(str2, "%8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_char_with_alignment_right) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%-8c", '\t'),
                   sprintf(str2, "%-8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_char_with_alignment) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'),
      sprintf(str2, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START HEX TEST
START_TEST(sprintf_test_one_hex_lower) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "%x", (unsigned)INT32_MIN),
                   sprintf(str2, "%x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%x", 0), sprintf(str2, "%x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%x", INT32_MAX),
                   sprintf(str2, "%x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%X", (unsigned)INT32_MIN),
                   sprintf(str2, "%X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%X", 0), sprintf(str2, "%x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%X", INT32_MAX),
                   sprintf(str2, "%X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_lower) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_upper) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST

// START HEX WITH ALIGNMENT
START_TEST(sprintf_test_one_hex_lower_with_alignment_left) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%-3x", (unsigned)INT32_MIN),
                   sprintf(str2, "%-3x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-3x", 0), sprintf(str2, "%-3x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-3x", INT32_MAX),
                   sprintf(str2, "%-3x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_lower_with_alignment_right) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%13x", (unsigned)INT32_MIN),
                   sprintf(str2, "%13x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%13x", 0), sprintf(str2, "%13x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%13x", INT32_MAX),
                   sprintf(str2, "%13x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper_with_alignment_left) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MIN),
                   sprintf(str2, "%-60X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-60X", 0), sprintf(str2, "%-60X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MAX),
                   sprintf(str2, "%-60X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper_with_alignment_right) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%7X", (unsigned)INT32_MIN),
                   sprintf(str2, "%7X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%7X", 0), sprintf(str2, "%7X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%7X", INT32_MAX),
                   sprintf(str2, "%7X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_lower_with_alignment) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_upper_with_alignment) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(
      s21_sprintf(str1, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// START HEX WITH ALIGNMENT

// START HEX TEST WITH #
START_TEST(sprintf_test_one_hex_with_hashtag) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MIN),
                   sprintf(str2, "%#x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#x", 0), sprintf(str2, "%#x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MAX),
                   sprintf(str2, "%#x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper_with_hashtag) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MIN),
                   sprintf(str2, "%#X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#X", 0), sprintf(str2, "%#X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MAX),
                   sprintf(str2, "%#X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_lower_with_hashtag_and_alignm) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0,
                  123213123),
      sprintf(str2, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_upper_with_hashtag_and_alignm) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0,
                  123213123),
      sprintf(str2, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH #

// START HEX TEST with width *
START_TEST(sprintf_test_one_hex_lower_with_width_star) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MIN),
                   sprintf(str2, "%*x", 11, (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, 0),
                   sprintf(str2, "%*x", 11, 0));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MAX),
                   sprintf(str2, "%*x", 11, INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper_with_width_star) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MIN),
                   sprintf(str2, "%*X", 11, (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, 0),
                   sprintf(str2, "%*X", 11, 0));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MAX),
                   sprintf(str2, "%*X", 11, INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_lower_with_width_star_and_align_and_hashtag) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#*x%*x%-12x%3x%*x", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*x%*x%-12x%3x%*x", 9, 127312897, -0, -1,
                           199, -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_upper_with_width_star) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1, 199,
                           -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH Width *

// START HEX TEST WITH precision
START_TEST(sprintf_test_one_hex_lower_with_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int a = s21_sprintf(str1, "%*.6x", 11, 0);
  int b = sprintf(str2, "%*.6x", 11, 0);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper_with_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int a = s21_sprintf(str1, "%*.6X", 11, INT32_MIN);
  int b = sprintf(str2, "%*.6X", 11, (unsigned)INT32_MIN);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_lower_with_precision_and_other) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int a = s21_sprintf(
      str1, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x", 3, 126714,
      4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9, 41, -41, 33);
  int b = sprintf(str2, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x",
                  3, 126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9,
                  41, -41, 33);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_upper_with_precision_and_other) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X",
                  3, -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9,
                  41, -41, 33),
      sprintf(str2, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X", 3,
              -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9, 41,
              -41, 33));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH precision

// START HEX TEST WITH Length
START_TEST(sprintf_test_one_hex_lower_with_length) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                   sprintf(str2, "%hx", (unsigned short)-11));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                   sprintf(str2, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper_with_length) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                   sprintf(str2, "%hx", (unsigned short)-11));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                   sprintf(str2, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%10ld";

  ck_assert_int_eq(s21_sprintf(str1, format, 1), sprintf(str2, format, 1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%1.1f";

  ck_assert_int_eq(s21_sprintf(str1, format, 1.1), sprintf(str2, format, 1.1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf3) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%8.3c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf4) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%+5.5d aboba";

  int val = 10000;
  int a = s21_sprintf(str1, format, val);
  int b = sprintf(str2, format, val);
  ck_assert_int_eq(a, b);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf6) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%7.7f";

  ck_assert_int_eq(s21_sprintf(str1, format, 11.123456),
                   sprintf(str2, format, 11.123456));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf7) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%7.4s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba floppa"),
                   sprintf(str2, format, "aboba floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf8) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%6.6u";

  ck_assert_int_eq(s21_sprintf(str1, format, 12341151),
                   sprintf(str2, format, 12341151));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf9) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%li%ld%lu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666666666666, 777, 111),
                   sprintf(str2, format, 666666666666, 777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf10) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%hi%hd%hu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666, -777, 111),
                   sprintf(str2, format, 666, -777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf11) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%+li%+lu%+d%+lf";

  ck_assert_int_eq(s21_sprintf(str1, format, -123, 321, -5555, -1213.123),
                   sprintf(str2, format, -123, 321, -5555, -1213.123));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf14) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% 0.0li% 0.0lu% 0.0ld % 0.0lf";

  ck_assert_int_eq(s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
                   sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf15) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% 0.0hi% 0.0hu% 0.0hd % 0.0hf";

  ck_assert_int_eq(s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
                   sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf16) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf17) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba likes floppa"),
                   sprintf(str2, format, "aboba likes floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf18) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% s% c";

  ck_assert_int_eq(s21_sprintf(str1, format, "", 'f'),
                   sprintf(str2, format, "", 'f'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf19) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%210s";

  ck_assert_int_eq(s21_sprintf(str1, format, "AHHAHAHA\0AHHAHAHAH"),
                   sprintf(str2, format, "AHHAHAHA\0AHHAHAHAH"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf20) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-115s";

  ck_assert_int_eq(s21_sprintf(str1, format, "Nick her"),
                   sprintf(str2, format, "Nick her"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf24) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%+2.1c%+4.2d%+5.4i%+10.2f%+55.55s%+1.1u";

  ck_assert_int_eq(
      s21_sprintf(str1, format, 'f', 21, 42, 666.666,
                  "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11),
      sprintf(str2, format, 'f', 21, 42, 666.666,
              "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf25) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 121.123),
                   sprintf(str2, format, 121.123));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf26) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%%";

  ck_assert_int_eq(s21_sprintf(str1, format), sprintf(str2, "%%"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf27) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%%%%%%%%";

  ck_assert_int_eq(s21_sprintf(str1, format), sprintf(str2, "%%%%%%%%"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf28) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int n1;
  int n2;
  int a = s21_sprintf(str1, "%d%n", 123, &n1);
  int b = sprintf(str2, "%d%n", 123, &n2);

  ck_assert_int_eq(a, b);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf29) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 111.111),
                   sprintf(str2, format, 111.111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf30) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-.1d";

  ck_assert_int_eq(s21_sprintf(str1, format, 111), sprintf(str2, format, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf31) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%e";
  double x = 111;
  ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf32) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%e%e%e%e";

  ck_assert_int_eq(s21_sprintf(str1, format, 11.111, 222.2222, 666., -555.125),
                   sprintf(str2, format, 11.111, 222.2222, 666., -555.125));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf33) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%Le";
  long double x = 122.1231;

  ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf35) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.10e";

  ck_assert_int_eq(s21_sprintf(str1, format, 111.184314818),
                   sprintf(str2, format, 111.184314818));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf36) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%5.3e%3.2e%lf";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.000111, 111.555, 1.999),
                   sprintf(str2, format, 0.000111, 111.555, 1.999));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf37) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%E";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.666666),
                   sprintf(str2, format, 0.666666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf38) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%E%E%E";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.0000999, 111.9999, 6.666),
                   sprintf(str2, format, 0.0000999, 111.9999, 6.666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf39) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%e ABOBA %Lf %Lf %Le";
  long double c = 848181;
  long double a = 0.00000001;
  long double b = 1111111.11;
  ck_assert_int_eq(s21_sprintf(str1, format, 123.123, a, b, c),
                   sprintf(str2, format, 123.123, a, b, c));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf40) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%#e Floppa %#E%#f";

  ck_assert_int_eq(s21_sprintf(str1, format, 123.111, 0.0000999, 0.555),
                   sprintf(str2, format, 123.111, 0.0000999, 0.555));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf41) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.Lf";
  long double a = 7.9418438184;

  ck_assert_int_eq(s21_sprintf(str1, format, a), sprintf(str2, format, a));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf42) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%#5p";
  int a = 5;
  ck_assert_int_eq(s21_sprintf(str1, format, &a), sprintf(str2, format, &a));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf43) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.5o";

  ck_assert_int_eq(s21_sprintf(str1, format, 12345),
                   sprintf(str2, format, 12345));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf44) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%#5lX";
  long hex = 314818438141;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_trailing_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.50300;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_large) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 5131.43141;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_small) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.5g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_precision_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.0g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_precision_missing) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_many_zeroes_in_front) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.g";
  double hex = 0.0004;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_one_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.5g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_mantiss) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.0000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_mantiss_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%5.8g";
  double hex = 0.0000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_short_no_mantiss) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_LG) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%LG";
  long double hex = 0.000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%LG %g %G %Lg %.5g";
  long double hex = 0.000005;
  double hex1 = 41.1341;
  double hex2 = 848.9000;
  long double hex3 = 0.0843;
  double hex4 = 0.0005;
  double hex5 = 0.8481481;
  ck_assert_int_eq(s21_sprintf(str1, format, hex, hex1, hex2, hex3, hex4, hex5),
                   sprintf(str2, format, hex, hex1, hex2, hex3, hex4, hex5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// sprintf <-

/**
    --------------------------------------------------
            <========== TEST SUITES ==========>
    --------------------------------------------------
**/

Suite *ts_s21_memchr() {
  Suite *suite = suite_create("ts_s21_memchr");
  TCase *test_case = tcase_create("tc_s21_memchr");

  tcase_add_test(test_case, tc001_memchr);
  tcase_add_test(test_case, tc002_memchr);
  tcase_add_test(test_case, tc003_memchr);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *ts_s21_memcmp() {
  Suite *suite = suite_create("ts_s21_memcmp");
  TCase *test_case = tcase_create("tc_s21_memcmp");

  tcase_add_test(test_case, tc004_memcmp);
  tcase_add_test(test_case, tc005_memcmp);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *ts_s21_memcpy() {
  Suite *suite = suite_create("ts_s21_memcpy");
  TCase *test_case = tcase_create("tc_s21_memcpy");

  tcase_add_test(test_case, tc006_memcpy);
  tcase_add_test(test_case, tc007_memcpy);
  tcase_add_test(test_case, tc008_memcpy);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *ts_s21_memmove() {
  Suite *suite = suite_create("ts_s21_memmove");
  TCase *test_case = tcase_create("tc_s21_memmove");

  tcase_add_test(test_case, tc009_memmove);
  tcase_add_test(test_case, tc010_memmove);
  tcase_add_test(test_case, tc011_memmove);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *ts_s21_memset() {
  Suite *suite = suite_create("ts_s21_memset");
  TCase *test_case = tcase_create("tc_s21_memset");

  tcase_add_test(test_case, tc015_memset);
  tcase_add_test(test_case, tc016_memset);
  tcase_add_test(test_case, tc017_memset);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *ts_s21_strcat() {
  Suite *suite = suite_create("ts_s21_strcat");
  TCase *test_case = tcase_create("tc_s21_strcat");

  tcase_add_test(test_case, tc018_strcat);
  tcase_add_test(test_case, tc019_strcat);
  tcase_add_test(test_case, tc020_strcat);
  tcase_add_test(test_case, tc021_strcat);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *ts_s21_strncat() {
  Suite *suite = suite_create("ts_s21_strncat");
  TCase *test_case = tcase_create("tc_s21_strncat");

  tcase_add_test(test_case, tc022_strncat);
  tcase_add_test(test_case, tc023_strncat);
  tcase_add_test(test_case, tc024_strncat);
  tcase_add_test(test_case, tc025_strncat);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *ts_s21_strchr() {
  Suite *suite = suite_create("ts_s21_strchr");
  TCase *test_case = tcase_create("tc_s21_strchr");

  tcase_add_test(test_case, tc026_strchr);
  tcase_add_test(test_case, tc027_strchr);
  tcase_add_test(test_case, tc028_strchr);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *ts_s21_strcmp() {
  Suite *suite = suite_create("ts_s21_strcmp");
  TCase *test_case = tcase_create("tc_s21_strcmp");

  tcase_add_test(test_case, tc029_strcmp);
  tcase_add_test(test_case, tc030_strcmp);
  tcase_add_test(test_case, tc031_strcmp);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *ts_s21_strncmp() {
  Suite *suite = suite_create("ts_s21_strncmp");
  TCase *test_case = tcase_create("tc_s21_strncmp");

  tcase_add_test(test_case, tc032_strncmp);
  tcase_add_test(test_case, tc033_strncmp);
  tcase_add_test(test_case, tc034_strncmp);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *ts_s21_strcpy() {
  Suite *suite = suite_create("ts_s21_strcpy");
  TCase *test_case = tcase_create("tc_s21_strcpy");

  tcase_add_test(test_case, tc035_strcpy);
  tcase_add_test(test_case, tc036_strcpy);
  tcase_add_test(test_case, tc037_strcpy);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *ts_s21_strncpy() {
  Suite *suite = suite_create("ts_s21_strncpy");
  TCase *test_case = tcase_create("tc_s21_strncpy");

  tcase_add_test(test_case, tc038_strncpy);
  tcase_add_test(test_case, tc039_strncpy);
  tcase_add_test(test_case, tc040_strncpy);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *ts_s21_strcspn() {
  Suite *suite = suite_create("ts_s21_strcspn");
  TCase *test_case = tcase_create("tc_s21_strcspn");

  tcase_add_test(test_case, tc041_strcspn);
  tcase_add_test(test_case, tc042_strcspn);
  tcase_add_test(test_case, tc043_strcspn);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *ts_s21_strerror() {
  Suite *suite = suite_create("ts_s21_strerror");
  TCase *test_case = tcase_create("tc_s21_strerror");

  tcase_add_test(test_case, tc044_strerror);
  tcase_add_test(test_case, tc045_strerror);
  tcase_add_test(test_case, tc046_strerror);
  tcase_add_test(test_case, tc047_strerror);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *ts_s21_strlen() {
  Suite *suite = suite_create("ts_s21_strlen");
  TCase *test_case = tcase_create("tc_s21_strlen");

  tcase_add_test(test_case, tc048_strlen);
  tcase_add_test(test_case, tc049_strlen);
  tcase_add_test(test_case, tc050_strlen);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *ts_s21_strpbrk() {
  Suite *suite = suite_create("ts_s21_strpbrk");
  TCase *test_case = tcase_create("tc_s21_strpbrk");

  tcase_add_test(test_case, tc051_strpbrk);
  tcase_add_test(test_case, tc052_strpbrk);
  tcase_add_test(test_case, tc053_strpbrk);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *ts_s21_strrchr() {
  Suite *suite = suite_create("ts_s21_strchr");
  TCase *test_case = tcase_create("tc_s21_strchr");

  tcase_add_test(test_case, tc054_strrchr);
  tcase_add_test(test_case, tc055_strrchr);
  tcase_add_test(test_case, tc056_strrchr);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *ts_s21_strspn() {
  Suite *suite = suite_create("ts_s21_strspn");
  TCase *test_case = tcase_create("tc_s21_strspn");

  tcase_add_test(test_case, tc057_strspn);
  tcase_add_test(test_case, tc058_strspn);
  tcase_add_test(test_case, tc059_strspn);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *ts_s21_strstr() {
  Suite *suite = suite_create("ts_s21_strstr");
  TCase *test_case = tcase_create("tc_s21_strstr");

  tcase_add_test(test_case, tc060_strstr);
  tcase_add_test(test_case, tc061_strstr);
  tcase_add_test(test_case, tc062_strstr);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *ts_s21_strtok() {
  Suite *suite = suite_create("ts_s21_strtok");
  TCase *test_case = tcase_create("tc_s21_strtok");

  tcase_add_test(test_case, tc063_strtok);
  tcase_add_test(test_case, tc064_strtok);
  tcase_add_test(test_case, tc065_strtok);
  tcase_add_test(test_case, tc066_strtok);
  tcase_add_test(test_case, tc067_strtok);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *ts_s21_sscanf() {
  Suite *suite = suite_create("ts_s21_sscanf");
  TCase *test_case = tcase_create("tc_s21_sscanf");

  tcase_add_test(test_case, tc_sscanf_simpliest);
  tcase_add_test(test_case, tc_sscanf_suppress);
  tcase_add_test(test_case, tc_sscanf_non_matching_char_in_between);
  tcase_add_test(test_case, tc_sscanf_matching_substr_in_between);
  tcase_add_test(test_case, tc_sscanf_matching_substr_in_between_with_suppress);
  tcase_add_test(test_case, tc_sscanf_simple_width);
  tcase_add_test(test_case, tc_sscanf_wchars);
  tcase_add_test(test_case, tc_sscanf_simple_short);
  tcase_add_test(test_case, tc_sscanf_simple_short_short);
  tcase_add_test(test_case, tc_sscanf_simple_long);
  tcase_add_test(test_case, tc_sscanf_simple_longlong);
  tcase_add_test(test_case, tc_sscanf_simple_i_spec);
  tcase_add_test(test_case, tc_sscanf_hex_i_spec);
  tcase_add_test(test_case, tc_sscanf_simple_octal);
  tcase_add_test(test_case, tc_sscanf_bad_octal);
  tcase_add_test(test_case, tc_sscanf_simple_string);
  tcase_add_test(test_case, tc_sscanf_two_strings);
  tcase_add_test(test_case, tc_sscanf_suppress_and_width_string);
  tcase_add_test(test_case, tc_sscanf_simple_unsigned);
  tcase_add_test(test_case, tc_sscanf_unsigned_long);
  tcase_add_test(test_case, tc_sscanf_unsigned_longlong);
  tcase_add_test(test_case, tc_sscanf_simple_hex);
  tcase_add_test(test_case, tc_sscanf_hex_long);
  tcase_add_test(test_case, tc_sscanf_hex_longlong);
  tcase_add_test(test_case, tc_sscanf_hex_short);
  tcase_add_test(test_case, tc_sscanf_bad_hex);
  tcase_add_test(test_case, tc_sscanf_hex_cap_longlong);
  tcase_add_test(test_case, tc_sscanf_simple_pointer);
  tcase_add_test(test_case, tc_sscanf_signed_pointer);
  tcase_add_test(test_case, tc_sscanf_bad_pointer);
  tcase_add_test(test_case, tc_sscanf_bytes_readed);
  tcase_add_test(test_case, tc_sscanf_bytes_readed_short);
  tcase_add_test(test_case, tc_sscanf_bytes_readed_short_short);
  tcase_add_test(test_case, tc_sscanf_bytes_readed_long);
  tcase_add_test(test_case, tc_sscanf_bytes_readed_longlong);
  tcase_add_test(test_case, tc_sscanf_simple_float);
  tcase_add_test(test_case, tc_sscanf_simple_double);
  tcase_add_test(test_case, tc_sscanf_simple_long_double);
  tcase_add_test(test_case, tc_sscanf_pos_exponent);
  tcase_add_test(test_case, tc_sscanf_neg_exponent);
  tcase_add_test(test_case, tc_sscanf_float_underflow);
  tcase_add_test(test_case, tc_sscanf_inf_float);
  tcase_add_test(test_case, tc_sscanf_nan_float);
  tcase_add_test(test_case, tc_sscanf_nan_float_alter);
  tcase_add_test(test_case, tc_sscanf_spec_char);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *ts_s21_sprintf() {
  Suite *suite = suite_create("ts_s21_fprintf");
  TCase *test_case = tcase_create("tc_s21_fprintf");

  tcase_add_test(test_case, s21_Ssprintf_test);
  tcase_add_test(test_case, s21_Csprintf_test);
  tcase_add_test(test_case, s21_Fsprintf_test);
  tcase_add_test(test_case, s21_IDsprintf_test);
  tcase_add_test(test_case, s21_Usprintf_test);
  tcase_add_test(test_case, s21_eEsprintf_test);
  tcase_add_test(test_case, s21_Osprintf_test);
  tcase_add_test(test_case, s21_xXsprintf_test);
  tcase_add_test(test_case, s21_Psprintf_test);
  tcase_add_test(test_case, s21_Nsprintf_test);

  // // sprintf ->

  tcase_add_test(test_case, sprintf_simple_int);
  tcase_add_test(test_case, sprintf_precise_int);
  tcase_add_test(test_case, sprintf_width_int);
  tcase_add_test(test_case, sprintf_minus_width_int);
  tcase_add_test(test_case, sprintf_plus_width_int);
  tcase_add_test(test_case, sprintf_padding_int);
  tcase_add_test(test_case, sprintf_star_width_int);
  tcase_add_test(test_case, sprintf_star_precision_int);
  tcase_add_test(test_case, sprintf_many_flags_many_ints);
  tcase_add_test(test_case, sprintf_flags_long_int);
  tcase_add_test(test_case, sprintf_flags_short_int);
  tcase_add_test(test_case, sprintf_flags_another_long_int);
  tcase_add_test(test_case, sprintf_zero_precision_zero_int);
  tcase_add_test(test_case, sprintf_space_flag_int);
  tcase_add_test(test_case, sprintf_unsigned_val);
  tcase_add_test(test_case, sprintf_unsigned_val_width);
  tcase_add_test(test_case, sprintf_unsigned_val_flags);
  tcase_add_test(test_case, sprintf_unsigned_val_precision);
  tcase_add_test(test_case, sprintf_unsigned_val_many_flags);
  tcase_add_test(test_case, sprintf_unsigned_val_short);
  tcase_add_test(test_case, sprintf_unsigned_val_long);
  tcase_add_test(test_case, sprintf_unsigned_val_many);

  tcase_add_test(test_case, sprintf_octal_width);
  tcase_add_test(test_case, sprintf_octal_flags);
  tcase_add_test(test_case, sprintf_octal_precision);
  tcase_add_test(test_case, sprintf_octal_many_flags);
  tcase_add_test(test_case, sprintf_octal_short);
  tcase_add_test(test_case, sprintf_octal_long);
  tcase_add_test(test_case, sprintf_octal_many);
  tcase_add_test(test_case, sprintf_octal);
  tcase_add_test(test_case, sprintf_octal_zero);
  tcase_add_test(test_case, sprintf_octal_hash);
  tcase_add_test(test_case, sprintf_unsigned_zero);
  tcase_add_test(test_case, sprintf_hex_width);
  tcase_add_test(test_case, sprintf_hex_flags);
  tcase_add_test(test_case, sprintf_hex_precision);
  tcase_add_test(test_case, sprintf_hex_many);
  tcase_add_test(test_case, sprintf_hex_many_flags);
  tcase_add_test(test_case, sprintf_hex_zero);
  tcase_add_test(test_case, sprintf_hex_huge);
  tcase_add_test(test_case, sprintf_hex_short);
  tcase_add_test(test_case, sprintf_hex_long);
  tcase_add_test(test_case, sprintf_hex_one_longer_width);
  tcase_add_test(test_case, sprintf_hex_two_longer_width);
  tcase_add_test(test_case, sprintf_one_char);
  tcase_add_test(test_case, sprintf_one_precision);
  tcase_add_test(test_case, sprintf_one_flags);
  tcase_add_test(test_case, sprintf_one_width);
  tcase_add_test(test_case, sprintf_one_many);
  tcase_add_test(test_case, sprintf_one_many_flags);
  tcase_add_test(test_case, sprintf_string);
  tcase_add_test(test_case, sprintf_string_precision);
  tcase_add_test(test_case, sprintf_string_width);
  tcase_add_test(test_case, sprintf_string_flags);
  tcase_add_test(test_case, sprintf_string_long);
  tcase_add_test(test_case, sprintf_string_many);
  tcase_add_test(test_case, sprintf_ptr);
  tcase_add_test(test_case, sprintf_ptr_width);
  tcase_add_test(test_case, sprintf_ptr_precision);
  tcase_add_test(test_case, sprintf_null_ptr);
  tcase_add_test(test_case, sprintf_n_specifier);
  tcase_add_test(test_case, sprintf_string_width_huge);
  tcase_add_test(test_case, sprintf_float_precision);
  tcase_add_test(test_case, sprintf_float_width);
  tcase_add_test(test_case, sprintf_float_precision_zero);
  tcase_add_test(test_case, sprintf_float_precision_empty);
  tcase_add_test(test_case, sprintf_float_precision_huge);
  tcase_add_test(test_case, sprintf_float_precision_huge_negative);
  tcase_add_test(test_case, sprintf_float_huge);
  tcase_add_test(test_case, sprintf_float_flags);
  tcase_add_test(test_case, sprintf_float_many);
  tcase_add_test(test_case, sprintf_e_precision_zero);
  tcase_add_test(test_case, sprintf_e_precision_empty);
  tcase_add_test(test_case, sprintf_e_precision_huge);
  tcase_add_test(test_case, sprintf_e_precision_huge_negative);
  tcase_add_test(test_case, sprintf_e_huge);
  tcase_add_test(test_case, sprintf_e_many);
  tcase_add_test(test_case, sprintf_e_width);
  tcase_add_test(test_case, sprintf_e_flags);
  tcase_add_test(test_case, sprintf_E_int);
  tcase_add_test(test_case, sprintf_all_empty);
  tcase_add_test(test_case, sprintf_empty_format_and_parameters);
  tcase_add_test(test_case, sprintf_test_one_char);
  tcase_add_test(test_case, sprintf_test_many_char);
  tcase_add_test(test_case, sprintf_test_one_string);
  tcase_add_test(test_case, sprintf_test_many_string);
  tcase_add_test(test_case, sprintf_test_one_dec);
  tcase_add_test(test_case, sprintf_test_many_dec);
  tcase_add_test(test_case, sprintf_test_one_int);
  tcase_add_test(test_case, sprintf_test_many_int);
  tcase_add_test(test_case, sprintf_test_one_float);
  tcase_add_test(test_case, sprintf_test_many_float);
  tcase_add_test(test_case, sprintf_test_one_unsigned_dec);
  tcase_add_test(test_case, sprintf_test_many_unsigned_dec);
  tcase_add_test(test_case, sprintf_test_one_char_with_alignment_left);
  tcase_add_test(test_case, sprintf_test_one_char_with_alignment_right);
  tcase_add_test(test_case, sprintf_test_many_char_with_alignment);
  tcase_add_test(test_case, sprintf_test_one_hex_lower);
  tcase_add_test(test_case, sprintf_test_one_hex_upper);
  tcase_add_test(test_case, sprintf_test_many_hex_lower);
  tcase_add_test(test_case, sprintf_test_many_hex_upper);
  tcase_add_test(test_case, sprintf_test_one_hex_lower_with_alignment_left);
  tcase_add_test(test_case, sprintf_test_one_hex_lower_with_alignment_right);
  tcase_add_test(test_case, sprintf_test_one_hex_upper_with_alignment_left);
  tcase_add_test(test_case, sprintf_test_one_hex_upper_with_alignment_right);
  tcase_add_test(test_case, sprintf_test_many_hex_lower_with_alignment);
  tcase_add_test(test_case, sprintf_test_many_hex_upper_with_alignment);
  tcase_add_test(test_case, sprintf_test_one_hex_with_hashtag);
  tcase_add_test(test_case, sprintf_test_one_hex_upper_with_hashtag);
  tcase_add_test(test_case,
                 sprintf_test_many_hex_lower_with_hashtag_and_alignm);
  tcase_add_test(test_case,
                 sprintf_test_many_hex_upper_with_hashtag_and_alignm);
  tcase_add_test(test_case, sprintf_test_one_hex_lower_with_width_star);
  tcase_add_test(test_case, sprintf_test_one_hex_upper_with_width_star);
  tcase_add_test(
      test_case,
      sprintf_test_many_hex_lower_with_width_star_and_align_and_hashtag);
  tcase_add_test(test_case, sprintf_test_many_hex_upper_with_width_star);
  tcase_add_test(test_case, sprintf_test_one_hex_lower_with_precision);
  tcase_add_test(test_case, sprintf_test_one_hex_upper_with_precision);
  tcase_add_test(test_case,
                 sprintf_test_many_hex_lower_with_precision_and_other);
  tcase_add_test(test_case,
                 sprintf_test_many_hex_upper_with_precision_and_other);
  tcase_add_test(test_case, sprintf_test_one_hex_lower_with_length);
  tcase_add_test(test_case, sprintf_test_one_hex_upper_with_length);
  tcase_add_test(test_case, sprintf_test_sprintf1);
  tcase_add_test(test_case, sprintf_test_sprintf2);
  tcase_add_test(test_case, sprintf_test_sprintf3);
  tcase_add_test(test_case, sprintf_test_sprintf4);
  tcase_add_test(test_case, sprintf_test_sprintf6);
  tcase_add_test(test_case, sprintf_test_sprintf7);
  tcase_add_test(test_case, sprintf_test_sprintf8);
  tcase_add_test(test_case, sprintf_test_sprintf9);
  tcase_add_test(test_case, sprintf_test_sprintf10);
  tcase_add_test(test_case, sprintf_test_sprintf11);
  tcase_add_test(test_case, sprintf_test_sprintf14);
  tcase_add_test(test_case, sprintf_test_sprintf15);
  tcase_add_test(test_case, sprintf_test_sprintf16);
  tcase_add_test(test_case, sprintf_test_sprintf17);
  tcase_add_test(test_case, sprintf_test_sprintf18);
  tcase_add_test(test_case, sprintf_test_sprintf19);
  tcase_add_test(test_case, sprintf_test_sprintf20);
  tcase_add_test(test_case, sprintf_test_sprintf24);
  tcase_add_test(test_case, sprintf_test_sprintf25);
  tcase_add_test(test_case, sprintf_test_sprintf28);
  tcase_add_test(test_case, sprintf_test_sprintf29);
  tcase_add_test(test_case, sprintf_test_sprintf30);
  tcase_add_test(test_case, sprintf_test_sprintf31);
  tcase_add_test(test_case, sprintf_test_sprintf32);
  tcase_add_test(test_case, sprintf_test_sprintf33);
  tcase_add_test(test_case, sprintf_test_sprintf35);
  tcase_add_test(test_case, sprintf_test_sprintf36);
  tcase_add_test(test_case, sprintf_test_sprintf37);
  tcase_add_test(test_case, sprintf_test_sprintf38);
  tcase_add_test(test_case, sprintf_test_sprintf39);
  tcase_add_test(test_case, sprintf_test_sprintf40);
  tcase_add_test(test_case, sprintf_test_sprintf41);
  tcase_add_test(test_case, sprintf_test_sprintf42);
  tcase_add_test(test_case, sprintf_test_sprintf43);
  tcase_add_test(test_case, sprintf_test_sprintf44);
  tcase_add_test(test_case, sprintf_test_sprintf26);
  tcase_add_test(test_case, sprintf_test_sprintf27);
  tcase_add_test(test_case, sprintf_g_trailing_zero);
  tcase_add_test(test_case, sprintf_g_large);
  tcase_add_test(test_case, sprintf_g_small);
  tcase_add_test(test_case, sprintf_g_precision);
  tcase_add_test(test_case, sprintf_g_precision_zero);
  tcase_add_test(test_case, sprintf_g_precision_missing);
  tcase_add_test(test_case, sprintf_g_many_zeroes_in_front);
  tcase_add_test(test_case, sprintf_g_one_zero);
  tcase_add_test(test_case, sprintf_g_mantiss);
  tcase_add_test(test_case, sprintf_g_mantiss_flags);
  tcase_add_test(test_case, sprintf_g_short_no_mantiss);
  tcase_add_test(test_case, sprintf_LG);
  tcase_add_test(test_case, sprintf_g_many);
  tcase_add_test(test_case, sprintf_g_zero);

  suite_add_tcase(suite, test_case);

  return suite;
}

int main(void) {
  int failed = 0;
  Suite *test_suites[] = {
      ts_s21_memchr(),
      ts_s21_memcmp(),
      ts_s21_memcpy(),
      ts_s21_memmove(),
      ts_s21_memset(),
      ts_s21_strcat(),
      ts_s21_strncat(),
      ts_s21_strchr(),
      ts_s21_strcmp(),
      ts_s21_strncmp(),
      ts_s21_strcpy(),
      ts_s21_strncpy(),
      ts_s21_strcspn(),
      ts_s21_strerror(),
      ts_s21_strlen(),
      ts_s21_strpbrk(),
      ts_s21_strrchr(),
      ts_s21_strspn(),
      ts_s21_strstr(),
      ts_s21_strtok(),
      ts_s21_sscanf(),
      ts_s21_sprintf(),
      NULL,
  };

  for (Suite **s = test_suites; *s != NULL; s++) {
    SRunner *runner = srunner_create(*s);
    srunner_run_all(runner, CK_NORMAL);
    failed += srunner_ntests_failed(runner);
    srunner_free(runner);
  }

  return failed;
}
