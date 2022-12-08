#include "s21_string.h"

int parser(sprint_t *spec, const char *format, va_list vl) {
  int ptr_format = 0;  // количество считанных символов с 'format'

  // Парсим флаг
  int tmp = 0;
  tmp = flag_parser(spec, format);
  ptr_format += tmp;
  format += tmp;

  // парсим ширину
  tmp = 0;
  tmp = width_parser(spec, format, vl);
  ptr_format += tmp;
  format += tmp;

  // парсим точность
  tmp = 0;
  tmp = precision_parser(spec, format, vl);
  ptr_format += tmp;
  format += tmp;

  // парсим длину
  tmp = 0;
  tmp = length_parser(spec, format);
  ptr_format += tmp;
  format += tmp;

  // парсим спецификатор
  tmp = 0;
  tmp = specifier_parser(spec, format);
  ptr_format += tmp;
  format += tmp;

  return ptr_format;
}

// парсер флага, возвращает сколько флагов и прочего считал
int flag_parser(sprint_t *spec, const char *format) {
  int ptr_format = 0;
  const char *tmp_format = format;
  while (*tmp_format == '-' || *tmp_format == '+' || *tmp_format == ' ' ||
         *tmp_format == '0' || *tmp_format == '#') {
    if (*tmp_format == '-') spec->minus = TRUE, ptr_format++;
    if (*tmp_format == '+') spec->plus = TRUE, ptr_format++;
    if (*tmp_format == ' ') spec->space = TRUE, ptr_format++;
    if (*tmp_format == '#') spec->lattice = TRUE, ptr_format++;
    if (*tmp_format == '0') spec->zero = TRUE, ptr_format++;
    tmp_format++;
  }
  return ptr_format;
}

// Минимальное количество печатаемых символов.
// Если выводимое значение короче этого числа,
// результат дополняется пробелами.
//Значение не усекается, даже если результат больше.
int width_parser(sprint_t *spec, const char *format, va_list vl) {
  int ptr_format = 0;
  const char *tmp_format = format;
  int width = 0;
  if (*tmp_format == '*') {
    format++;
    spec->width = va_arg(vl, int);
    // spec->width_in_args = TRUE;printf
    // tmp_format++;
    ptr_format++;
  }
  if (*tmp_format >= '1' && *tmp_format <= '9') {
    while (*tmp_format >= '0' && *tmp_format <= '9') {
      width *= 10;
      width += *tmp_format - '0';
      tmp_format++;
      ptr_format++;
    }
    spec->width = width;
  }
  return ptr_format;
}

int precision_parser(sprint_t *spec, const char *format, va_list vl) {
  int ptr_format = 0;
  const char *tmp_format = format;
  int precision = 0;

  if (*tmp_format == '.') {
    spec->precision_is_set = TRUE;
    tmp_format++;
    ptr_format++;
  }
  if (*tmp_format == '*') {
    spec->precision = va_arg(vl, int);
    tmp_format++;
    ptr_format++;
  }
  if (*tmp_format >= '0' && *tmp_format <= '9') {
    while (*tmp_format >= '0' && *tmp_format <= '9') {
      precision *= 10;
      precision += *tmp_format - '0';
      tmp_format++;
      ptr_format++;
    }
    spec->precision = precision;
  }
  return ptr_format;
}

int length_parser(sprint_t *spec, const char *format) {
  int ptr_format = 0;
  const char *tmp_format = format;

  switch (*tmp_format) {
    case 'h': {
      spec->length = _h;
      ptr_format++;

      break;
    }
    case 'l': {
      spec->length = _l;
      ptr_format++;

      break;
    }
    case 'L':
      spec->length = _L;
      ptr_format++;
      break;
  }
  return ptr_format;
}

int specifier_parser(sprint_t *spec, const char *format) {
  int ptr_format = 0;

  switch (*format) {
    case 'c':
      spec->sp = c;
      ptr_format++;
      break;
    case 'd':
      spec->sp = d;
      ptr_format++;
      break;
    case 'i':
      spec->sp = i;
      ptr_format++;
      break;
    case 'e':
      spec->sp = e;
      ptr_format++;
      break;
    case 'E':
      spec->sp = E;
      ptr_format++;
      break;
    case 'f':
      spec->sp = f;
      ptr_format++;
      break;
    case 'g':
      spec->sp = g;
      ptr_format++;
      break;
    case 'G':
      spec->sp = G;
      ptr_format++;
      break;
    case 'o':
      spec->sp = o;
      ptr_format++;
      break;
    case 's':
      spec->sp = s;
      ptr_format++;
      break;
    case 'u':
      spec->sp = u;
      ptr_format++;
      break;
    case 'x':
      spec->sp = x;
      ptr_format++;
      break;
    case 'X':
      spec->sp = X;
      ptr_format++;
      break;
    case 'p':
      spec->sp = p;
      ptr_format++;
      break;
    case 'n':
      spec->sp = n;
      ptr_format++;
      break;
    case '%':
      spec->sp = percent;
      ptr_format++;
      break;
  }
  return ptr_format;
}

void transfer_to_str(sprint_t spec, va_list vl, char *tmp_str) {
  switch (spec.sp) {
    case c:
      _set_char(spec, vl, tmp_str);
      break;
    case d:
      _set_int(spec, vl, tmp_str);
      break;
    case i:
      _set_int(spec, vl, tmp_str);
      break;
    case e:
      set_exponent(spec, vl, tmp_str);
      break;
    case E:
      set_exponent(spec, vl, tmp_str);
      break;
    case f:
      set_double(spec, vl, tmp_str);
      break;
    case g:
      set_g_G(spec, vl, tmp_str);
      break;
    case G:
      set_g_G(spec, vl, tmp_str);
      break;
    case o:
      set_oct_and_hex(spec, vl, tmp_str);
      break;
    case s:
      set_str(spec, vl, tmp_str);
      break;
    case u:
      set_oct_and_hex(spec, vl, tmp_str);
      break;
    case x:
      set_oct_and_hex(spec, vl, tmp_str);
      break;
    case X:
      set_oct_and_hex(spec, vl, tmp_str);
      break;
    case p:
      _set_pointer(spec, vl, tmp_str);
      break;
    case n:
      (void)0;
      break;
    case percent:
      tmp_str[0] = '%';
      break;
  }
}

void _set_char(sprint_t spec, va_list vl, char *tmp_str) {
  char c = va_arg(vl, int);

  if (spec.width && !spec.minus) {
    for (int i = 0; i < spec.width; i++) {
      tmp_str[i] = ' ';
      if (i == spec.width - 1) tmp_str[i] = c;
    }
  } else if (spec.width) {
    tmp_str[0] = c;
    for (int i = 1; i < spec.width; i++) {
      tmp_str[i] = ' ';
    }
  } else {
    tmp_str[0] = c;
  }
}

void _set_int(sprint_t spec, va_list vl, char *tmp_str) {
  int64_t num = va_arg(vl, int64_t);

  if (spec.length == _l) {
    num = (int64_t)num;
  } else if (spec.length == _h) {
    num = (int16_t)num;
  } else {
    num = (int32_t)num;
  }

  num_to_str(num, tmp_str, 10);
  edit_precision(spec, tmp_str);
  edit_flag(spec, tmp_str);
}

void set_double(sprint_t spec, va_list vl, char *tmp_str) {
  long double number = 0;

  if (spec.length == _L)
    number = va_arg(vl, long double);
  else
    number = va_arg(vl, double);

  if (!spec.precision_is_set) spec.precision = 6;

  double_to_str(number, tmp_str, spec);
  edit_flag(spec, tmp_str);
}

void set_oct_and_hex(sprint_t spec, va_list vl, char *tmp_str) {
  uint64_t num = va_arg(vl, uint64_t);

  if (spec.length == _h) {
    num = (uint16_t)num;
  } else if (spec.length == _l) {
    num = (uint64_t)num;
  } else {
    num = (uint32_t)num;
  }

  if (spec.sp == o) {
    nonsign_num_to_str(num, tmp_str, spec, 8);
  } else if (spec.sp == x || spec.sp == X) {
    nonsign_num_to_str(num, tmp_str, spec, 16);
  } else if (spec.sp == u) {
    nonsign_num_to_str(num, tmp_str, spec, 10);
  }

  edit_flag(spec, tmp_str);
}

// перевод беззнакового числа в строку
void nonsign_num_to_str(uint64_t num, char *tmp_str, sprint_t spec,
                        int type_num) {
  char buff[100] = {'\0'};
  int cell_buff = 98;

  if (num == 0) buff[cell_buff] = '0';

  int val = num;

  while (num > 0) {
    cell_buff--;

    if (spec.sp == X) {
      buff[cell_buff] = "0123456789ABCDEF"[num % type_num];
    } else {
      buff[cell_buff] = "0123456789abcdef"[num % type_num];
    }

    num /= type_num;
  }

  int v = cell_buff;
  char t[100] = {'\0'};
  for (int i = 0; buff[v]; v++, i++) {
    t[i] = buff[v];
  }

  edit_precision(spec, t);

  if (spec.lattice && spec.sp == o && val != 0 &&
      spec.precision < (int)s21_strlen(t)) {
    tmp_str[0] = '0';
  } else if ((spec.lattice && spec.sp == x && val != 0) || spec.sp == p) {
    tmp_str[1] = 'x';
    tmp_str[0] = '0';
  } else if (spec.lattice && spec.sp == X && val != 0) {
    tmp_str[1] = 'X';
    tmp_str[0] = '0';
  }

  s21_strcat(tmp_str, t);
}

void set_str(sprint_t spec, va_list vl, char *tmp_str) {
  char str[200] = {'\0'};
  char tmp_w[200] = {'\0'};

  if (spec.length == _l) {
    wchar_t *wtmp = va_arg(vl, wchar_t *);
    wcstombs(tmp_w, wtmp, 200);
    s21_strcpy(str, tmp_w);
  } else {
    char *tmp = va_arg(vl, char *);
    s21_strcpy(str, tmp);
  }

  if (spec.precision_is_set) str[spec.precision] = '\0';

  int length_str = s21_strlen(str);
  int width_str_len = spec.width - length_str;

  //если задана ширина и она больше длины строки
  if (spec.minus && width_str_len > 0) {
    s21_strcpy(tmp_str, str);
    s21_memset(tmp_str + length_str, ' ', width_str_len);
  } else if (width_str_len > 0) {
    s21_memset(tmp_str, ' ', width_str_len);
    s21_strcpy(tmp_str + width_str_len, str);
  } else {
    s21_strcpy(tmp_str, str);
  }
}

void _set_pointer(sprint_t spec, va_list vl, char *tmp_str) {
  uint64_t pointer = va_arg(vl, uint64_t);

  if (!pointer) {
#if defined(__linux__)
    char *nil = "(nil)";
#elif (__APPLE__)
    char *nil = "0x0";
#endif
    for (int i = 0; *nil; nil++, i++) {
      tmp_str[i] = *nil;
    }
  } else {
    nonsign_num_to_str(pointer, tmp_str, spec, 16);
  }

  edit_flag(spec, tmp_str);
}

void set_exponent(sprint_t spec, va_list vl, char *tmp_str) {
  long double number = 0;

  if (spec.length == _L)
    number = va_arg(vl, long double);
  else
    number = va_arg(vl, double);

  int pow = 0;

  char sign_of_pow = (int)number == 0 ? '-' : '+';

  if ((int)number - number) {
    while ((int)number == 0) {
      pow++;
      number *= 10;
    }
  } else {
    sign_of_pow = '+';
  }

  while ((int)number / 10 != 0) {
    pow++;
    number /= 10;
  }

  if (!spec.precision_is_set) spec.precision = 6;

  double_to_str(number, tmp_str, spec);
  mantiss_to_str(pow, tmp_str, sign_of_pow, spec);
  edit_flag(spec, tmp_str);
}

void set_g_G(sprint_t spec, va_list vl, char *tmp_str) {
  long double val = 0;

  if (spec.length == _L) {
    val = va_arg(vl, long double);

  } else {
    val = va_arg(vl, double);
  }

  if (!spec.precision_is_set) {
    spec.precision = 6;
  }
  if (spec.precision == 0) spec.precision = 1;
  int precision = spec.precision;
  long double m_val = val;
  int pow = 0;
  if ((int)val - val) {
    while ((int)m_val == 0) {
      pow++;
      m_val *= 10;
    }
  }
  if (pow > 4) {
    spec.precision = 0;
    double_to_str(m_val, tmp_str, spec);
  } else {
    spec.precision = 10;
    double_to_str(val, tmp_str, spec);
  }
  format_gG_precision(tmp_str, precision);

  char sign_of_pow = '-';

  if (pow > 4) {
    mantiss_to_str(pow, tmp_str, sign_of_pow, spec);
  }

  //удаляем концевые нули
  int len = s21_strlen(tmp_str);
  char *dot = s21_strchr(tmp_str, '.');
  if (dot) {
    for (int i = len - 1; tmp_str[i] != '.'; i--) {
      if (tmp_str[i] == '0')
        tmp_str[i] = '\0';
      else
        break;
    }
    if (dot[1] == '\0') dot[0] = '\0';
  }

  edit_flag(spec, tmp_str);
}

void format_gG_precision(char *buff, int precision) {
  int sig_digs = 0;
  s21_size_t len = s21_strlen(buff);
  int not_zero_found = 0;
  for (s21_size_t i = 0; i < s21_strlen(buff); i++) {
    if ((buff[i] == '0' && !not_zero_found) || buff[i] == '.')
      continue;
    else
      not_zero_found = 1;

    if (s21_isdigit(buff[i]) && not_zero_found) {
      sig_digs++;
    }
    if (sig_digs == precision && i + 1 < len) {
      int next = buff[i + 1] == '.' ? 2 : 1;
      buff[i] = buff[i + next] - '0' > 5 ? (char)(buff[i] + 1) : buff[i];
      buff[i + 1] = '\0';
      break;
    }
  }
}

int s21_isdigit(char c) { return (c >= '0' && c <= '9'); }

void mantiss_to_str(int pow, char *tmp_str, char sign_of_pow, sprint_t spec) {
  int len_tmp_str = s21_strlen(tmp_str);

  if (spec.sp == E || spec.sp == G)
    tmp_str[len_tmp_str] = 'E';
  else
    tmp_str[len_tmp_str] = 'e';

  tmp_str[len_tmp_str + 1] = sign_of_pow;
  tmp_str[len_tmp_str + 3] = '0' + pow % 10;
  pow /= 10;
  tmp_str[len_tmp_str + 2] = '0' + pow % 10;
  tmp_str[len_tmp_str + 4] = '\0';
}

void double_to_str(long double number, char *tmp_str, sprint_t spec) {
  char buff[200] = {'\0'};
  int cell_buff = 98;
  int is_negative = number < 0 ? 1 : 0;
  number = is_negative ? number * -1 : number;

  // выносим целую часть в переменную part_int
  // остаток возвращаем в frac_part
  long double part_int = 0;
  long double frac_part = modfl(number, &part_int);

  // если значение точности 0, то округляем до целого для f, e, E
  if (spec.precision == 0) {
    part_int = roundl(number);
    frac_part = 0;
  }
  //  printf("number is - %s\n", buff + cell_buff + 1);
  // Записываем дробну часть в строку
  char frac_part_to_str[100] = {'\0'};
  for (int i = 0; i < spec.precision; i++) {
    frac_part = frac_part * 10;
    frac_part_to_str[i] = (int)frac_part + '0';
  }

  long long right = roundl(frac_part);
  long long left = part_int;

  // если в дробной части 0, то заносим нули в соответвтсии с точностью
  // buff заполняем с конца
  if (!right) {
    for (int i = 0; i < spec.precision; cell_buff--, i++) buff[cell_buff] = '0';
  } else {
    for (int i = s21_strlen(frac_part_to_str); right || i > 0;
         right /= 10, cell_buff--, i--)
      buff[cell_buff] = '0' + (int)(right % 10 + 0.05);
  }

  if ((spec.precision_is_set && spec.precision != 0) || (int)frac_part ||
      (!spec.precision_is_set && number == 0) || s21_strlen(frac_part_to_str))
    buff[cell_buff--] = '.';
  if (!left) {
    buff[cell_buff] = '0';
    cell_buff--;
  } else {
    for (; left; left /= 10, cell_buff--)
      buff[cell_buff] = '0' + (int)(left % 10);
  }

  for (int i = 0; buff[cell_buff + 1]; cell_buff++, i++) {
    if (is_negative && i == 0) {
      tmp_str[i] = '-';
      i++;
    }
    tmp_str[i] = buff[cell_buff + 1];
  }
}

// попроавялем строку в соответствии с флагами
// очень сложная логика, при возможности подумать как можно упростить
void edit_flag(sprint_t spec, char *tmp_str) {
  char tmp[201] = {'\0'};

  if (spec.sp == x || spec.sp == X || spec.sp == o || spec.sp == u) {
    spec.plus = FALSE;
    spec.space = FALSE;
  }

  if (spec.plus && spec.width <= (int)s21_strlen(tmp_str)) {
    tmp[0] = tmp_str[0] == '-' ? tmp_str[0] : '+';
    s21_strcpy(tmp + 1, tmp_str[0] == '-' ? tmp_str + 1 : tmp_str);
    s21_strcpy(tmp_str, tmp);
  } else if (spec.space && tmp_str[0] != '-' &&
             spec.width <= (int)s21_strlen(tmp_str)) {
    tmp[0] = ' ';
    s21_strcpy(tmp + 1, tmp_str);
    s21_strcpy(tmp_str, tmp);
  }

  if (spec.width > (int)s21_strlen(tmp_str)) {
    s21_size_t wid_len = spec.width - s21_strlen(tmp_str);
    if (!spec.minus) {
      if (spec.zero && spec.space) {
        if (tmp_str[0] != '-') {
          tmp[0] = ' ';
          s21_memset(tmp + 1, spec.zero ? '0' : ' ', wid_len);
          s21_strcpy(tmp + wid_len, tmp_str);
        } else {
          tmp[0] = '-';
          s21_memset(tmp + 1, spec.zero ? '0' : ' ', wid_len);
          s21_strcpy(tmp + wid_len + 1, tmp_str + 1);
        }
      } else if (spec.zero && spec.plus) {
        if (tmp_str[0] != '-') {
          tmp[0] = '+';
          s21_memset(tmp + 1, spec.zero ? '0' : ' ', wid_len);
          s21_strcpy(tmp + wid_len, tmp_str);
        } else {
          tmp[0] = '-';
          s21_memset(tmp + 1, spec.zero ? '0' : ' ', wid_len);
          s21_strcpy(tmp + wid_len + 1, tmp_str + 1);
        }
      } else if (spec.zero) {
        if (tmp_str[0] == '-') {
          tmp[0] = '-';
          s21_memset(tmp + 1, spec.zero ? '0' : ' ', wid_len);
          s21_strcpy(tmp + wid_len + 1, tmp_str + 1);
        } else {
          s21_memset(tmp, spec.zero ? '0' : ' ', wid_len);
          s21_strcpy(tmp + wid_len, tmp_str);
        }
      } else if (spec.plus) {
        s21_memset(tmp, ' ', wid_len - 1);
        if (tmp_str[0] != '-') tmp[wid_len - 1] = '+';
        if (tmp_str[0] == '-') tmp[wid_len - 1] = ' ';
        s21_strcpy(tmp + wid_len, tmp_str);
      } else {
        s21_memset(tmp, spec.zero ? '0' : ' ', wid_len);
        s21_strcpy(tmp + wid_len, tmp_str);
      }
    } else {
      if (spec.plus) {
        tmp[0] = '+';
        s21_strcpy(tmp + 1, tmp_str);
        s21_memset(tmp + s21_strlen(tmp), ' ', wid_len - 1);
      } else if (spec.space) {
        tmp[0] = ' ';
        s21_strcpy(tmp + 1, tmp_str);
        s21_memset(tmp + 1 + s21_strlen(tmp), ' ', wid_len);
      } else {
        s21_strcpy(tmp, tmp_str);
        s21_memset(tmp + s21_strlen(tmp), ' ', wid_len);
      }
    }
    s21_strcpy(tmp_str, tmp);
  }
}

// поправляем строку в соответсвии с точностью
void edit_precision(sprint_t spec, char *tmp_str) {
  char buff[100] = {'\0'};

  int is_sign = 0;  // нужен ли знак
  int length = s21_strlen(tmp_str);

  if (tmp_str[0] == '-') {
    buff[0] = '-';
    length--;
    is_sign = 1;
  }

  if (spec.precision > length) {
    int j;
    for (j = is_sign; j < spec.precision - length + is_sign; j++) buff[j] = '0';

    for (int i = is_sign; tmp_str[i]; i++, j++) buff[j] = tmp_str[i];

    s21_strcpy(tmp_str, buff);
  }

  if (spec.precision == 0 && is_integer(spec.sp) && spec.precision_is_set &&
      tmp_str[0] == '0')
    tmp_str[0] = '\0';
}

//является ли переданный спецификатор целым числом
int is_integer(spec_t sp) {
  int result = 0;
  if (sp == d || sp == i || sp == o || sp == u || sp == x || sp == X) {
    result = 1;
  }
  return result;
}

// перевод int числа в строку
void num_to_str(int64_t num, char *tmp_str, int type_num) {
  char buff[100] = {'\0'};
  int cell_buff = 98;

  int is_negative = num < 0 ? 1 : 0;
  num = is_negative ? -num : num;
  if (num == 0) buff[cell_buff] = '0';

  while (num > 0) {
    cell_buff--;
    buff[cell_buff] = "0123456789"[num % type_num];
    num /= type_num;
  }

  for (int i = 0; buff[cell_buff]; cell_buff++, i++) {
    if (is_negative && i == 0) tmp_str[i++] = '-';
    tmp_str[i] = buff[cell_buff];
  }
}