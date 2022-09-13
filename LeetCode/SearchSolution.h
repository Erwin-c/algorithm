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
  // 349
  std::vector<int> intersection(std::vector<int>& nums1,
                                std::vector<int>& nums2);

  // 349 optimized
  std::vector<int> intersectionOptimized(std::vector<int>& nums1,
                                         std::vector<int>& nums2);

  // 350
  std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2);

  // 350 optimized
  std::vector<int> intersectOptimized(std::vector<int>& nums1,
                                      std::vector<int>& nums2);

  // 1
  std::vector<int> twoSum(std::vector<int> nums, int target);

  // TBD: 454

  // 219
  bool containNearbyDuplicate(std::vector<int>& nums, int k);
};

#endif  // SEARCH_SOLUTION_H_
