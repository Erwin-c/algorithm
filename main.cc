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
  int* arr3 = helper::CopyArray(arr, n);

  helper::TestSort("Selection Sort", sort::SelectionSort, arr, n);
  helper::TestSort("Insertion Sort", sort::InsertionSort, arr2, n);
  helper::TestSort("Insertion Sort", sort::MergeSort, arr3, n);

  delete[] arr;
  delete[] arr2;
  delete[] arr3;

  return 0;
}
