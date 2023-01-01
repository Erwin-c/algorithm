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
  // 283. Move Zeroes
  // 原地 (in place) 解决该问题
  // 时间复杂度: O(n)
  // 空间复杂度: O(1)
  void moveZeros(std::vector<int>& nums);

  // TBD: 27 (Optimized), 26, 80

  // 75. Sort Colors
  // 计数排序的思想
  // 对整个数组遍历了两遍
  // 时间复杂度: O(n)
  // 空间复杂度: O(k), k 为元素的取值范围.
  void sortColors(std::vector<int>& nums);

  // 75. Sort Colors Optimized
  // 三路快速排序的思想
  // 对整个数组只遍历了一遍
  // 时间复杂度: O(n)
  // 空间复杂度: O(1)
  void sortColorsOptimized(std::vector<int>& nums);

  // TBD: 88, 215

  // TBD: 167 binary search
  // vector<int> twoSum(vector<int>& numbers, int target);

  // 167. Two Sum II - Input array is sorted
  // 对撞指针
  // 时间复杂度: O(n)
  // 空间复杂度: O(1)
  std::vector<int> twoSumOptimized(std::vector<int>& numbers, int target);

  // 209. Minimum Size Subarray Sum
  // 滑动窗口的思路
  // 时间复杂度: O(n)
  // 空间复杂度: O(1)
  int minSubArrayLen(int target, std::vector<int>& nums);

  // 3. Longest Substring Without Repeating Characters
  // 滑动窗口
  // 时间复杂度: O(len(s))
  // 空间复杂度: O(len(charset))
  int lengthOfLongestSubstring(std::string s);

  // TBD: 438
};

#endif  // ARRAY_SOLUTION_H_
