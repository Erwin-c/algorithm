/*
 * sort_test.cc
 *
 *  Created on: Jan 10, 2021
 *      Author: Erwin
 */

#include <iostream>

#include "sort/helper.h"
#include "sort/sort.h"

int main() {
  int n = 1000;
  int* arr = helper::GenerateRandomArray(n, 0, n);
  int* arr2 = helper::CopyArray(arr, n);

  helper::TestSort("Selection Sort", SelectionSort, arr, n);
  helper::TestSort("Insertion Sort", InsertionSort, arr2, n);

  delete[] arr;
  delete[] arr2;

  return 0;
}
