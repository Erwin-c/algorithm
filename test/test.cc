/*
 * test.cc
 *
 *  Created on: Jan 28, 2021
 *      Author: Erwin
 */

#include "test.h"

#include <iostream>

#include "../sort/helper.h"
#include "../sort/sort.h"

namespace test {

void sort_test_1() {
  std::cout << "---------------------------------------------------------------"
               "-----------------"
            << std::endl;
  std::cout << "Start sort_test_1():" << std::endl;
  std::cout << "Compare Merge Sort 2 and Quick Sort with random arrays"
            << std::endl;

  int n = 1000000;
  // Test for random arrays.
  std::cout << "Test for random arrays, size = " << n << ", random range [0, "
            << n << "]" << std::endl;
  int* arr1 = helper::GenerateRandomArray(n, 0, n);
  int* arr2 = helper::CopyArray(arr1, n);

  helper::TestSort("Merge Sort", sort::MergeSort2, arr1, n);
  helper::TestSort("Quick Sort", sort::QuickSort, arr2, n);

  delete[] arr1;
  delete[] arr2;

  std::cout << "End ^-^" << std::endl;
}

void sort_test_2() {
  std::cout << "---------------------------------------------------------------"
               "-----------------"
            << std::endl;
  std::cout << "Start sort_test_2():" << std::endl;
  std::cout << "Compare Insertion Sort, Merge Sort 2 and Quick Sort with nearly "
               "ordered arrays"
            << std::endl;

  int n = 500000;
  int swap_time = 100;
  // Test for nearly ordered arrays.
  std::cout << "Test for nearly ordered arrays, size = " << n
            << ", swap time = " << swap_time << std::endl;
  int* arr1 = helper::GenerateNearlyOrderedArray(n, swap_time);
  int* arr2 = helper::CopyArray(arr1, n);
  int* arr3 = helper::CopyArray(arr1, n);

  helper::TestSort("Insertion Sort", sort::InsertionSort, arr1, n);
  helper::TestSort("Merge Sort", sort::MergeSort2, arr2, n);
  helper::TestSort("Quick Sort", sort::QuickSort, arr3, n);

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  std::cout << "End ^-^" << std::endl;
}

}  // namespace test
