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

int main(void) {
  int failed = 0;
  Suite *test_suites[] = {
      ts_s21_memcmp(),
      ts_s21_memcpy(),
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
