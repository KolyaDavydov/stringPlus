#include <check.h>
#include <stdio.h>
#include <string.h>

#include "s21_string.h"

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
  char str1[] = "++Aboba++Floppa_! Kotya===!Shleppa+++ A +";
  char str2[] = "++Aboba++Floppa_! Kotya===!Shleppa+++ A +";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got && expected) {
    got = s21_strtok(s21_NULL, delims);
    expected = strtok(s21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
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
END_TEST

// <=== TEST CASES: s21_to_upper ===>

START_TEST(tc068_to_upper) {
  char str1[] = ". Hello /world/!!! ";
  char *ch1 = s21_to_upper(str1);
  ck_assert_pstr_eq(ch1, ". HELLO /WORLD/!!! ");
  if (ch1) free(ch1);
}
END_TEST

START_TEST(tc069_to_upper) {
  char str1[] = "";
  char *ch1 = s21_to_upper(str1);
  ck_assert_pstr_eq(ch1, s21_NULL);
  if (ch1) free(ch1);
}
END_TEST

// <=== TEST CASES: s21_to_lower ===>

START_TEST(tc070_to_lower) {
  char str1[] = ". HELLO /WORLD/!!! ";
  char *ch1 = s21_to_lower(str1);
  ck_assert_pstr_eq(ch1, ". hello /world/!!! ");
  if (ch1) free(ch1);
}
END_TEST

START_TEST(tc071_to_lower) {
  char str1[] = "";
  char *ch1 = s21_to_lower(str1);
  ck_assert_pstr_eq(ch1, s21_NULL);
  if (ch1) free(ch1);
}
END_TEST

// <=== TEST CASES: s21_insert ===>

START_TEST(tc072_insert) {
  char str1[] = ". HELLO /WORLD/!!! ";
  char str2[] = "space";
  s21_size_t i = 8;
  char *ch1 = s21_insert(str1, str2, i);
  ck_assert_pstr_eq(ch1, ". HELLO space/WORLD/!!! ");
  if (ch1) free(ch1);
}
END_TEST

START_TEST(tc073_insert) {
  char str1[] = "qwe ";
  char str2[] = "space";
  s21_size_t i = 3;
  char *ch1 = s21_insert(str1, str2, i);
  ck_assert_pstr_eq(ch1, "qwespace ");
  if (ch1) free(ch1);
}
END_TEST

START_TEST(tc074_insert) {
  char str1[] = "";
  char str2[] = "space";
  s21_size_t i = 3;
  char *ch1 = s21_insert(str1, str2, i);
  ck_assert_pstr_eq(ch1, s21_NULL);
  if (ch1) free(ch1);
}
END_TEST

// <=== TEST CASES: s21_trim ===>

START_TEST(tc075_trim) {
  char src1[] = "     &#@\n\n\t Hello, World! *&#@ \n\t   ";
  char trim_chars[] = " &#@\n\t";
  char *psrc = s21_trim(src1, trim_chars);
  ck_assert_pstr_eq(psrc, "Hello, World! *");
  free(psrc);
}
END_TEST

START_TEST(tc076_trim) {
  char str1[] = ". /!!! ";
  char str2[] = ". /!";
  char *ch1 = s21_trim(str1, str2);
  ck_assert_pstr_eq(ch1, s21_NULL);
  if (ch1) free(ch1);
}
END_TEST

START_TEST(tc077_trim) {
  char str1[] = ". HELLO /WORLD/!!! ";
  char str2[] = "";
  char *ch1 = s21_trim(str1, str2);
  ck_assert_pstr_eq(ch1, s21_NULL);
  if (ch1) free(ch1);
}
END_TEST

START_TEST(tc078_trim) {
  char str[] = "        abc         ";
  char *trim_ch = s21_NULL;
  char *got = s21_trim(str, trim_ch);
  ck_assert_pstr_eq(got, trim_ch);
  if (got) free(got);
}
END_TEST

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

Suite *ts_s21_to_upper() {
  Suite *suite = suite_create("ts_s21_to_upper");
  TCase *test_case = tcase_create("tc_s21_to_upper");

  tcase_add_test(test_case, tc068_to_upper);
  tcase_add_test(test_case, tc069_to_upper);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *ts_s21_to_lower() {
  Suite *suite = suite_create("ts_s21_to_lower");
  TCase *test_case = tcase_create("tc_s21_to_lower");

  tcase_add_test(test_case, tc070_to_lower);
  tcase_add_test(test_case, tc071_to_lower);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *ts_s21_insert() {
  Suite *suite = suite_create("ts_s21_insert");
  TCase *test_case = tcase_create("tc_s21_insert");

  tcase_add_test(test_case, tc072_insert);
  tcase_add_test(test_case, tc073_insert);
  tcase_add_test(test_case, tc074_insert);
  suite_add_tcase(suite, test_case);

  return suite;
}

Suite *ts_s21_trim() {
  Suite *suite = suite_create("ts_s21_trim");
  TCase *test_case = tcase_create("tc_s21_trim");

  tcase_add_test(test_case, tc075_trim);
  tcase_add_test(test_case, tc076_trim);
  tcase_add_test(test_case, tc077_trim);
  tcase_add_test(test_case, tc078_trim);
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
      ts_s21_to_upper(),
      ts_s21_to_lower(),
      ts_s21_insert(),
      ts_s21_trim(),
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
