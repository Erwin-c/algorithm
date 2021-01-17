/*
 * sort_test.cc
 *
 *  Created on: Jan 10, 2021
 *      Author: Erwin
 */

#ifdef SORT_ENV_

#include <iostream>
#include "helper.h"
#include "sort.h"

int main() {
  int n = 1000;
  int* arr = helper::GenerateRandomArray(n, 0, n);

  helper::TestSort("Selection Sort", SelectionSort, arr, n);

  delete[] arr;

  return 0;
}

#endif  // SORT_ENV_
