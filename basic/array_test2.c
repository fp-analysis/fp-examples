/*
 * Copyright 2017 National University of Singapore
 *
 * Author: Himeshi De Silva <himeshidslv@gmail.com>
 *
 * This exemplifies the specification of input errors for arrays, for
 * arrays of 32-bit ints.
 */
#include <klee/klee.h>
#include <stdio.h>

#define SIZE 5

void test_array(int *x);

int arr[SIZE], answer;

int main() {

  /*
     Here we add __arr32__ prefix to declare that this was an array of
     32 bits. This causes array indirection to be used in the output
     error expression.
  */
  klee_make_symbolic(arr, SIZE * sizeof(int), "__arr32__arr");
  klee_track_error(arr, "__arr32__arr_error");

  test_array(arr);

  klee_bound_error(arr[0], "arr[0]", 1.3);
  return 0;
}

void test_array(int *x) {
  // x[0] = (x[1] + x[2]) * (x[3] - x[4]);
  x[0] = x[1] + x[2];
}
