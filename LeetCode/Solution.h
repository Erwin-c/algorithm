/*
 * Solution.h
 *
 *  Created on: Aug 30, 2022
 *      Author: Erwin
 */

#ifndef SOLUTION_H_
#define SOLUTION_H_

#include <vector>

class Solution {
 public:
  // 283
  void moveZeros(std::vector<int>& nums);

  // 75
  void sortColors(std::vector<int>& nums);

  // 75 optimized
  void sortColorsOptimized(std::vector<int>& nums);

  // TBD: 167 binary search
  // vector<int> twoSum(vector<int>& numbers, int target);

  // 167 optimized
  std::vector<int> twoSumOptimized(std::vector<int>& numbers, int target);
};

#endif  // SOLUTION_H_
