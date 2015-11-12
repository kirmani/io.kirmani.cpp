/*
 * main.cpp
 * Copyright (C) 2015 Sean Kirmani <sean@kirmani.io>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdint.h>

int max(unsigned int n, int... arr);

int main() {
  printf("expected: 40, actual: %d\n", max(3, 16, -2, 40));
}

int max(unsigned int n, int... arr) {
  int max = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}
