/*
 * SortTest.cc
 *
 *  Author: Erwin
 */

#include "Sort/Sort.h"
#include "Util/Util.h"
#include "gtest/gtest.h"

namespace {

class SortTest : public ::testing::Test {
 protected:
  bool testSort(const std::string& sortName, void (*sort)(int[], int),
                int arr[], int n) {
    clock_t startTime = clock();
    sort(arr, n);
    clock_t endTime = clock();

    std::cout << sortName << ": "
              << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s"
              << std::endl;

    return isSorted(arr, n);
  }

  bool isSorted(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
      if (arr[i + 1] < arr[i]) {
        return false;
      }
    }

    return true;
  }
};

// Selection Sort, Insertion Sort and Merge Sort for random arrays
TEST_F(SortTest, test1) {
  std::cout << "Compare Selection Sort, Insertion Sort and Merge Sort with "
               "random arrays"
            << std::endl;

  int n = 50000;
  std::cout << "Test for random arrays, size = " << n << ", random range [0, "
            << n << "]" << std::endl;
  int* arr1 = Util::generateRandomArray<int>(n, 0, n);
  int* arr2 = Util::copyArray(arr1, n);
  int* arr3 = Util::copyArray(arr1, n);

  EXPECT_TRUE(testSort("Selection Sort", Sort::selectionSort, arr1, n));
  EXPECT_TRUE(testSort("Insertion Sort", Sort::insertionSort, arr2, n));
  EXPECT_TRUE(testSort("Merge Sort", Sort::mergeSort, arr3, n));

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
}

// Selection Sort, Insertion Sort and Merge Sort for nearly ordered arrays
TEST_F(SortTest, test2) {
  std::cout << "Compare Selection Sort, Insertion Sort and Merge Sort with "
               "nearly ordered arrays"
            << std::endl;

  int n = 100000;
  int swapTime = 10;
  std::cout << "Test for nearly ordered arrays, size = " << n
            << ", swap time = " << swapTime << std::endl;
  int* arr1 = Util::generateNearlyOrderedArray<int>(n, swapTime);
  int* arr2 = Util::copyArray(arr1, n);
  int* arr3 = Util::copyArray(arr1, n);

  EXPECT_TRUE(testSort("Selection Sort", Sort::selectionSort, arr1, n));
  EXPECT_TRUE(testSort("Insertion Sort", Sort::insertionSort, arr2, n));
  EXPECT_TRUE(testSort("Merge Sort", Sort::mergeSort, arr3, n));

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
}

// Insertion Sort, Merge Sort Optimized for nearly ordered arrays
TEST_F(SortTest, test3) {
  std::cout << "Compare Insertion Sort and Merge Sort Optimized with nearly "
               "ordered arrays"
            << std::endl;

  int n = 100000;
  int swapTime = 10;
  std::cout << "Test for nearly ordered arrays, size = " << n
            << ", swap time = " << swapTime << std::endl;
  int* arr1 = Util::generateNearlyOrderedArray<int>(n, swapTime);
  int* arr2 = Util::copyArray(arr1, n);

  EXPECT_TRUE(testSort("Insertion Sort", Sort::insertionSort, arr1, n));
  EXPECT_TRUE(
      testSort("Merge Sort Optimized", Sort::mergeSortOptimized, arr2, n));

  delete[] arr1;
  delete[] arr2;
}

// Merge Sort Optimized and Quick Sort for random arrays
TEST_F(SortTest, test4) {
  std::cout << "Compare Merge Sort Optimized and Quick Sort with random arrays"
            << std::endl;

  int n = 1000000;
  std::cout << "Test for random arrays, size = " << n << ", random range [0, "
            << n << "]" << std::endl;
  int* arr1 = Util::generateRandomArray<int>(n, 0, n);
  int* arr2 = Util::copyArray(arr1, n);

  EXPECT_TRUE(
      testSort("Merge Sort Optimized", Sort::mergeSortOptimized, arr1, n));
  EXPECT_TRUE(testSort("Quick Sort", Sort::quickSort, arr2, n));

  delete[] arr1;
  delete[] arr2;
}

// Insertion Sort, Merge Sort Optimized and Quick Sort for nearly ordered arrays
TEST_F(SortTest, test5) {
  std::cout << "Compare Insertion Sort, Merge Sort Optimized and Quick Sort "
               "with nearly ordered arrays"
            << std::endl;

  int n = 500000;
  int swapTime = 100;
  std::cout << "Test for nearly ordered arrays, size = " << n
            << ", swap time = " << swapTime << std::endl;
  int* arr1 = Util::generateNearlyOrderedArray<int>(n, swapTime);
  int* arr2 = Util::copyArray(arr1, n);
  int* arr3 = Util::copyArray(arr1, n);

  EXPECT_TRUE(testSort("Insertion Sort", Sort::insertionSort, arr1, n));
  EXPECT_TRUE(
      testSort("Merge Sort Optimized", Sort::mergeSortOptimized, arr2, n));
  EXPECT_TRUE(testSort("Quick Sort", Sort::quickSort, arr3, n));

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
}

// Insertion Sort, Merge Sort Optimized and Quick Sort Optimized for nearly
// ordered arrays
TEST_F(SortTest, test6) {
  std::cout << "Compare Insertion Sort, Merge Sort Optimized and Quick Sort "
               "Optimized with nearly ordered arrays"
            << std::endl;

  int n = 500000;
  int swapTime = 100;
  std::cout << "Test for nearly ordered arrays, size = " << n
            << ", swap time = " << swapTime << std::endl;
  int* arr1 = Util::generateNearlyOrderedArray<int>(n, swapTime);
  int* arr2 = Util::copyArray(arr1, n);
  int* arr3 = Util::copyArray(arr1, n);

  EXPECT_TRUE(testSort("Insertion Sort", Sort::insertionSort, arr1, n));
  EXPECT_TRUE(
      testSort("Merge Sort Optimized", Sort::mergeSortOptimized, arr2, n));
  EXPECT_TRUE(
      testSort("Quick Sort Optimized", Sort::quickSortOptimized, arr3, n));

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
}

// Merge Sort Optimized and Quick Sort Optimized for arrays with many duplicate
// elements
TEST_F(SortTest, test7) {
  std::cout << "Compare Merge Sort Optimized and Quick Sort Optimized with "
               "arrays which have many duplicate elements"
            << std::endl;

  int n = 350000;
  std::cout << "Test for random arrays, size = " << n << ", random range [0, "
            << 10 << "]" << std::endl;
  int* arr1 = Util::generateRandomArray<int>(n, 0, 10);
  int* arr2 = Util::copyArray(arr1, n);

  EXPECT_TRUE(
      testSort("Merge Sort Optimized", Sort::mergeSortOptimized, arr1, n));
  EXPECT_TRUE(
      testSort("Quick Sort Optimized", Sort::quickSortOptimized, arr2, n));

  delete[] arr1;
  delete[] arr2;
}

// Merge Sort Optimized and Quick Sort 2 Ways for arrays with many duplicate
// elements
TEST_F(SortTest, test8) {
  std::cout << "Compare Merge Sort Optimized and Quick Sort 2 Ways with arrays "
               "which have many duplicate elements"
            << std::endl;

  int n = 350000;
  std::cout << "Test for random arrays, size = " << n << ", random range [0, "
            << 10 << "]" << std::endl;
  int* arr1 = Util::generateRandomArray<int>(n, 0, 10);
  int* arr2 = Util::copyArray(arr1, n);

  EXPECT_TRUE(
      testSort("Merge Sort Optimized", Sort::mergeSortOptimized, arr1, n));
  EXPECT_TRUE(testSort("Quick Sort 2 Ways", Sort::quickSort2Ways, arr2, n));

  delete[] arr1;
  delete[] arr2;
}

// Merge Sort Optimized, Quick Sort 2 Ways and Quick Sort 3 Ways for arrays with
// many duplicate elements
TEST_F(SortTest, test9) {
  std::cout << "Compare Merge Sort Optimized, Quick Sort 2 Ways and Quick Sort "
               "3 Ways with arrays which have many duplicate elements"
            << std::endl;

  int n = 350000;
  std::cout << "Test for random arrays, size = " << n << ", random range [0, "
            << 10 << "]" << std::endl;
  int* arr1 = Util::generateRandomArray<int>(n, 0, 10);
  int* arr2 = Util::copyArray(arr1, n);
  int* arr3 = Util::copyArray(arr1, n);

  EXPECT_TRUE(
      testSort("Merge Sort Optimized", Sort::mergeSortOptimized, arr1, n));
  EXPECT_TRUE(testSort("Quick Sort 2 Ways", Sort::quickSort2Ways, arr2, n));
  EXPECT_TRUE(testSort("Quick Sort 3 Ways", Sort::quickSort3Ways, arr3, n));

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
}

// Merge Sort Optimized, Quick Sort 2 Ways, Quick Sort 3 Ways and Heap Sort 1
// for arrays with many duplicate elements
TEST_F(SortTest, test10) {
  std::cout
      << "Compare Merge Sort Optimized, Quick Sort 2 Ways, Quick Sort 3 Ways "
         "and Heap Sort 1 with arrays which have many duplicate elements "
      << std::endl;

  int n = 1000000;
  std::cout << "Test for random arrays, size = " << n << ", random range [0, "
            << 10 << "]" << std::endl;
  int* arr1 = Util::generateRandomArray<int>(n, 0, 10);
  int* arr2 = Util::copyArray(arr1, n);
  int* arr3 = Util::copyArray(arr1, n);
  int* arr4 = Util::copyArray(arr1, n);

  EXPECT_TRUE(
      testSort("Merge Sort Optimized", Sort::mergeSortOptimized, arr1, n));
  EXPECT_TRUE(testSort("Quick Sort 2 Ways", Sort::quickSort2Ways, arr2, n));
  EXPECT_TRUE(testSort("Quick Sort 3 Ways", Sort::quickSort3Ways, arr3, n));
  EXPECT_TRUE(testSort("Heap Sort Insert", Sort::heapSortInsert, arr4, n));

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  delete[] arr4;
}

// Merge Sort Optimized, Quick Sort 2 Ways, Quick Sort 3 Ways, Heap Sort Insert
// and Heap Sort Heapify for arrays with many duplicate elements. In general,
// Heap Sort is worse than others. So Heap Sort is often used to process dynamic
// data, not for system sort
TEST_F(SortTest, test11) {
  std::cout << "Compare Merge Sort Optimized, Quick Sort 2 Ways, Quick Sort 3 "
               "Ways Heap Sort 1 and Heap Sort 2 with arrays which have many "
               "duplicate elements "
            << std::endl;

  int n = 1000000;
  std::cout << "Test for random arrays, size = " << n << ", random range [0, "
            << 10 << "]" << std::endl;
  int* arr1 = Util::generateRandomArray<int>(n, 0, 10);
  int* arr2 = Util::copyArray(arr1, n);
  int* arr3 = Util::copyArray(arr1, n);
  int* arr4 = Util::copyArray(arr1, n);
  int* arr5 = Util::copyArray(arr1, n);

  EXPECT_TRUE(
      testSort("Merge Sort Optimized", Sort::mergeSortOptimized, arr1, n));
  EXPECT_TRUE(testSort("Quick Sort 2 Ways", Sort::quickSort2Ways, arr2, n));
  EXPECT_TRUE(testSort("Quick Sort 3 Ways", Sort::quickSort3Ways, arr3, n));
  EXPECT_TRUE(testSort("Heap Sort Insert", Sort::heapSortInsert, arr4, n));
  EXPECT_TRUE(testSort("Heap Sort Heapify", Sort::heapSortHeapify, arr5, n));

  delete[] arr1;
  delete[] arr2;
  delete[] arr3;
  delete[] arr4;
  delete[] arr5;
}

}  // namespace
