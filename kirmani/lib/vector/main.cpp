/*
 * main.cpp
 * Copyright (C) 2015 Sean Kirmani <sean@kirmani.io>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <stdint.h>
#include "vector.h"

int main() {
  Vector<const char*> vector{};
  for (unsigned int index = 0; index <= 100; index++)
    vector.Append("s");
  std::cout << vector << std::endl;
  std::cout << "vector[5] = " << vector[5] << std::endl;
  vector[5] = "sean";
  std::cout << "Vector[5] = " << vector[5] << std::endl;
  std::cout << vector << std::endl;
}
