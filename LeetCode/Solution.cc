/*
 * Solution.cc
 *
 *  Created on: Aug 30, 2022
 *      Author: Erwin
 */

#include "LeetCode/Solution.h"

void Solution::moveZeros(std::vector<int>& nums) {
  // Element in [0...k) is not 0
  size_t k = 0;

  // [0...i]: [0...k) --> !0, [k...i] --> 0
  for (size_t i = 0; i < nums.size(); ++i) {
    if (nums[i] != 0) {
      if (k != i) {
        std::swap(nums[k++], nums[i]);
      } else {
        ++k;
      }
    }
  }

  return;
}
