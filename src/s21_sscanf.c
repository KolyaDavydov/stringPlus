#include "s21_string.h"

int is_spec_start(char ch) { return ch == '%'; }

int parse_spec(sp_t *spec, char *fmt) {
  int bytes_readed = 1;
  char width[16] = {0};

  if (*(++fmt) == '*') {
    spec->suppress = TRUE;
    bytes_readed++;
    fmt++;
  }

  if (get_digit_substr(width, fmt, 16, 0, PUSHREG)) {
    spec->width = parse_int(width);
    int len = s21_strlen(width);
    bytes_readed += len;
    fmt += len;
  }

  switch (*fmt) {
    case 'h': {
      if (*(fmt + 1) == 'h') {
        spec->length = hh;
        bytes_readed += 2;
        fmt += 2;
      } else {
        spec->length = h;

        bytes_readed++;
        fmt++;
      }
      break;
    }
    case 'l': {
      if (*(fmt + 1) == 'l') {
        spec->length = ll;
        bytes_readed += 2;
        fmt += 2;
      } else {
        spec->length = l;
        bytes_readed++;
        fmt++;
      }
      break;
    }
    case 'L':
      spec->length = L;
      bytes_readed++;
      fmt++;
      break;
    default:
      spec->length = nil;
      break;
  }

  switch (*fmt) {
    case 'c':
      spec->sp = c;
      break;
    case 'd':
      spec->sp = d;
      break;
    case 'i':
      spec->sp = i;
      break;
    case 'e':
      spec->sp = e;
      break;
    case 'E':
      spec->sp = E;
      break;
    case 'f':
      spec->sp = f;
      break;
    case 'g':
      spec->sp = g;
      break;
    case 'G':
      spec->sp = G;
      break;
    case 'o':
      spec->sp = o;
      break;
    case 's':
      spec->sp = s;
      break;
    case 'u':
      spec->sp = u;
      break;
    case 'x':
      spec->sp = x;
      break;
    case 'X':
      spec->sp = X;
      break;
    case 'p':
      spec->sp = p;
      break;
    case 'n':
      spec->sp = n;
      break;
    case '%':
      spec->sp = spec_ch;
      break;
  }

  bytes_readed++;
  return bytes_readed;
}

int exec_spec(sp_t *spec, va_list *vl, char *str, int bytes_scanned,
              int *result) {
  int res = 0, skipped = 0;
  if (spec->sp != c) skipped = skip_whitespace(&str);
  switch (spec->sp) {
    case c:
      res = set_char(vl, spec, str[0], result);
      break;
    case d:
      res = set_int(vl, spec, str, result, PUSHREG, TRUE);
      break;
    case i:
      res = set_int(vl, spec, str, result, PUSHEXT, TRUE);
      break;
    case e:
      res = set_float(vl, spec, str, result, PUSHFLT);
      break;
    case E:
      res = set_float(vl, spec, str, result, PUSHFLT);
      break;
    case f:
      res = set_float(vl, spec, str, result, PUSHFLT);
      break;
    case g:
      res = set_float(vl, spec, str, result, PUSHFLT);
      break;
    case G:
      res = set_float(vl, spec, str, result, PUSHFLT);
      break;
    case o:
      res = set_int(vl, spec, str, result, PUSHOCT, TRUE);
      break;
    case s:
      res = set_string(vl, spec, str, result);
      break;
    case u:
      res = set_int(vl, spec, str, result, PUSHREG, FALSE);
      break;
    case x:
      res = set_hex(vl, spec, str, result, PUSHHEX);
      break;
    case X:
      res = set_hex(vl, spec, str, result, PUSHHEX);
      break;
    case p:
      res = set_pointer(vl, spec, str, result, PUSHEXT);
      break;
    case n:
      set_bscan(vl, spec, bytes_scanned, result);
      break;
      break;
    case spec_ch:
      res = handle_spec_char(str, result);
      break;
  }

  return res + skipped;
}

int set_char(va_list *vl, sp_t *spec, char ch, int *result) {
  if (!spec->suppress) {
    if (spec->length == l) {
      SET_VALUE(wchar_t, ch, vl);
    } else {
      SET_VALUE(char, ch, vl);
    }
    incr_res(result);
  } else if (spec->suppress) {
    if (*result < 0) *result = 0;
  }

  return 1;
}

int set_int(va_list *vl, sp_t *spec, char *str, int *result, int mode,
            bool_t is_signed) {
  char buf[32] = {0};
  if (s21_strlen(str) == 0) return 0;
  int digits = get_digit_substr(buf, str, 32, spec->width, mode);
  if (digits == -1) {
    digits = s21_strlen(str) + 1;
    if (*result < 0) *result = 0;
  } else if (digits && !spec->suppress) {
    switch (spec->length) {
      case h: {
        if (is_signed) {
          SET_INTEGER(short, vl, buf, mode);
        } else {
          SET_INTEGER(unsigned short, vl, buf, mode);
        }
      } break;
      case hh: {
        if (is_signed) {
          SET_INTEGER(char, vl, buf, mode);
        } else {
          SET_INTEGER(unsigned char, vl, buf, mode);
        }
      } break;
      case l: {
        if (is_signed) {
          SET_INTEGER(long, vl, buf, mode);
        } else {
          SET_INTEGER(unsigned long, vl, buf, mode);
        }
      } break;
      case ll: {
        if (is_signed) {
          SET_INTEGER(long long, vl, buf, mode);
        } else {
          SET_INTEGER(unsigned long long, vl, buf, mode);
        }
      } break;
      default: {
        if (is_signed) {
          SET_INTEGER(int, vl, buf, mode);
        } else {
          SET_INTEGER(unsigned int, vl, buf, mode);
        }
      } break;
    }

    incr_res(result);
  }
  if (*result < 0) *result = 0;

  return digits;
}

int set_float(va_list *vl, sp_t *spec, char *str, int *result, int mode) {
  char buf[32] = {0};
  int digits = get_digit_substr(buf, str, 32, spec->width, mode);
  if (digits == -1) {
    digits = s21_strlen(str) + 1;
    if (*result < 0) *result = 0;
  } else if (digits && !spec->suppress) {
    switch (spec->length) {
      case L: {
        long double *digit = va_arg(*vl, long double *);
        long double v = matold(buf);
        *digit = get_ldex(buf, v);
      } break;
      case l: {
        double *digit = va_arg(*vl, double *);
        double v = (double)matold(buf);
        *digit = (double)get_ldex(buf, v);
      } break;
      default: {
        float *digit = va_arg(*vl, float *);
        float v = (float)matold(buf);
        *digit = (float)get_ldex(buf, v);
      } break;
    }
    incr_res(result);
  } else if (spec->suppress) {
    if (*result < 0) *result = 0;
  }

  return digits;
}

int set_string(va_list *vl, sp_t *spec, char *str, int *result) {
  int bytes_w = 0;
  for (; *str && skip_char(*str); str++) bytes_w++;

  if (!spec->suppress) {
    char *ptr = va_arg(*vl, char *);
    char *p = ptr;

    if (spec->width) {
      for (; *str && !skip_char(*str) && bytes_w < spec->width; str++, p++) {
        *p = *str;
        bytes_w++;
      }
      if (skip_char(*str)) bytes_w++;
    } else {
      for (; *str && !skip_char(*str); str++, p++) {
        *p = *str;
        bytes_w++;
      }
      if (skip_char(*str)) bytes_w++;
    }
    if (bytes_w) incr_res(result);
  } else if (spec->suppress) {
    for (; *str && !skip_char(*str); str++) bytes_w++;
    if (skip_char(*str)) bytes_w++;
    if (*result < 0) *result = 0;
  }

  return bytes_w;
}

#include <stdio.h>

int set_hex(va_list *vl, sp_t *spec, char *str, int *result, int mode) {
  char buf[32] = {0};
  int digits = get_digit_substr(buf, str, 32, spec->width, mode);
  if (digits == -1) {
    digits = s21_strlen(str) + 1;
    if (*result < 0) *result = 0;
  } else if (digits && !spec->suppress) {
    switch (spec->length) {
      case h: {
        SET_HEX(short, vl, buf);
      } break;
      case l: {
        SET_HEX(long, vl, buf);
      } break;
      case ll: {
        SET_HEX(long long, vl, buf);
      } break;
      default: {
        SET_HEX(int, vl, buf);
      } break;
    }
    incr_res(result);
  } else {
    if (*result < 0) *result = 0;
  }

  return digits;
}

int set_pointer(va_list *vl, sp_t *spec, char *str, int *result, int mode) {
  char buf[32] = {0};
  int digits = get_digit_substr(buf, str, 32, spec->width, mode);
  if (digits == -1) {
    digits = s21_strlen(str) + 1;
  } else if (digits && !spec->suppress) {
    void **digit = va_arg(*vl, void **);
    long long parsed = htod(buf);

    *digit = (void *)parsed;
    incr_res(result);
  } else {
    if (*result < 0) *result = 0;
  }

  return digits;
}

void set_bscan(va_list *vl, sp_t *spec, int bscanned, int *result) {
  if (*result < 0) *result = 0;
  switch (spec->length) {
    case h: {
      SET_VALUE(short, bscanned, vl);
    } break;
    case hh: {
      SET_VALUE(char, bscanned, vl);
    } break;
    case l: {
      SET_VALUE(long, bscanned, vl);
    } break;
    case ll: {
      SET_VALUE(long long, bscanned, vl);
    } break;
    default: {
      SET_VALUE(int, bscanned, vl);
    } break;
  }
}

int handle_spec_char(const char *str, int *result) {
  int res = 0;
  if (*str == '%') {
    res = 1;
    if (*result < 0) *result = 0;
  }
  return res;
}

bool_t is_space(char ch) { return ch == ' '; }

bool_t skip_char(char ch) {
  return ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r';
}

int skip_whitespace(char **str) {
  int skipped = 0;
  while (skip_char(**str)) {
    ++*str;
    skipped++;
  }

  return skipped;
}

bool_t is_hex_prefixed(const char *str) {
  return (s21_strlen(str) > 2 && *str == '0' &&
          (*(str + 1) == 'x' || *(str + 1) == 'X'));
}

bool_t is_hex(const char *str) {
  bool_t res = FALSE;

  if (is_hex_prefixed(str)) {
    for (; *str; str++) {
      if ((*str >= '0' && *str <= '9') || (*str >= 'a' && *str <= 'f') ||
          (*str >= 'A' && *str <= 'F')) {
        res = TRUE;
        break;
      }
    }
  }

  return res;
}

int get_digit_substr(char *dest, char *str, int n, int width, int mode) {
  int len = 0;
  bool_t can_skip = FALSE;

  while (is_space(*str)) ++str;
  if (*str == '-' || *str == '+') dest[len++] = *str++;
  if ((mode == PUSHEXT || mode == PUSHHEX) && is_hex_prefixed(str)) {
    dest[len++] = *str++;
    dest[len++] = *str++;
  }

  if (mode == PUSHFLT && check_nan(str)) {
    dest = s21_strncpy(&dest[len], "nan", 3);
    len += 3;
    can_skip = TRUE;
  } else if (mode == PUSHFLT && check_inf(str)) {
    dest = s21_strncpy(&dest[len], "inf", 3);
    len += 3;
    can_skip = TRUE;
  }

  if (!can_skip) {
    if (width) {
      for (; *str && dest != s21_NULL && len < width && len < n; str++)
        if (!push_digit(dest, *str, &len, mode)) break;
    } else {
      for (; *str && dest != s21_NULL && len < n; str++)
        if (!push_digit(dest, *str, &len, mode)) break;
    }
  }

  if (mode != PUSHHEX) {
    if (len == 1 && (dest[len - 1] < '0' || dest[len - 1] > '9')) len = -1;
  } else {
    if (len == 1 && ((dest[len - 1] < '0' || dest[len - 1] > '9') &&
                     (dest[len - 1] < 'a' || dest[len - 1] > 'f') &&
                     (dest[len - 1] < 'A' || dest[len - 1] > 'F')))
      len = -1;
  }
  return len;
}

bool_t push_digit(char *dest, char digit, int *len, int mode) {
  bool_t is_digit = TRUE;

  switch (mode) {
    case PUSHREG:
      if (digit >= '0' && digit <= '9')
        dest[(*len)++] = digit;
      else
        is_digit = FALSE;
      break;
    case PUSHOCT:
      if (digit >= '0' && digit <= '7')
        dest[(*len)++] = digit;
      else
        is_digit = FALSE;

      break;
    case PUSHEXT:
    case PUSHHEX:
      if ((digit >= '0' && digit <= '9') || (digit >= 'a' && digit <= 'f') ||
          (digit >= 'A' && digit <= 'F'))
        dest[(*len)++] = digit;
      else
        is_digit = FALSE;
      break;
    case PUSHFLT:
      if ((digit >= '0' && digit <= '9') || digit == '.' || digit == 'e' ||
          digit == '+' || digit == '-')
        dest[(*len)++] = digit;
      else
        is_digit = FALSE;
      break;
  }

  return is_digit;
}

int parse_int(char *input) {
  int result = 0;

  for (; *input; input++)
    if (*input >= '0' && *input <= '9')
      result = (result * 10) + (int)(*input - 48);

  return result;
}

long double parse_digits(const char **str, int *const count) {
  long double value = 0.0f;
  int c = 0;
  while (**str >= '0' && **str <= '9') {
    value = value * 10.0f + (*(*str)++ - '0');
    c++;
  }
  if (count) *count = c;
  return value;
}

long double matold(const char *str) {
  const int sign = parse_sign(&str);
  long double value = parse_digits(&str, NULL);

  if (*str == '.') {
    int digits = 0;
    str++;
    long double fraction = parse_digits(&str, &digits);
    while (digits--) fraction /= 10.0f;
    value += fraction;
  }

  if (!sign) value = -value;
  if (to_clower(*str++) == 'e') {
    const long double exponent_sign = parse_sign(&str) ? 10. : .1;
    int exponent = parse_digits(&str, NULL);
    while (exponent--) value *= exponent_sign;
  }

  return value;
}

long long otod(char *src) {
  int parsed = 0;
  long long sign = !parse_sign((const char **)&src) ? -1 : 1;
  if (src != NULL) {
    int power = s21_strlen(src) - 1;
    while (*src) parsed += (*(src++) - 48) * pow(8, power--);
  }
  return parsed * sign;
}

long long htod(char *src) {
  long long parsed = 0, base = 1;
  long long sign = !parse_sign((const char **)&src) ? -1 : 1;
  if (is_hex_prefixed(src)) src += 2;
  s21_size_t len = s21_strlen(src);
  for (int i = (int)len--; i >= 0; i--) {
    if (src[i] >= '0' && src[i] <= '9') {
      parsed += (src[i] - 48) * base;
      base *= 16;
    } else if (src[i] >= 'A' && src[i] <= 'F') {
      parsed += (src[i] - 55) * base;
      base *= 16;
    } else if (src[i] >= 'a' && src[i] <= 'f') {
      parsed += (src[i] - 87) * base;
      base *= 16;
    }
  }
  return parsed * sign;
}

long long hoatod(char *src, int mode) {
  long long parsed = 0;
  long long sign = !parse_sign((const char **)&src) ? -1 : 1;
  if (is_hex(src)) {
    parsed = htod(src);
  } else if (*src == '0' || mode == PUSHOCT) {
    if (mode != PUSHOCT) src++;
    parsed = otod(src);
  } else {
    for (; *src; src++)
      if (*src >= '0' && *src <= '9') parsed = (parsed * 10) + (*src - 48);
  }
  return parsed * sign;
}

bool_t parse_sign(const char **str) {
  switch (**str) {
    case '-':
      ++*str;
      return FALSE;
    case '+':
      ++*str;
      return TRUE;
    default:
      return TRUE;
  }
}

bool_t check_nan(char *str) {
  bool_t is_nan = FALSE;
  char buf[8] = {0};
  char *buf_p = s21_strncpy(buf, str, 3);
  to_strlower(buf);
  if (!s21_strncmp(buf_p, "nan", 3)) is_nan = TRUE;
  return is_nan;
}

bool_t check_inf(char *str) {
  bool_t is_inf = FALSE;
  char buf[8] = {0};
  char *buf_p = s21_strncpy(buf, str, 3);
  to_strlower(buf);
  if (!s21_strncmp(buf_p, "inf", 3)) is_inf = TRUE;
  return is_inf;
}

long double get_ldex(const char *str, long double v) {
  if (check_nan((char *)str))
    return 0.0f / 0.0f;
  else if (check_inf((char *)str))
    return 1.0f / 0.0f;
  else
    return v;
}

char to_clower(char ch) {
  return (ch >= 'A' && ch <= 'Z') ? (ch - 65) + 97 : ch;
}

void to_strlower(char *str) {
  for (; *str && str != s21_NULL; str++)
    if (*str >= 'A' && *str <= 'Z') *str = (*str - 65) + 97;
}

void incr_res(int *res) { *res > 0 ? (*res)++ : (*res = 1); }
