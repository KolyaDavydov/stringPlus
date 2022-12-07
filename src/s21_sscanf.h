#ifndef SRC_S21_SSCANF_H_
#define SRC_S21_SSCANF_H_

#include <math.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define PUSHREG 0xfa
#define PUSHOCT 0xfb
#define PUSHFLT 0xfc
#define PUSHHEX 0xfd
#define PUSHEXT 0xff

#define SET_VALUE(TYPE, VALUE, VA_LIST)       \
  TYPE *character = va_arg(*VA_LIST, TYPE *); \
  *character = VALUE

#define SET_INTEGER(TYPE, VA_LIST, INPUT, MODE) \
  TYPE *digit = va_arg(*VA_LIST, TYPE *);       \
  *digit = (TYPE)hoatod(INPUT, MODE)

#define SET_HEX(TYPE, VA_LIST, INPUT)     \
  TYPE *digit = va_arg(*VA_LIST, TYPE *); \
  *digit = (TYPE)htod(INPUT)

typedef int bool_t;

typedef enum length {
  h,
  hh,
  l,
  ll,
  L,
  nil,
} len_t;

typedef enum specifier {
  c,
  d,
  i,
  e,
  E,
  f,
  g,
  G,
  o,
  s,
  u,
  x,
  X,
  p,
  n,
  spec_ch,
} spec_t;

typedef struct spec_proto {
  bool_t suppress;
  int width;
  len_t length;
  spec_t sp;
} sp_t;

/* <== Specifier funtions ==> */

int is_spec_start(char);
int parse_spec(sp_t *, char *);
int exec_spec(sp_t *, va_list *, char *, int, int *);

/* <== Arg setters funtions ==> */

int set_char(va_list *, sp_t *, char, int *);
int set_int(va_list *, sp_t *, char *, int *, int, bool_t);
int set_float(va_list *, sp_t *, char *, int *, int);
int set_string(va_list *, sp_t *, char *, int *);
int set_hex(va_list *, sp_t *, char *, int *, int);
int set_pointer(va_list *, sp_t *, char *, int *, int);
void set_bscan(va_list *, sp_t *, int, int *);
int handle_spec_char(const char *, int *);

/* <== Utils funtions ==> */

bool_t is_space(char);
bool_t skip_char(char);
int skip_whitespace(char **);
bool_t is_hex_prefixed(const char *);
bool_t is_hex(const char *);
int get_digit_substr(char *, char *, int, int, int);
bool_t push_digit(char *, char, int *, int);
int parse_int(char *);
long double parse_digits(const char **, int *const);
long double matold(const char *);
long long otod(char *);
long long htod(char *);
long long hoatod(char *, int);
bool_t parse_sign(const char **);
bool_t check_nan(char *);
bool_t check_inf(char *);
long double get_ldex(const char *, long double);
char to_clower(char);
void to_strlower(char *);
void incr_res(int *);

#endif  // SRC_S21_SSCANF_H_
