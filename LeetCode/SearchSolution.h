/*
 * SearchSolution.h
 *
 *  Created on: Sep 7, 2022
 *      Author: Erwin
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
};

#endif  // SEARCH_SOLUTION_H_
