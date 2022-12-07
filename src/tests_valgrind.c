#include <stdint.h>
#include <stdio.h>

#include "s21_string.h"

#define BUFF_SIZE 512

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

int main(void) {
  tc_s21_memcmp();
  tc_s21_memcpy();
  tc_s21_memmove();
  tc_s21_sscanf();
  return 0;
}
