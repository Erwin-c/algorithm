/*
 * SearchSolution.h
 *
 *  Author: Erwin
 */

#ifndef SEARCH_SOLUTION_H_
#define SEARCH_SOLUTION_H_

#include <vector>

class SearchSolution {
 public:
  // 349. Intersection of Two Arrays.
  // 时间复杂度: O(n).
  // 空间复杂度: O(n).
  std::vector<int> intersection(std::vector<int>& nums1,
                                std::vector<int>& nums2);

  // 349. Intersection of Two Arrays Optimized.
  // 时间复杂度: O(n).
  // 空间复杂度: O(n).
  std::vector<int> intersectionOptimized(std::vector<int>& nums1,
                                         std::vector<int>& nums2);

  // 350. Intersection of Two Arrays II.
  // 时间复杂度: O(n).
  // 空间复杂度: O(n).
  std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2);

  // 350. Intersection of Two Arrays II Optimized.
  // 时间复杂度: O(n).
  // 空间复杂度: O(n).
  std::vector<int> intersectOptimized(std::vector<int>& nums1,
                                      std::vector<int>& nums2);

  // 1.
  std::vector<int> twoSum(std::vector<int> nums, int target);

  // 454.
  int fourSumCount(std::vector<int>& nums1, std::vector<int>& nums2,
                   std::vector<int>& nums3, std::vector<int>& nums4);

  // 219.
  bool containNearbyDuplicate(std::vector<int>& nums, int k);

  // 220.
  bool containNearbyAlmostDuplicate(std::vector<int> nums, int indexDiff,
                                    int valueDiff);
};

#endif  // SEARCH_SOLUTION_H_
