/*
 * main.cpp
 * Copyright (C) 2015 Sean Kirmani <sean@kirmani.io>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdint.h>

int sorted(int x[], unsigned int n);
int sumsTo(unsigned int x[], unsigned int n, unsigned int k, unsigned int v);
void testSorted();
void testSumsTo();

int main() {
  testSumsTo();
}

int sorted(int x[], unsigned int n) {
  if (n == 1) {
    return 0;
  }
  int result;
  if (x[n] < x[n - 1]) {
    result = 1;
  } else {
    result = (x[n] == x[n - 1]) ? 0 : -1;
  }
  int is_rest_sorted = sorted(x, n - 1);
  return (result == 0 || is_rest_sorted == result) ? is_rest_sorted : -99;
}

void testSorted() {
  int x[] = {2, 2, 2};
  int n = 3;
  printf("expected: %d, actual: %d\n", 0, sorted(x, n));
  x[0] = 1;
  x[2] = 3;  // {1, 2, 3}
  printf("expected: %d, actual: %d\n", -1, sorted(x, n));
  x[0] = 2;  // {2, 2, 3}
  printf("expected: %d, actual: %d\n", -1, sorted(x, n));
  x[0] = 3;
  x[2] = 1;  // {3, 2, 1}
  printf("expected: %d, actual: %d\n", 1, sorted(x, n));
  x[1] = 1;  // {3, 1, 1}
  printf("expected: %d, actual: %d\n", 1, sorted(x, n));
  x[2] = 2;  // {3, 1, 2}
  printf("expected: %d, actual: %d\n", -99, sorted(x, n));
}


int sumsTo(unsigned int x[], unsigned int n, unsigned int k, unsigned int v) {
  if (k == 0)
    return (v == 0) ? 1 : 0;
  for (unsigned int i = 0; i < n; i++)
    if (sumsTo(x, n, k - 1, v - x[i]))
      return 1;
  return 0;
}

void testSumsTo() {
  unsigned int x[] = {1, 8, 6, 4, 3};
  unsigned int n = 5;
  unsigned int k = 3;
  unsigned int v = 9;
  printf("expected: %d, actual: %d\n", 0, sumsTo(x, n, k, v));
}

