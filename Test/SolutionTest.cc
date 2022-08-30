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
  int arr[] = {0, 1, 0, 3, 12};

  std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

  Solution().moveZeros(vec);

  for (size_t i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << " ";
  }

  std::cout << std::endl;

  return;
}

}  // namespace SolutionTest
