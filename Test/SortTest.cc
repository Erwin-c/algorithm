/*
 * SortTest.cc
 *
 *  Created on: Jan 28, 2021
 *      Author: Erwin
 */

#include "Test/SortTest.h"

#include <iostream>

#include "Sort/Sort.h"
#include "Util/Util.h"

namespace SortTest {

void test1() {
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "Start sort test 1:" << std::endl;
  std::cout << "Compare Selection Sort, Insertion Sort and Merge Sort with "
               "random arrays"
            << std::endl;

  int n = 50000;
  // Test for random arrays
  std::cout << "Test for random arrays, size = " << n << ", random range [0, "
            << n << "]" << std::endl;
  int* arr1 = Util::generateRandomArray<int>(n, 0, n);
  int* arr2 = Util::copyArray(arr1, n);
  int* arr3 = Util::copyArray(arr1, n);

  Util::testSort("Selection Sort", selectionSort, arr1, n);
  Util::testSort("Insertion Sort", insertionSort, arr2, n);
  Util::testSort("Merge Sort", mergeSort, arr3, n);

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  std::cout << "End ^-^" << std::endl;

  return;
}

void test2() {
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "Start sort test 2:" << std::endl;
  std::cout
      << "Compare Selection Sort, Insertion Sort and Merge Sort with nearly "
         "ordered arrays"
      << std::endl;

  int n = 100000;
  int swapTime = 10;
  // Test for nearly ordered arrays
  std::cout << "Test for nearly ordered arrays, size = " << n
            << ", swap time = " << swapTime << std::endl;
  int* arr1 = Util::generateNearlyOrderedArray<int>(n, swapTime);
  int* arr2 = Util::copyArray(arr1, n);
  int* arr3 = Util::copyArray(arr1, n);

  Util::testSort("Selection Sort", selectionSort, arr1, n);
  Util::testSort("Insertion Sort", insertionSort, arr2, n);
  Util::testSort("Merge Sort", mergeSort, arr3, n);

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  std::cout << "End ^-^" << std::endl;

  return;
}

void test3() {
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "Start sort test 3:" << std::endl;
  std::cout << "Compare Insertion Sort and Merge Sort Optimized with nearly "
               "ordered arrays"
            << std::endl;

  int n = 100000;
  int swapTime = 10;
  // Test for nearly ordered arrays
  std::cout << "Test for nearly ordered arrays, size = " << n
            << ", swap time = " << swapTime << std::endl;
  int* arr1 = Util::generateNearlyOrderedArray<int>(n, swapTime);
  int* arr2 = Util::copyArray(arr1, n);

  Util::testSort("Insertion Sort", insertionSort, arr1, n);
  Util::testSort("Merge Sort Optimized", mergeSortOptimized, arr2, n);

  delete[] arr1;
  delete[] arr2;

  std::cout << "End ^-^" << std::endl;

  return;
}

void test4() {
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "Start sort test 4:" << std::endl;
  std::cout << "Compare Merge Sort Optimized and Quick Sort with random arrays"
            << std::endl;

  int n = 1000000;
  // Test for random arrays
  std::cout << "Test for random arrays, size = " << n << ", random range [0, "
            << n << "]" << std::endl;
  int* arr1 = Util::generateRandomArray<int>(n, 0, n);
  int* arr2 = Util::copyArray(arr1, n);

  Util::testSort("Merge Sort Optimized", mergeSortOptimized, arr1, n);
  Util::testSort("Quick Sort", quickSort, arr2, n);

  delete[] arr1;
  delete[] arr2;

  std::cout << "End ^-^" << std::endl;

  return;
}

void test5() {
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "Start sort test 5:" << std::endl;
  std::cout << "Compare Insertion Sort, Merge Sort Optimized and Quick Sort "
               "with nearly "
               "ordered arrays"
            << std::endl;

  int n = 500000;
  int swapTime = 100;
  // Test for nearly ordered arrays
  std::cout << "Test for nearly ordered arrays, size = " << n
            << ", swap time = " << swapTime << std::endl;
  int* arr1 = Util::generateNearlyOrderedArray<int>(n, swapTime);
  int* arr2 = Util::copyArray(arr1, n);
  int* arr3 = Util::copyArray(arr1, n);

  Util::testSort("Insertion Sort", insertionSort, arr1, n);
  Util::testSort("Merge Sort Optimized", mergeSortOptimized, arr2, n);
  Util::testSort("Quick Sort", quickSort, arr3, n);

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  std::cout << "End ^-^" << std::endl;

  return;
}

void test6() {
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "Start sort test 6:" << std::endl;
  std::cout << "Compare Insertion Sort, Merge Sort Optimized and Quick Sort "
               "Optimized with nearly "
               "ordered arrays"
            << std::endl;

  int n = 500000;
  int swapTime = 100;
  // Test for nearly ordered arrays
  std::cout << "Test for nearly ordered arrays, size = " << n
            << ", swap time = " << swapTime << std::endl;
  int* arr1 = Util::generateNearlyOrderedArray<int>(n, swapTime);
  int* arr2 = Util::copyArray(arr1, n);
  int* arr3 = Util::copyArray(arr1, n);

  Util::testSort("Insertion Sort", insertionSort, arr1, n);
  Util::testSort("Merge Sort Optimized", mergeSortOptimized, arr2, n);
  Util::testSort("Quick Sort Optimized", quickSortOptimized, arr3, n);

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  std::cout << "End ^-^" << std::endl;

  return;
}

void test7() {
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "Start sort test 7:" << std::endl;
  std::cout << "Compare Merge Sort Optimized and Quick Sort Optimized with "
               "arrays which have many duplicate elements"
            << std::endl;

  int n = 350000;
  // Test for random arrays which have more duplicate elements
  std::cout << "Test for random arrays, size = " << n << ", random range [0, "
            << 10 << "]" << std::endl;
  int* arr1 = Util::generateRandomArray<int>(n, 0, 10);
  int* arr2 = Util::copyArray(arr1, n);

  Util::testSort("Merge Sort Optimized", mergeSortOptimized, arr1, n);
  Util::testSort("Quick Sort Optimized", quickSortOptimized, arr2, n);

  delete[] arr1;
  delete[] arr2;

  std::cout << "End ^-^" << std::endl;

  return;
}

void test8() {
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "Start sort test 8:" << std::endl;
  std::cout << "Compare Merge Sort Optimized and Quick Sort 2 Ways with "
               "arrays which have many duplicate elements"
            << std::endl;

  int n = 350000;
  // Test for random arrays which have more duplicate elements
  std::cout << "Test for random arrays, size = " << n << ", random range [0, "
            << 10 << "]" << std::endl;
  int* arr1 = Util::generateRandomArray<int>(n, 0, 10);
  int* arr2 = Util::copyArray(arr1, n);

  Util::testSort("Merge Sort Optimized", mergeSortOptimized, arr1, n);
  Util::testSort("Quick Sort 2 Ways", quickSort2Ways, arr2, n);

  delete[] arr1;
  delete[] arr2;

  std::cout << "End ^-^" << std::endl;

  return;
}

void test9() {
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "Start sort test 9:" << std::endl;
  std::cout << "Compare Merge Sort Optimized, Quick Sort 2 Ways and Quick Sort "
               "3 Ways with arrays which have many duplicate elements"
            << std::endl;

  int n = 350000;
  // Test for random arrays which have more duplicate elements
  std::cout << "Test for random arrays, size = " << n << ", random range [0, "
            << 10 << "]" << std::endl;
  int* arr1 = Util::generateRandomArray<int>(n, 0, 10);
  int* arr2 = Util::copyArray(arr1, n);
  int* arr3 = Util::copyArray(arr1, n);

  Util::testSort("Merge Sort Optimized", mergeSortOptimized, arr1, n);
  Util::testSort("Quick Sort 2 Ways", quickSort2Ways, arr2, n);
  Util::testSort("Quick Sort 3 Ways", quickSort3Ways, arr3, n);

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;

  std::cout << "End ^-^" << std::endl;

  return;
}

void test10() {
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "Start sort test 10:" << std::endl;
  std::cout << "Compare Merge Sort Optimized, Quick Sort 2 Ways, Quick Sort "
               "3 Ways and Heap Sort 1 with arrays which have many duplicate "
               "elements"
            << std::endl;

  int n = 1000000;
  // Test for random arrays which have more duplicate elements
  std::cout << "Test for random arrays, size = " << n << ", random range [0, "
            << 10 << "]" << std::endl;
  int* arr1 = Util::generateRandomArray<int>(n, 0, 10);
  int* arr2 = Util::copyArray(arr1, n);
  int* arr3 = Util::copyArray(arr1, n);
  int* arr4 = Util::copyArray(arr1, n);

  Util::testSort("Merge Sort Optimized", mergeSortOptimized, arr1, n);
  Util::testSort("Quick Sort 2 Ways", quickSort2Ways, arr2, n);
  Util::testSort("Quick Sort 3 Ways", quickSort3Ways, arr3, n);
  Util::testSort("Heap Sort 1", heapSort1, arr4, n);

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  delete[] arr4;

  std::cout << "End ^-^" << std::endl;

  return;
}

void test11() {
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "Start sort test 11:" << std::endl;
  std::cout << "Compare Merge Sort Optimized, Quick Sort 2 Ways, Quick Sort "
               "3 Ways Heap Sort 1 and Heap Sort 2 with arrays which have many "
               "duplicate  elements"
            << std::endl;

  int n = 1000000;
  // Test for random arrays which have more duplicate elements
  std::cout << "Test for random arrays, size = " << n << ", random range [0, "
            << 10 << "]" << std::endl;
  int* arr1 = Util::generateRandomArray<int>(n, 0, 10);
  int* arr2 = Util::copyArray(arr1, n);
  int* arr3 = Util::copyArray(arr1, n);
  int* arr4 = Util::copyArray(arr1, n);
  int* arr5 = Util::copyArray(arr1, n);

  Util::testSort("Merge Sort Optimized", mergeSortOptimized, arr1, n);
  Util::testSort("Quick Sort 2 Ways", quickSort2Ways, arr2, n);
  Util::testSort("Quick Sort 3 Ways", quickSort3Ways, arr3, n);
  Util::testSort("Heap Sort 1", heapSort1, arr4, n);
  Util::testSort("Heap Sort 2", heapSort2, arr5, n);

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  delete[] arr4;
  delete[] arr5;

  std::cout << "End ^-^" << std::endl;

  return;
}

}  // namespace SortTest
