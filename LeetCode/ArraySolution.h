/*
 * ArraySolution.h
 *
 *  Author: Erwin
 */

#ifndef ARRAY_SOLUTION_H_
#define ARRAY_SOLUTION_H_

#include <string>
#include <vector>

class ArraySolution {
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

  // 209
  int minSubArrayLen(int s, std::vector<int>& nums);

  // 3
  int lengthOfLongestSubstring(std::string s);

  // TBD: 438
};

#endif  // ARRAY_SOLUTION_H_
