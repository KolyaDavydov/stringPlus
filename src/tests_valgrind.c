#include <stdint.h>
#include <stdio.h>

#include "s21_string.h"

#define BUFF_SIZE 512

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

void tc_s21_sscanf() {
  {
    char fstr[] = "%d";
    char str[] = "        ";

    s21_sscanf(str, fstr, 0);
    sscanf(str, fstr, 100);
  }

  {
    char fstr[] = "%d ";
    char str[] = "               ";
    int16_t a1 = 0, a2 = 0;

    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    char fstr[] = "%d ";
    char str[] = "  ";
    int16_t a1 = 0, a2 = 0;

    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    char fstr[] = "%c %c %c %c";
    char str[] = "   a     b c d";
    int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    char fstr[] = "%c%c%c%c";
    char str[] = "abcd";
    int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    char fstr[] = "%c %c %c      %c";
    char str[] = "1 a 3   c           ";
    int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    char fstr[] = "%c %c %c %c";
    char str[] = "   000 0    ";
    int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    char fstr[] = "%c %c %c %c";
    char str[] = "tttt";
    int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    char fstr[] = "%c%c%c%c";
    char str[] = "\\\n\t\t\t";
    int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    char fstr[] = "%c %c %c %c";
    char str[] = "z ' ' /";
    int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    char fstr[] = "%c%*c%c%c";
    char str[] = "ABCD";
    int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;

    s21_sscanf(str, fstr, &a1, &b1, &c1);

    sscanf(str, fstr, &a2, &b2, &c2);
  }

  {
    char fstr[] = "%c %c %c %c";
    char str[] = "z *'@";
    int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    char fstr[] = "%1c %c %c %0c";
    char str[] = "z *'@";
    int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    char fstr[] = "%c %c %c %c";
    char str[] = "z *'@";
    int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    char fstr[] = "%c %c %c %c";
    char str[] = "z *'@";
    int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    char fstr[] = "%*c%*c%*c%c";
    char str[] = "abcde";
    int16_t a1 = 0, a2 = 0;

    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    char fstr[] = "%*c%*c%*c%*c";
    char str[] = "   c ";
    int16_t a1 = 0, a2 = 0;

    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    char fstr[] = "%*c%*c%*c%c";
    char str[] = "abcd ";
    int16_t a1 = 0, a2 = 0;

    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char fstr[] = "%ld %ld %ld %ld";
    const char str[] = "555 666 777 888";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "1337 21 5008 3000";
    const char fstr[] = "%hd %hd %hd %hd";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "1337 21 5008 300004";
    const char fstr[] = "%lld %lld %lld %lld";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "1337 21 5008 300004";
    const char fstr[] = "%1lld %3lld %1lld %4lld";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "1337";
    const char fstr[] = "%1lld %1lld %1lld %1lld";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "100000000000000005";
    const char fstr[] = "%3lld%lld%1lld%5lld";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "1337";
    const char fstr[] = "%15lld %1lld %1lld %1lld";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
    const char str[] = "1337123123 1 123412341234 1 999999 0";
    const char fstr[] = "%*d %lld %*d %lld %*d %lld";

    s21_sscanf(str, fstr, &a1, &b1, &c1);
    sscanf(str, fstr, &a2, &b2, &c2);
  }

  {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "1337";
    const char fstr[] = "%15lld %1lld %1lld %1lld";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "1337";
    const char fstr[] = "%15lld %1lld %1lld %1lld";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "1337";
    const char fstr[] = "%15lld %1lld %1lld %1lld";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "11337 ++3 -5 ------4";
    const char fstr[] = "%lld %lld %lld %lld";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "-1337 +1 -1 -1";
    const char fstr[] = "%15lld %1lld %1lld %5lld";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "-0 +0 +0 -0";
    const char fstr[] = "%2lld %1lld %1lld %1lld";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "1 01 10 0";
    const char fstr[] = "%lld %lld %lld %lld";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "300 500 -600 +700";
    const char fstr[] = "%lli %lli %lli %lli";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "300500-600+700 111";
    const char fstr[] = "%lli %lld %lld %lli";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    long long a1 = 0, a2 = 0, c1 = 0, c2 = 0;
    char b1 = 0, b2 = 0, d1 = 0, d2 = 0;
    const char str[] = "300500-600+700+400";
    const char fstr[] = "%lli%c%lli%c";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "  55555 f f f5555555 ddd   4    3    1 ";
    const char fstr[] = "%lli %lld %lld %lli";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "0xFFF 0xA123123 0x123123 0x0";
    const char fstr[] = "%lli %lld %lld %lli";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = " 0xFFFF 0xf 0xf 0xf5555555 ddd   4    3    1 ";
    const char fstr[] = "%lli %lld %lld %lli";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "  055555 0f 0f 0f5555555 0ddd   4    3    1 ";
    const char fstr[] = "%lli %lld %lld %lli";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    const char str[] = "  055555 0f 0f 0f5555555 0ddd   4    3    1 ";
    const char fstr[] = "%lli %lld %lld %lli";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  // [%s] //
  {
    char s1[BUFF_SIZE] = {'\0'};
    char s2[BUFF_SIZE] = {'\0'};
    char s3[BUFF_SIZE] = {'\0'};
    char s4[BUFF_SIZE] = {'\0'};

    char s5[BUFF_SIZE] = {'\0'};
    char s6[BUFF_SIZE] = {'\0'};
    char s7[BUFF_SIZE] = {'\0'};
    char s8[BUFF_SIZE] = {'\0'};

    const char str[] = "Aboba Floppa Keppa Shleppa Anuroba";
    const char fstr[] = "%s %s %s %s";

    s21_sscanf(str, fstr, s1, s2, s3, s4);
    sscanf(str, fstr, s5, s6, s7, s8);
  }

  {
    char s1[BUFF_SIZE] = {'\0'};
    char s2[BUFF_SIZE] = {'\0'};
    char s3[BUFF_SIZE] = {'\0'};
    char s4[BUFF_SIZE] = {'\0'};

    char s5[BUFF_SIZE] = {'\0'};
    char s6[BUFF_SIZE] = {'\0'};
    char s7[BUFF_SIZE] = {'\0'};
    char s8[BUFF_SIZE] = {'\0'};

    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

    const char str[] = "Aboba 123 Floppa -3 Keppa 4444Shleppa 333Anuroba 3";
    const char fstr[] = "%s%ld%s%d%s%d%s";

    s21_sscanf(str, fstr, s1, &a1, s2, &b1, s3, &c1, s4, &d1);
    s21_sscanf(str, fstr, s5, &a2, s6, &b2, s7, &c2, s8, &d2);
  }

  {
    char s1[BUFF_SIZE] = {'\0'};
    char s2[BUFF_SIZE] = {'\0'};
    char s3[BUFF_SIZE] = {'\0'};
    char s4[BUFF_SIZE] = {'\0'};

    char s5[BUFF_SIZE] = {'\0'};
    char s6[BUFF_SIZE] = {'\0'};
    char s7[BUFF_SIZE] = {'\0'};
    char s8[BUFF_SIZE] = {'\0'};

    const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
    const char fstr[] = "%s%s%s%s";

    s21_sscanf(str, fstr, s1, s2, s3, s4);
    sscanf(str, fstr, s5, s6, s7, s8);
  }

  {
    const char str[] = "aboba\tkepaboba floppa shleppa koooppa ap p p p p";
    const char fstr[] = "%*s%*s%*s%*s";
    s21_sscanf(str, fstr);
    sscanf(str, fstr);
  }

  {
    char s1[BUFF_SIZE] = {'\0'};
    char s2[BUFF_SIZE] = {'\0'};
    char s3[BUFF_SIZE] = {'\0'};
    char s4[BUFF_SIZE] = {'\0'};

    char s5[BUFF_SIZE] = {'\0'};
    char s6[BUFF_SIZE] = {'\0'};
    char s7[BUFF_SIZE] = {'\0'};
    char s8[BUFF_SIZE] = {'\0'};

    const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
    const char fstr[] = "%1s%1s%1s%1s";

    s21_sscanf(str, fstr, s1, s2, s3, s4);
    sscanf(str, fstr, s5, s6, s7, s8);
  }

  {
    char s1[BUFF_SIZE] = {'\0'};
    char s2[BUFF_SIZE] = {'\0'};
    char s3[BUFF_SIZE] = {'\0'};
    char s4[BUFF_SIZE] = {'\0'};

    char s5[BUFF_SIZE] = {'\0'};
    char s6[BUFF_SIZE] = {'\0'};
    char s7[BUFF_SIZE] = {'\0'};
    char s8[BUFF_SIZE] = {'\0'};

    const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
    const char fstr[] = "%3s%3s%3s%3s";

    s21_sscanf(str, fstr, s1, s2, s3, s4);
    sscanf(str, fstr, s5, s6, s7, s8);
  }

  {
    char s1[BUFF_SIZE] = {'\0'};
    char s2[BUFF_SIZE] = {'\0'};
    char s3[BUFF_SIZE] = {'\0'};
    char s4[BUFF_SIZE] = {'\0'};

    char s5[BUFF_SIZE] = {'\0'};
    char s6[BUFF_SIZE] = {'\0'};
    char s7[BUFF_SIZE] = {'\0'};
    char s8[BUFF_SIZE] = {'\0'};

    const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
    const char fstr[] = "%150s%1s%1s\t%3s";

    s21_sscanf(str, fstr, s1, s2, s3, s4);
    sscanf(str, fstr, s5, s6, s7, s8);
  }

  // strings_mixed1
  {
    unsigned long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
    long long d1 = 0, d2 = 0;
    long double e1 = 0, e2 = 0;

    const char str[] =
        "4444444"
        "eeeeeee\teeeeeee";
    const char fstr[] = "%5s %1s %*s %*s %llu %s %llu %llu %lld %Lf %33s";

    char s1[BUFF_SIZE] = {'\0'};
    char s2[BUFF_SIZE] = {'\0'};
    char s5[BUFF_SIZE] = {'\0'};
    char s6[BUFF_SIZE] = {'\0'};
    char s7[BUFF_SIZE] = {'\0'};
    char s8[BUFF_SIZE] = {'\0'};
    char s9[BUFF_SIZE] = {'\0'};
    char s10[BUFF_SIZE] = {'\0'};

    s21_sscanf(str, fstr, s7, s9, &a1, s5, &b1, &c1, &d1, &e1, s1);
    sscanf(str, fstr, s8, s10, &a2, s6, &b2, &c2, &d2, &e2, s2);
  }

  {
    int d1 = 0, d2 = 0, b1 = 0, b2 = 0, a1 = 0, a2 = 0;
    long long v1, v2;

    const char str[] = "1 1 1 1 1 -1";
    const char fstr[] = "%1s %5d %1s %1s %d %lld %d";

    char s1[BUFF_SIZE] = {'\0'};
    char s2[BUFF_SIZE] = {'\0'};
    char s3[BUFF_SIZE] = {'\0'};
    char s4[BUFF_SIZE] = {'\0'};
    char s5[BUFF_SIZE] = {'\0'};
    char s6[BUFF_SIZE] = {'\0'};

    s21_sscanf(str, fstr, s1, &a1, s2, s3, &b1, &v1, &d1);
    sscanf(str, fstr, s4, &a2, s5, s6, &b2, &v2, &d2);
  }

  // [%n] //
  {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    int32_t n1 = 0, n2 = 5;

    const char str[BUFF_SIZE] = "50 160 70 80";
    const char fstr[BUFF_SIZE] = "%lli %lli %n %lli %lli";

    s21_sscanf(str, fstr, &a1, &b1, &n1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &n2, &c2, &d2);
  }

  {
    int n1 = 1, n2 = 5;

    char s1[BUFF_SIZE] = {'\0'};
    char s2[BUFF_SIZE] = {'\0'};
    char s3[BUFF_SIZE] = {'\0'};
    char s5[BUFF_SIZE] = {'\0'};
    char s6[BUFF_SIZE] = {'\0'};
    char s7[BUFF_SIZE] = {'\0'};

    const char str[] = "cbobErobM fl? asdfasdflkasdf asdfasdf asdfasdf 88888";
    const char fstr[] = "%s %s %n %s";

    s21_sscanf(str, fstr, s1, s2, &n1, s3);
    sscanf(str, fstr, s5, s6, &n2, s7);
  }

  {
    int n1 = 0, n2 = 5;

    const char str[BUFF_SIZE] = "50 60 70 80";
    const char fstr[BUFF_SIZE] = "%n";

    s21_sscanf(str, fstr, &n1);
    sscanf(str, fstr, &n2);
  }

  {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    int32_t n1 = 0, n2 = 5;

    const char str[] = "50 60 70 80";
    const char fstr[] = "%lli %lli %n %lli %lli";

    s21_sscanf(str, fstr, &a1, &b1, &n1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &n2, &c2, &d2);
  }

  {
    long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
    int n1 = 0, n2 = 5;

    const char str[] = "50 60 70 80";
    const char fstr[] = "%lli %lli %n %lli %lli";

    s21_sscanf(str, fstr, &a1, &b1, &n1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &n2, &c2, &d2);
  }

  // [%f] / [%g] / %[%G] //
  {
    long double a1 = 1, a2 = 0, b1 = 1, b2 = 0, c1 = 1, c2 = 0, d1 = 1, d2 = 0;

    const char str[] = "53.1 -4.1135 41.3333 +2.0001";
    const char fstr[] = "%Lf %Lf %Lf %Lf";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

    const char str[] = "0.00001 -4123123 4. .";
    const char fstr[] = "%lf %lf %lf %lf";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

    const char str[] = ". . . .";
    const char fstr[] = "%f %f %f %f";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    long double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

    const char str[] = "513.41 -4.14135 414.3333 +112.0001";
    const char fstr[] = "%Lf %Lf %Lf %Lf";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;

    const char str[] = "53.1 -4.1135 411231.333 +2.0001";
    const char fstr[] = "%*f %f %f %f";

    s21_sscanf(str, fstr, &a1, &b1, &c1);
    sscanf(str, fstr, &a2, &b2, &c2);
  }

  {
    float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

    const char str[] = "1.4441 1.31e+4 -3.31e-4 0.444e-5";
    const char fstr[] = "%G %G %G %G";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

    const char str[] = "inf 1.31e+4 NaN 0.444e-5";
    const char fstr[] = "%G %G %G %G";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
    // Unfortunately, assertions for inf do not work correctly in libcheck
  }

  {
    float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

    const char str[] = "inF InF inF INF";
    const char fstr[] = "%G %G %G %G";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

    const char str[] = "Nan NAN 0.0000 0";
    const char fstr[] = "%G %G %G %G";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

    const char str[] =
        "nAN           INF                   -0.1111         1e-10";
    const char fstr[] = "%G %G %G %G";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  // [%u] //
  {
    unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0,
                   d2 = 0;
    const char str[] = "-1337 +21 --5008 3000";
    const char fstr[] = "%hu %hu %hu %hu";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    unsigned long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0,
                           d1 = 0, d2 = 0;
    const char str[] = "-1337 233333331 5008 3000";
    const char fstr[] = "%1llu %2llu %5llu %4llu";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    unsigned long long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
    long long d1 = 0, d2 = 0;
    long double v1, v2;

    const char str[] =
        "\t\t\t\t\t\n 3      adsfdfa%$$$$`adfasdfasdfaszcvzcxvcv -1337 "
        "anurobich+ 21 -5008 -33000 0.3333";
    const char fstr[] = "%*s %*s %llu %s %llu %llu %lld %Lf";

    char s1[BUFF_SIZE] = {'\0'};
    char s2[BUFF_SIZE] = {'\0'};

    s21_sscanf(str, fstr, &a1, s1, &b1, &c1, &d1, &v1);
    sscanf(str, fstr, &a2, s2, &b2, &c2, &d2, &v2);
  }

  {
    unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0,
                   d2 = 0;
    const char str[] = "-1337 +21 --5008 3000";
    const char fstr[] = "%hu %hu %hu %hu";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0,
                   d2 = 0;
    const char str[] = "-1337 +21 --5008 3000";
    const char fstr[] = "%hu %hu %hu %hu";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0,
                   d2 = 0;
    const char str[] = "-1337 +21 --5008 3000";
    const char fstr[] = "%hu %hu %hu %hu";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    uint32_t a1, a2;
    const char str[] = "F";
    const char fstr[] = "%X";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    uint32_t a1, a2;
    const char str[] = "0xFFFFFFFF";
    const char fstr[] = "%X";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    uint32_t a1, a2;
    const char str[] = "0x";
    const char fstr[] = "%X";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    uint32_t a1, a2;
    const char str[] = "0X";
    const char fstr[] = "%X";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    uint32_t a1, a2;
    const char str[] = "";
    const char fstr[] = "%X";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    uint32_t a1, a2;
    const char str[] = "qF";
    const char fstr[] = "%X";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    uint32_t a1, a2;
    const char str[] = "          \n             \n     F";
    const char fstr[] = "%X";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    uint16_t a1, a2;
    const char str[] = "F";
    const char fstr[] = "%hX";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    unsigned long int a1, a2;
    const char str[] = "F";
    const char fstr[] = "%lX";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    unsigned long long int a1, a2;
    const char str[] = "F";
    const char fstr[] = "%llX";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    uint32_t a1, a2;
    const char str[] = "0xFF0x0xFFF 0xFFxFF";
    const char fstr[] = "%X";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    const char str[] = "0xFF0x0xFFF 0xFFxFF";
    const char fstr[] = "%*X";
    s21_sscanf(str, fstr);
    sscanf(str, fstr);
  }

  {
    uint32_t a1, a2;
    const char str[] = "tqwqpl";
    const char fstr[] = "%X";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    uint32_t a1, a2;
    const char str[] = "abcdef";
    const char fstr[] = "%X";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    uint32_t a1, a2;
    const char str[] = "-f";
    const char fstr[] = "%X";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    uint32_t a1, a2;
    const char str[] = "f";
    const char fstr[] = "%x";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    uint32_t a1, a2;
    const char str[] = "0xfffffffffffffffffff";
    const char fstr[] = "%x";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    uint32_t a1, a2;
    const char str[] = "0x";
    const char fstr[] = "%x";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    uint32_t a1, a2;
    const char str[] = "0X";
    const char fstr[] = "%x";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    uint32_t a1, a2;
    const char str[] = "";
    const char fstr[] = "%x";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    uint32_t a1, a2;
    const char str[] = "qF";
    const char fstr[] = "%x";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    uint32_t a1, a2;
    const char str[] = "          \n             \n     F";
    const char fstr[] = "%x";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    uint16_t a1, a2;
    const char str[] = "ff";
    const char fstr[] = "%hx";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    unsigned long int a1, a2;
    const char str[] = "ff";
    const char fstr[] = "%lx";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    unsigned long long int a1, a2;
    const char str[] = "faaaaaaaaaaaaf";
    const char fstr[] = "%llx";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    uint32_t a1, a2;
    const char str[] = "0xFF0x0xFFF 0xFFxFF";
    const char fstr[] = "%x";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    const char str[] = "0xFF0x0xFFF 0xFFxFF";
    const char fstr[] = "%*x";
    s21_sscanf(str, fstr);
    sscanf(str, fstr);
  }

  {
    uint32_t a1, a2;
    const char str[] = "tqwqpl";
    const char fstr[] = "%x";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    uint32_t a1, a2;
    const char str[] = "abcdef";
    const char fstr[] = "%x";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    uint32_t a1, a2;
    const char str[] = "-f";
    const char fstr[] = "%x";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    uint32_t a1, a2;
    const char str[] = "123531FFF";
    const char fstr[] = "%2X";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    uint32_t a1, a2;
    const char str[] = "123531FFF";
    const char fstr[] = "%2x";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    uint32_t a1, a2;
    const char str[] = "777";
    const char fstr[] = "%o";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    uint32_t a1, a2;
    const char str[] = "0x7777777777777777777777";
    const char fstr[] = "%o";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    uint32_t a1, a2;
    const char str[] = "0x";
    const char fstr[] = "%o";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    uint32_t a1, a2;
    const char str[] = "0X";
    const char fstr[] = "%o";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    uint32_t a1, a2;
    const char str[] = "";
    const char fstr[] = "%o";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    uint32_t a1, a2;
    const char str[] = "q1";
    const char fstr[] = "%o";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    uint32_t a1, a2;
    const char str[] = "          \n             \n     5";
    const char fstr[] = "%o";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    uint16_t a1, a2;
    const char str[] = "12";
    const char fstr[] = "%ho";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    unsigned long int a1, a2;
    const char str[] = "57234";
    const char fstr[] = "%lo";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    unsigned long long int a1, a2;
    const char str[] = "12356226137";
    const char fstr[] = "%llo";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    uint32_t a1, a2;
    const char str[] = "0x12320x213x123213";
    const char fstr[] = "%o";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    const char str[] = "521561612";
    const char fstr[] = "%*o";
    s21_sscanf(str, fstr);
    sscanf(str, fstr);
  }

  {
    uint32_t a1, a2;
    const char str[] = "tqwqpl";
    const char fstr[] = "%o";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    uint32_t a1, a2;
    const char str[] = "01234567";
    const char fstr[] = "%o";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    uint32_t a1, a2;
    const char str[] = "-66";
    const char fstr[] = "%o";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    uint32_t a1, a2;
    const char str[] = "123531";
    const char fstr[] = "%2o";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    int32_t a1, a2;
    int32_t b1, b2;
    const char str[] = "12 keppa 12";
    const char fstr[] = "%d keppa %d";
    s21_sscanf(str, fstr, &a1, &b1);
    sscanf(str, fstr, &a2, &b2);
  }

  {
    int32_t a1, a2;
    int32_t b1, b2;
    const char str[] = "12keppa12";
    const char fstr[] = "%dkeppa%d";
    s21_sscanf(str, fstr, &a1, &b1);
    sscanf(str, fstr, &a2, &b2);
  }

  {
    int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
    const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
    const char fstr[] = "%p %p %p %p";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
    const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
    const char fstr[] = "%p %p %p %p";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
    const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
    const char fstr[] = "%p %p %p %p";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
    const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
    const char fstr[] = "%p %p %p %p";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    int a1 = 0, a2 = 5, a3 = 3, a4 = 9;
    int32_t n1 = 500, n2 = 10000;

    const char str[] = "123123SkipMePlease!!!!123";
    const char fstr[] = "%dSkipMePlease!!!!%d %n";

    s21_sscanf(str, fstr, &a1, &a3, &n1);
    sscanf(str, fstr, &a2, &a4, &n2);
  }

  {
    int32_t a1, a2;
    int32_t b1 = 0, b2 = 0;
    const char str[] = "12keppa12";
    const char fstr[] = "%dkeppapos%d";
    s21_sscanf(str, fstr, &a1, &b1);
    sscanf(str, fstr, &a2, &b2);
  }

  {
    int32_t a1, a2;
    int32_t b1 = 80, b2 = 33;
    int32_t c1 = 55, c2 = 33;
    const char str[] = "12 % 13 % 14";
    const char fstr[] = "%d %% %d %% %d";
    s21_sscanf(str, fstr, &a1, &b1, &c1);
    sscanf(str, fstr, &a2, &b2, &c2);
  }

  {
    int32_t a1, a2;
    int32_t b1 = 80, b2 = 33;
    int32_t c1 = 55, c2 = 33;
    const char str[] = "12%13%14";
    const char fstr[] = "%d%%%d%%%d";
    s21_sscanf(str, fstr, &a1, &b1, &c1);
    sscanf(str, fstr, &a2, &b2, &c2);
  }

  {
    int32_t a1 = 1234, a2 = 33333;

    const char str[] = "%%%16";
    const char fstr[] = "%%%%%%%d";
    s21_sscanf(str, fstr, &a1);
    sscanf(str, fstr, &a2);
  }

  {
    const char str[] = "%%%";
    const char fstr[] = "%%%%%%";
    s21_sscanf(str, fstr);
    sscanf(str, fstr);
  }

  {
    int32_t a1 = 1234, a2 = 33333;
    int32_t b1 = 1234, b2 = 33333;

    const char str[] = "%%123%888";
    const char fstr[] = "%%%%%d%%%d";
    s21_sscanf(str, fstr, &a1, &b1);
    sscanf(str, fstr, &a2, &b2);
  }

  {
    int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;

    const char str[] = "0xFFFF 0xAAA 7123 0xBBC1FF";
    const char fstr[] = "%p %p %p %p";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    char *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;

    const char str[] = "0x4 0x3 0x2 0x1";
    const char fstr[] = "%p %p %p %p";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;

    const char str[] = "03033 0333 0123 0123 0x123 0xFFFFF 0xBBC1FF";
    const char fstr[] = "%p %p %p %p";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;

    const char str[] = "0xABCDEF 0xAAA 7123 0xBBC1FF";
    const char fstr[] = "%p %p %p %p";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;

    const char str[] = "NULL";
    const char fstr[] = "%p %p %p %p";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    char a1, a2;
    char b1[256] = {'\0'};
    char b2[256] = {'\0'};
    float c1, c2;
    short int d1, d2;
    long long int e1, e2;

    const char str[] = "$AmIIn%%sane? %\n\n\n \n \n \n\t   InF 0 %FIN9D-ME%";
    const char fstr[] = "%c%5s%%%*s %%  %G %hi %%FIN%lldDME%%";

    s21_sscanf(str, fstr, &a1, b1, &c1, &d1, &e1);
    sscanf(str, fstr, &a2, b2, &c2, &d2, &e2);
  }

  {
    char a1, a2;
    char b1, b2;
    char c1, c2;
    char d1, d2;

    const char str[] = "%%$Char!StressssT%%estus!&&&";
    const char fstr[] = "%% %*c%*c%*c%*c%*c %c %c %c %c ### %*c";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }

  {
    char a1, a2;
    char b1, b2;
    char c1, c2;
    char d1, d2;
    const char str[] =
        "%%$Char!StressssVIm User Aboba %% %%% %%% %% % % %% % "
        "% % %% % % %% %T%%estus!%%&&&";
    const char fstr[] =
        "%% %*c%*c%*c%*c%*c %c %c %c %c %% %% %% %% %% %% %% "
        "%% %% %% %% %% %% %% %% %% ### %*c";

    s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
    sscanf(str, fstr, &a2, &b2, &c2, &d2);
  }
}

void makefreeArr(char *str1, char *str2, int arrsize) {
  for (int i = 0; i < arrsize; i++) {
    str1[i] = 0;
    str2[i] = 0;
  }
}

void tc_s21_sprintf() {
  {
    char str1[100] = {'\0'};
    char str2[100] = {'\0'};

    sprintf(str1, "%s", "Hello");
    s21_sprintf(str2, "%s", "Hello");

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%.1s", "Hello");
    s21_sprintf(str2, "%.1s", "Hello");

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%7s", "Hello");
    s21_sprintf(str2, "%7s", "Hello");

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%-10s", "Hello");
    s21_sprintf(str2, "%-10s", "Hello");

    makefreeArr(str1, str2, 100);
  }

  {
    char str1[100] = {'\0'};
    char str2[100] = {'\0'};

    sprintf(str1, "%1c %c", 'H', 'z');
    s21_sprintf(str2, "%1c %c", 'H', 'z');

    makefreeArr(str1, str2, 50);

    sprintf(str1, "%10c %2c", 'H', 'z');
    s21_sprintf(str2, "%10c %2c", 'H', 'z');

    makefreeArr(str1, str2, 50);

    sprintf(str1, "%-1c %-c", 'H', 'z');
    s21_sprintf(str2, "%-1c %-c", 'H', 'z');

    makefreeArr(str1, str2, 50);
  }

  {
    char str1[255] = {'\0'};
    char str2[255] = {'\0'};

    sprintf(str1, "%12.16f %10.17f", 100000000000.14, 100000000000.14);
    s21_sprintf(str2, "%12.16f %10.17f", 100000000000.14, 100000000000.14);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%f", 100000.4);
    s21_sprintf(str2, "%f", 100000.4);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%.16f", -100000.4);
    s21_sprintf(str2, "%.16f", -100000.4);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%-1f", 100000.4);
    s21_sprintf(str2, "%-1f", 100000.4);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%f", -100000.4);
    s21_sprintf(str2, "%f", -100000.4);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%+f %+f", -100000.4, 1000.231);
    s21_sprintf(str2, "%+f %+f", -100000.4, 1000.231);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%-20f", 100000.4);
    s21_sprintf(str2, "%-20f", 100000.4);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%-+20f", 100000.4);
    s21_sprintf(str2, "%-+20f", 100000.4);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%-20f", -100000.4);
    s21_sprintf(str2, "%-20f", -100000.4);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%+20f", 100000.4);
    s21_sprintf(str2, "%+20f", 100000.4);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%+20f", -100000.4);
    s21_sprintf(str2, "%+20f", -100000.4);

    makefreeArr(str1, str2, 100);

    float key = 10000;
    sprintf(str1, "%+20f", key);
    s21_sprintf(str2, "%+20f", key);

    makefreeArr(str1, str2, 100);

    sprintf(str2, "%+34.10f%.10i%15.1d%25.10s", 25.3456, 1234, 4567,
            "HELLOMYDEARFRIEND");
    s21_sprintf(str1, "%+34.10f%.10i%15.1d%25.10s", 25.3456, 1234, 4567,
                "HELLOMYDEARFRIEND");

    makefreeArr(str1, str2, 255);
  }

  {
    char str1[100] = {'\0'};
    char str2[100] = {'\0'};

    sprintf(str1, "% 010d", 4);
    s21_sprintf(str2, "% 010d", 4);

    makefreeArr(str1, str2, 30);

    sprintf(str1, "% 010d", -4);
    s21_sprintf(str2, "% 010d", -4);

    makefreeArr(str1, str2, 30);

    sprintf(str1, "%-+10d", 4);
    s21_sprintf(str2, "%-+10d", 4);

    makefreeArr(str1, str2, 30);

    sprintf(str1, "%.d", 4);
    s21_sprintf(str2, "%.d", 4);

    makefreeArr(str1, str2, 30);

    sprintf(str1, "%.10d%%\n", 4);
    s21_sprintf(str2, "%.10d%%\n", 4);

    makefreeArr(str1, str2, 30);

    sprintf(str1, "%d%%\n", -4);
    s21_sprintf(str2, "%d%%\n", -4);

    makefreeArr(str1, str2, 30);

    sprintf(str1, "%-+10d%%\n", 4);
    s21_sprintf(str2, "%-+10d%%\n", 4);

    makefreeArr(str1, str2, 30);

    sprintf(str1, "%-10d%%\n", -4);
    s21_sprintf(str2, "%-10d%%\n", -4);

    makefreeArr(str1, str2, 30);

    sprintf(str1, "%+10d%%\n", 4);
    s21_sprintf(str2, "%+10d%%\n", 4);

    makefreeArr(str1, str2, 30);

    sprintf(str1, "%+10d%%\n", -4);
    s21_sprintf(str2, "%+10d%%\n", -4);

    makefreeArr(str1, str2, 30);

    sprintf(str1, "%+10.5d%%\n", -4);
    s21_sprintf(str2, "%+10.5d%%\n", -4);

    makefreeArr(str1, str2, 30);

    long int var_long = 100;
    sprintf(str1, "%ld%%\n", var_long);
    s21_sprintf(str2, "%ld%%\n", var_long);

    makefreeArr(str1, str2, 30);

    short var_short = 123;
    sprintf(str1, "%hd%%\n", var_short);
    s21_sprintf(str2, "%hd%%\n", var_short);

    makefreeArr(str1, str2, 30);

    sprintf(str2, "%+-25.3d%25.15d%10.f%15d", 252, 243, 256.34, 15);
    s21_sprintf(str1, "%+-25.3d%25.15d%10.f%15d", 252, 243, 256.34, 15);

    makefreeArr(str1, str2, 150);

    sprintf(str1, "%.i", 4);
    s21_sprintf(str2, "%.i", 4);

    makefreeArr(str1, str2, 30);

    sprintf(str1, "%.10i%%\n", 4);
    s21_sprintf(str2, "%.10i%%\n", 4);

    makefreeArr(str1, str2, 30);

    sprintf(str1, "% i%%\n", -4);
    s21_sprintf(str2, "% i%%\n", -4);

    makefreeArr(str1, str2, 30);

    sprintf(str1, "%-+10i%%\n", 4);
    s21_sprintf(str2, "%-+10i%%\n", 4);

    makefreeArr(str1, str2, 30);

    sprintf(str1, "%-10i%%\n", -4);
    s21_sprintf(str2, "%-10i%%\n", -4);

    makefreeArr(str1, str2, 30);

    sprintf(str1, "%+10i\n", 4);
    s21_sprintf(str2, "%+10i\n", 4);

    makefreeArr(str1, str2, 30);

    sprintf(str1, "%+10i\n", -4);
    s21_sprintf(str2, "%+10i\n", -4);

    makefreeArr(str1, str2, 30);

    sprintf(str1, "%+10.5i\n", -4);
    s21_sprintf(str2, "%+10.5i\n", -4);

    makefreeArr(str1, str2, 30);

    sprintf(str1, "%li%%\n", var_long);
    s21_sprintf(str2, "%li%%\n", var_long);

    makefreeArr(str1, str2, 30);
  }

  {
    char str1[100] = {'\0'};
    char str2[100] = {'\0'};

    sprintf(str1, "%2.5u%%\n", 4);
    s21_sprintf(str2, "%2.5u%%\n", 4);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%2.5u%%\n", -4);
    s21_sprintf(str2, "%2.5u%%\n", -4);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%10.5u%%\n", 4);
    s21_sprintf(str2, "%10.5u%%\n", 4);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%-10u%%\n", 421);
    s21_sprintf(str2, "%-10u%%\n", 421);

    makefreeArr(str1, str2, 100);

    short unsigned key_h = 421;
    sprintf(str1, "%-10hu%%\n", key_h);
    s21_sprintf(str2, "%-10hu%%\n", key_h);

    makefreeArr(str1, str2, 100);

    long unsigned key_l = 421;
    sprintf(str1, "%-10lu%%\n", key_l);
    s21_sprintf(str2, "%-10lu%%\n", key_l);

    makefreeArr(str1, str2, 100);
    char c[255] = {'\0'}, d[255] = {'\0'};
    s21_sprintf(c, "%10.s %10ls %-10ls %-3ls %.ls %.3ls %.10ls", "hello",
                L"hello", L"hello", L"hello", L"hello", L"hello", L"hello");
    sprintf(d, "%10.s %10ls %-10ls %-3ls %.ls %.3ls %.10ls", "hello", L"hello",
            L"hello", L"hello", L"hello", L"hello", L"hello");

    makefreeArr(c, d, 100);
  }

  {
    char str1[100] = {'\0'};
    char str2[100] = {'\0'};
    long double val = 15.35;
    long double val1 = 15.0000035;
    long double val2 = 15.00000000000000035;
    long double val3 = -15.35;

    sprintf(str1, "%#.16Le\n", val);
    s21_sprintf(str2, "%#.16Le\n", val);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%.0Le\n", val);
    s21_sprintf(str2, "%.0Le\n", val);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%.Le\n", val1);
    s21_sprintf(str2, "%.Le\n", val1);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%.15Le\n", val2);
    s21_sprintf(str2, "%.15Le\n", val2);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%10.16Le\n", val3);
    s21_sprintf(str2, "%10.16Le\n", val3);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%+10.6Le\n", val3);
    s21_sprintf(str2, "%+10.6Le\n", val3);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%-+*.*e\n", 10, 1, 15.01);
    s21_sprintf(str2, "%-+*.*e\n", 10, 1, 15.01);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%.16LE\n", val);
    s21_sprintf(str2, "%.16LE\n", val);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%.0LE\n", val);
    s21_sprintf(str2, "%.0LE\n", val);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%.LE\n", val1);
    s21_sprintf(str2, "%.LE\n", val1);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%.15LE\n", val2);
    s21_sprintf(str2, "%.15LE\n", val2);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%10.16LE\n", val3);
    s21_sprintf(str2, "%10.16LE\n", val3);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%+10.6LE\n", val3);
    s21_sprintf(str2, "%+10.6LE\n", val3);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%-+#*.*E\n", 10, 1, 15.01);
    s21_sprintf(str2, "%-+#*.*E\n", 10, 1, 15.01);

    makefreeArr(str1, str2, 100);
  }

  {
    char str1[100] = {'\0'};
    char str2[100] = {'\0'};

    sprintf(str1, "%#2.5o%%\n", 4);
    s21_sprintf(str2, "%#2.5o%%\n", 4);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%#2.5o%%\n", -4);
    s21_sprintf(str2, "%#2.5o%%\n", -4);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%10.5o%%\n", 4);
    s21_sprintf(str2, "%10.5o%%\n", 4);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%-10o%%\n", 421);
    s21_sprintf(str2, "%-10o%%\n", 421);

    makefreeArr(str1, str2, 100);

    short unsigned key_h = 421;
    sprintf(str1, "%-10ho%%\n", key_h);
    s21_sprintf(str2, "%-10ho%%\n", key_h);

    makefreeArr(str1, str2, 100);

    long unsigned key_l = 421;
    sprintf(str1, "%#-10lo%%\n", key_l);
    s21_sprintf(str2, "%-#10lo%%\n", key_l);

    makefreeArr(str1, str2, 100);
  }

  {
    char str1[100] = {'\0'};
    char str2[100] = {'\0'};

    sprintf(str1, "%2.5x%%\n", 4);
    s21_sprintf(str2, "%2.5x%%\n", 4);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%2.5x%%\n", -4);
    s21_sprintf(str2, "%2.5x%%\n", -4);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%10.5x%%\n", 4);
    s21_sprintf(str2, "%10.5x%%\n", 4);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%-10x%%\n", 421);
    s21_sprintf(str2, "%-10x%%\n", 421);

    makefreeArr(str1, str2, 100);

    short unsigned key_h = 421;
    sprintf(str1, "%-10hx%%\n", key_h);
    s21_sprintf(str2, "%-10hx%%\n", key_h);

    makefreeArr(str1, str2, 100);

    long unsigned key_l = 421;
    sprintf(str1, "%#-10lx%%\n", key_l);
    s21_sprintf(str2, "%-#10lx%%\n", key_l);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%2.5X%%\n", 4);
    s21_sprintf(str2, "%2.5X%%\n", 4);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%2.5X%%\n", -4);
    s21_sprintf(str2, "%2.5X%%\n", -4);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%10.5X%%\n", 4);
    s21_sprintf(str2, "%10.5X%%\n", 4);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%#-10X%%\n", 421);
    s21_sprintf(str2, "%#-10X%%\n", 421);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%-10hX%%\n", key_h);
    s21_sprintf(str2, "%-10hX%%\n", key_h);

    makefreeArr(str1, str2, 100);

    sprintf(str1, "%-10lX%%\n", key_l);
    s21_sprintf(str2, "%-10lX%%\n", key_l);

    makefreeArr(str1, str2, 100);
  }

  {
    char str1[100] = {'\0'};
    char str2[100] = {'\0'};

    char *format = "%p";

    s21_sprintf(str2, format, format);

    makefreeArr(str1, str2, 100);

    format = "%15p";

    s21_sprintf(str2, format, format);

    makefreeArr(str1, str2, 100);

    format = "%.5p";

    s21_sprintf(str2, format, format);

    makefreeArr(str1, str2, 100);
  }

  {
    char str1[100] = {'\0'};
    char str2[100] = {'\0'};
    int ptr = 0;
    char *format = "Hello\n asd%n\n";

    s21_sprintf(str2, format, &ptr);

    makefreeArr(str1, str2, 100);
  }
}

int main(void) {
  tc_s21_memcmp();
  tc_s21_memcpy();
  tc_s21_memchr1();
  tc_s21_memchr2();
  tc_s21_memchr3();
  tc_s21_memcmp1();
  tc_s21_memcmp2();
  tc_s21_memcmp3();
  tc_s21_memcpy1();
  tc_s21_memmove();
  tc_s21_memset();
  tc_s21_strcat();
  tc_s21_strncat();
  tc_s21_strchr();
  tc_s21_strcmp();
  tc_s21_strncmp();
  tc_s21_strcpy();
  tc_s21_strncpy();
  tc_s21_strcspn();
  tc_s21_strerror();
  tc_s21_strlen();
  tc_s21_strpbrk();
  tc_s21_strrchr();
  tc_s21_strspn();
  tc_s21_strstr();
  tc_s21_strtok();
  tc_s21_sscanf();
  tc_s21_sprintf();
  tc_s21_upper();
  tc_s21_lower();
  tc_s21_insert();
  tc_s21_trim();

  return 0;
}
