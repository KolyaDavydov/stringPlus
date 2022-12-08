#ifndef SRC_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_H_

#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

// библиотека для работы с функцией с переменным числом и типом параметров
// когда в s21_sprintf передаем '...'
// https://metanit.com/cpp/c/5.13.php
#include <stdarg.h>

#include "s21_string.h"
#include "utils.h"

typedef enum _length {
  zagluchka,
  _h,
  _l,
  _L,
} _len_t;

// механика sprintf:
// %[флаги][ширина][.точность][длина]спецификатор.
typedef struct spec_proto {
  // флаги
  bool_t minus;
  bool_t plus;
  bool_t space;
  bool_t lattice;
  bool_t zero;
  int width;  // Минимальное количество печатаемых символов
  int precision;  // точность минимальное количество записываемых цифр.
  bool_t precision_is_set;
  _len_t length;     // длина
  spec_t sp;         // непосредственно спецификатор
  bool_t end_of_sp;  // когда доходим до конца спецификатора то TRUE
} sprint_t;

int parser(sprint_t *spec, const char *format, va_list vl);
int flag_parser(sprint_t *spec, const char *format);
int width_parser(sprint_t *spec, const char *format, va_list vl);
int length_parser(sprint_t *spec, const char *format);
int precision_parser(sprint_t *spec, const char *format, va_list vl);
int specifier_parser(sprint_t *spec, const char *format);

// функции перевода в строку в соответствии со спецификаторами
void _set_char(sprint_t spec, va_list vl, char *tmp_str);
void _set_int(sprint_t spec, va_list vl, char *tmp_str);
void set_exponent(sprint_t spec, va_list vl, char *tmp_str);
void set_double(sprint_t spec, va_list vl, char *tmp_str);
void set_oct_and_hex(sprint_t spec, va_list vl, char *tmp_str);
void set_str(sprint_t spec, va_list vl, char *tmp_str);
void _set_pointer(sprint_t spec, va_list vl, char *tmp_str);
void set_g_G(sprint_t spec, va_list vl, char *tmp_str);

void edit_flag(sprint_t spec, char *tmp_str);
void edit_precision(sprint_t spec, char *tmp_str);
int is_integer(spec_t sp);
void num_to_str(int64_t num, char *tmp_str, int type_num);
void nonsign_num_to_str(uint64_t num, char *tmp_str, sprint_t spec,
                        int type_num);
void transfer_to_str(sprint_t spec, va_list vl, char *tmp_str);
void double_to_str(long double number, char *tmp_str, sprint_t spec);
void gG_to_str(long double number, char *tmp_str, sprint_t spec);
void mantiss_to_str(int pow, char *tmp_str, char sign_of_pow, sprint_t spec);
void dell_end_zeroes(char *tmp_str);
int s21_isdigit(char c);
void format_gG_precision(char *buff, int precision);

#endif  // SRC_S21_SPRINTF_H_