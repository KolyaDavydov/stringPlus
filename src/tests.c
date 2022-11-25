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

START_TEST(t0c21_strcat) {
  char dest[100]= "Hello ";
  char str[100] = "";
  ck_assert_str_eq(strcat(dest, str), s21_strcat(dest, str));
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
  Suite *suite = suite_create("ts_s21_memmove");
  TCase *test_case = tcase_create("tc_s21_memmove");

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
