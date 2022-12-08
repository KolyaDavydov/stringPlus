#ifndef SRC_UTILS_H_
#define SRC_UTILS_H_

#define TRUE 1
#define FALSE 0

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
  percent,
} spec_t;

#endif  // SRC_UTILS_H_