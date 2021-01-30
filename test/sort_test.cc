/*
 * test.cc
 *
 *  Created on: Jan 28, 2021
 *      Author: Erwin
 */

#include "test/sort_test.h"

#include <iostream>

#include "sort/helper.h"
#include "sort/sort.h"

namespace sort_test {

void Test1() {
  std::cout << "---------------------------------------------------------------"
               "-----------------"
            << std::endl;
  std::cout << "Start sort_test 1:" << std::endl;
  std::cout << "Compare Selection Sort, Insertion Sort and Merge Sort with "
               "random arrays."
            << std::endl;

  int n = 50000;
  // Test for random arrays.
  std::cout << "Test for random arrays, size = " << n << ", random range [0, "
            << n << "]" << std::endl;
  int* arr1 = helper::GenerateRandomArray(n, 0, n);
  int* arr2 = helper::CopyArray(arr1, n);
  int* arr3 = helper::CopyArray(arr1, n);

  helper::TestSort("Selection Sort", sort::SelectionSort, arr1, n);
  helper::TestSort("Insertion Sort", sort::InsertionSort, arr2, n);
  helper::TestSort("Merge Sort", sort::MergeSort, arr3, n);

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  std::cout << "End ^-^" << std::endl;
}

void Test2() {
  std::cout << "---------------------------------------------------------------"
               "-----------------"
            << std::endl;
  std::cout << "Start sort_test 2:" << std::endl;
  std::cout
      << "Compare Selection Sort, Insertion Sort and Merge Sort with nearly "
         "ordered arrays"
      << std::endl;

  int n = 100000;
  int swap_time = 10;
  // Test for nearly ordered arrays.
  std::cout << "Test for nearly ordered arrays, size = " << n
            << ", swap time = " << swap_time << std::endl;
  int* arr1 = helper::GenerateNearlyOrderedArray(n, swap_time);
  int* arr2 = helper::CopyArray(arr1, n);
  int* arr3 = helper::CopyArray(arr1, n);

  helper::TestSort("Selection Sort", sort::SelectionSort, arr1, n);
  helper::TestSort("Insertion Sort", sort::InsertionSort, arr2, n);
  helper::TestSort("Merge Sort", sort::MergeSort, arr3, n);

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  std::cout << "End ^-^" << std::endl;
}

void Test3() {
  std::cout << "---------------------------------------------------------------"
               "-----------------"
            << std::endl;
  std::cout << "Start sort_test 3:" << std::endl;
  std::cout << "Compare Insertion Sort and Merge Sort Advanced with nearly "
               "ordered arrays"
            << std::endl;

  int n = 100000;
  int swap_time = 10;
  // Test for nearly ordered arrays.
  std::cout << "Test for nearly ordered arrays, size = " << n
            << ", swap time = " << swap_time << std::endl;
  int* arr1 = helper::GenerateNearlyOrderedArray(n, swap_time);
  int* arr2 = helper::CopyArray(arr1, n);

  helper::TestSort("Insertion Sort", sort::InsertionSort, arr1, n);
  helper::TestSort("Merge Sort Advanced", sort::MergeSortAdvanced, arr2, n);

  delete[] arr1;
  delete[] arr2;

  std::cout << "End ^-^" << std::endl;
}

void Test4() {
  std::cout << "---------------------------------------------------------------"
               "-----------------"
            << std::endl;
  std::cout << "Start sort_test 4:" << std::endl;
  std::cout << "Compare Merge Sort Advanced and Quick Sort with random arrays"
            << std::endl;

  int n = 1000000;
  // Test for random arrays.
  std::cout << "Test for random arrays, size = " << n << ", random range [0, "
            << n << "]" << std::endl;
  int* arr1 = helper::GenerateRandomArray(n, 0, n);
  int* arr2 = helper::CopyArray(arr1, n);

  helper::TestSort("Merge Sort Advanced", sort::MergeSortAdvanced, arr1, n);
  helper::TestSort("Quick Sort", sort::QuickSort, arr2, n);

  delete[] arr1;
  delete[] arr2;

  std::cout << "End ^-^" << std::endl;
}

void Test5() {
  std::cout << "---------------------------------------------------------------"
               "-----------------"
            << std::endl;
  std::cout << "Start sort_test 5:" << std::endl;
  std::cout << "Compare Insertion Sort, Merge Sort Advanced and Quick Sort "
               "with nearly "
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
  helper::TestSort("Merge Sort Advanced", sort::MergeSortAdvanced, arr2, n);
  helper::TestSort("Quick Sort", sort::QuickSort, arr3, n);

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  std::cout << "End ^-^" << std::endl;
}

void Test6() {
  std::cout << "---------------------------------------------------------------"
               "-----------------"
            << std::endl;
  std::cout << "Start sort_test 6:" << std::endl;
  std::cout << "Compare Insertion Sort, Merge Sort Advanced and Quick Sort "
               "Advanced with nearly "
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
  helper::TestSort("Merge Sort Advanced", sort::MergeSortAdvanced, arr2, n);
  helper::TestSort("Quick Sort Advanced", sort::QuickSortAdvanced, arr3, n);

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  std::cout << "End ^-^" << std::endl;
}

}  // namespace sort_test
