#include <check.h>
#include <stdio.h>
#include <string.h>

#include "s21_string.h"

/**
    --------------------------------------------------
            <========== TEST CASES ==========>
    --------------------------------------------------
**/

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

/**
    --------------------------------------------------
            <========== TEST SUITES ==========>
    --------------------------------------------------
**/

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

Suite *ts_s21_strncat() {
  Suite *suite = suite_create("ts_s21_strncat");
  TCase *test_case = tcase_create("tc_s21_strncat");

  tcase_add_test(test_case, tc022_strncat);
  tcase_add_test(test_case, tc023_strncat);
  tcase_add_test(test_case, tc024_strncat);
  tcase_add_test(test_case, tc025_strncat);
  suite_add_tcase(suite, test_case);

  return suite;

int main(void) {
  int failed = 0;
  Suite *test_suites[] = {
      ts_s21_memcmp(),
      ts_s21_memcpy(),
      ts_s21_memmove(),
      ts_s21_strncat().
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
