/*
 * Simple loop example for numerical precision analysis.
 *
 * Copyright 2017 National University of Singapore
 */

#include <klee/klee.h>

int main(int argc, char **argv) {
  int c = 0;

  klee_make_symbolic(&c, sizeof(c), "c");
  klee_track_error(&c, "c_error");

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 4; ++j) {
      c++;
    }
    for (int j = 0; j < 5; ++j) {
      c++;
    }
  }

  klee_bound_error(c, "c", 1.3);

  return 0;
}
