/*
 * SolutionTest.cc
 *
 *  Created on: Aug 30, 2022
 *      Author: Erwin
 */

#include <iostream>

#include "LeetCode/Solution.h"

namespace SolutionTest {

void moveZerosTest() {
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "Start moveZeros() test:" << std::endl;
  int arr[] = {0, 1, 0, 3, 12};

  std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

  Solution().moveZeros(vec);

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

  Solution().sortColors(vec);

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

  Solution().sortColorsOptimized(vec);

  for (size_t i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << " ";
  }

  std::cout << std::endl;

  std::cout << "End ^-^" << std::endl;

  return;
}

}  // namespace SolutionTest
