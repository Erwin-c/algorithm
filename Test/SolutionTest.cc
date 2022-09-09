/*
 * SolutionTest.cc
 *
 *  Created on: Aug 30, 2022
 *      Author: Erwin
 */

#include <iostream>

#include "LeetCode/ArraySolution.h"
#include "LeetCode/SearchSolution.h"

namespace SolutionTest {

void moveZerosTest() {
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "Start moveZeros() test:" << std::endl;

  int arr[] = {0, 1, 0, 3, 12};
  std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

  ArraySolution().moveZeros(vec);

  for (size_t i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << " ";
  }

  std::cout << std::endl;

  std::cout << "End ^-^" << std::endl;

  return;
}

void sortColorsTest() {
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "Start sortColors() test:" << std::endl;

  int arr[] = {0, 2, 2, 1, 0, 2, 2, 0, 2, 1, 0};
  std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

  ArraySolution().sortColors(vec);

  for (size_t i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << " ";
  }

  std::cout << std::endl;

  std::cout << "End ^-^" << std::endl;

  return;
}

void sortColorsOptimizedTest() {
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "Start sortColorsOptimized() test:" << std::endl;

  int arr[] = {0, 2, 2, 1, 0, 2, 2, 0, 2, 1, 0};
  std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

  ArraySolution().sortColorsOptimized(vec);

  for (size_t i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << " ";
  }

  std::cout << std::endl;

  std::cout << "End ^-^" << std::endl;

  return;
}

void twoSumOptimizedTest() {
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "Start twoSumOptimized() test:" << std::endl;

  int arr[] = {1, 3, 4, 7, 11, 23, 55, 65, 89};
  std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

  std::vector<int> res;

  res = ArraySolution().twoSumOptimized(vec, 11);

  for (size_t i = 0; i < res.size(); ++i) {
    std::cout << res[i] << " ";
  }

  std::cout << std::endl;

  std::cout << "End ^-^" << std::endl;

  return;
}

void minSubArrayLenTest() {
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "Start minSubArrayLen() test:" << std::endl;

  int arr[] = {2, 3, 1, 2, 4, 3};
  std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

  int res = 0;

  res = ArraySolution().minSubArrayLen(7, vec);

  std::cout << res << std::endl;

  std::cout << "End ^-^" << std::endl;

  return;
}

void lengthOfLongestSubstringTest() {
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "Start lengthOfLongestSubstring() test:" << std::endl;

  std::string s = "abcabcbb";

  int res = 0;

  res = ArraySolution().lengthOfLongestSubstring(s);

  std::cout << res << std::endl;

  std::cout << "End ^-^" << std::endl;

  return;
}

void intersectionTest() {
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "Start intersection() test:" << std::endl;

  int arr1[] = {4, 9, 5};
  std::vector<int> vec1(arr1, arr1 + sizeof(arr1) / sizeof(int));

  int arr2[] = {9, 4, 9, 8, 4};
  std::vector<int> vec2(arr2, arr2 + sizeof(arr2) / sizeof(int));

  std::vector<int> res;
  res = SearchSolution().intersection(vec1, vec2);

  for (size_t i = 0; i < res.size(); ++i) {
    std::cout << res[i] << " ";
  }

  std::cout << std::endl;

  std::cout << "End ^-^" << std::endl;

  return;
}

void intersectionOptimizedTest() {
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "Start intersectionOptimized() test:" << std::endl;

  int arr1[] = {4, 9, 5};
  std::vector<int> vec1(arr1, arr1 + sizeof(arr1) / sizeof(int));

  int arr2[] = {9, 4, 9, 8, 4};
  std::vector<int> vec2(arr2, arr2 + sizeof(arr2) / sizeof(int));

  std::vector<int> res;
  res = SearchSolution().intersectionOptimized(vec1, vec2);

  for (size_t i = 0; i < res.size(); ++i) {
    std::cout << res[i] << " ";
  }

  std::cout << std::endl;

  std::cout << "End ^-^" << std::endl;

  return;
}

void intersectTest() {
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "Start intersect() test:" << std::endl;

  int arr1[] = {1, 2, 2, 1};
  std::vector<int> vec1(arr1, arr1 + sizeof(arr1) / sizeof(int));

  int arr2[] = {2, 2};
  std::vector<int> vec2(arr2, arr2 + sizeof(arr2) / sizeof(int));

  std::vector<int> res;
  res = SearchSolution().intersect(vec1, vec2);

  for (size_t i = 0; i < res.size(); ++i) {
    std::cout << res[i] << " ";
  }

  std::cout << std::endl;

  std::cout << "End ^-^" << std::endl;

  return;
}

void intersectOptimizedTest() {
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "Start intersectOptimized() test:" << std::endl;

  int arr1[] = {1, 2, 2, 1};
  std::vector<int> vec1(arr1, arr1 + sizeof(arr1) / sizeof(int));

  int arr2[] = {2, 2};
  std::vector<int> vec2(arr2, arr2 + sizeof(arr2) / sizeof(int));

  std::vector<int> res;
  res = SearchSolution().intersectOptimized(vec1, vec2);

  for (size_t i = 0; i < res.size(); ++i) {
    std::cout << res[i] << " ";
  }

  std::cout << std::endl;

  std::cout << "End ^-^" << std::endl;

  return;
}

void twoSumTest() {
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "Start twoSum() test:" << std::endl;

  int target = 9;
  int arr[] = {2, 7, 11, 15};
  std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

  std::vector<int> res;
  res = SearchSolution().twoSum(vec, target);

  for (size_t i = 0; i < res.size(); ++i) {
    std::cout << res[i] << " ";
  }

  std::cout << std::endl;

  std::cout << "End ^-^" << std::endl;

  return;
}

}  // namespace SolutionTest
