/*
 * sort_test.cc
 *
 *  Created on: Jan 10, 2021
 *      Author: Erwin
 */

#include <cassert>
#include <iostream>

#include "sort/helper.h"
#include "sort/sort.h"

int main() {
  int n = 50000;
  // Test for random arrays.
  std::cout << "Test for random arrays, size = " << n << ", random range [0, "
            << n << "]" << std::endl;
  int* arr1 = helper::GenerateRandomArray(n, 0, n);
  int* arr2 = helper::CopyArray(arr1, n);
  int* arr3 = helper::CopyArray(arr1, n);

  helper::TestSort("Selection Sort", sort::SelectionSort, arr1, n);
  helper::TestSort("Insertion Sort", sort::InsertionSort, arr2, n);
  helper::TestSort("Insertion Sort", sort::MergeSort, arr3, n);

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  int swap_time = 100;
  assert(swap_time >= 0);
  // Test for nearly ordered arrays.
  std::cout << "Test for nearly ordered arrays, size = " << n
            << ", swap time = " << swap_time << std::endl;
  arr1 = helper::GenerateNearlyOrderedArray(n, swap_time);
  arr2 = helper::CopyArray(arr1, n);

  helper::TestSort("Insertion Sort", sort::InsertionSort, arr1, n);
  helper::TestSort("Merge Sort", sort::MergeSort, arr2, n);

  delete[] arr1;
  delete[] arr2;

  return 0;
}
