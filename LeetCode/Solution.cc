/*
 * Solution.cc
 *
 *  Created on: Aug 30, 2022
 *      Author: Erwin
 */

#include "LeetCode/Solution.h"

#include <cassert>

// Time: O(n)
// Space: O(1)
void Solution::moveZeros(std::vector<int>& nums) {
  // Element in [0, k) is not 0
  size_t k = 0;

  // [0, i]: nums[0...k) != 0, nums[k...i] == 0
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

// Time: O(n)
// Space: O(1)
void Solution::sortColors(std::vector<int>& nums) {
  // Frequency of 0, 1, 2
  int count[3] = {0};

  for (size_t i = 0; i < nums.size(); ++i) {
    assert(nums[i] >= 0 && nums[i] <= 2);
    ++count[nums[i]];
  }

  size_t index = 0;
  for (int i = 0; i < count[0]; ++i) {
    nums[index++] = 0;
  }
  for (int i = 0; i < count[1]; ++i) {
    nums[index++] = 1;
  }
  for (int i = 0; i < count[2]; ++i) {
    nums[index++] = 2;
  }

  return;
}

// Time: O(n)
// Space: O(1)
void Solution::sortColorsOptimized(std::vector<int>& nums) {
  int zero = -1;             // nums[0...zero] = 0
  size_t two = nums.size();  // nums[two...n) = 2

  for (size_t i = 0; i < two;) {  // nums[(zero + 1)...i) = 1
    if (nums[i] == 1) {
      ++i;
    } else if (nums[i] == 2) {
      std::swap(nums[--two], nums[i]);
    } else {
      assert(nums[i] == 0);
      std::swap(nums[++zero], nums[i++]);
    }
  }

  return;
}
