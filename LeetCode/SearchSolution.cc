/*
 * SearchSolution.cc
 *
 *  Created on: Sep 7, 2022
 *      Author: Erwin
 */

#include "LeetCode/SearchSolution.h"

#include <set>

// Time: O(n)
// Space: O(n)
std::vector<int> SearchSolution::intersection(std::vector<int>& nums1,
                                              std::vector<int>& nums2) {
  std::set<int> record;
  for (size_t i = 0; i < nums1.size(); ++i) {
    record.insert(nums1[i]);
  }

  std::set<int> resultSet;
  for (size_t i = 0; i < nums2.size(); ++i) {
    if (record.find(nums2[i]) != record.end()) {
      resultSet.insert(nums2[i]);
    }
  }

  std::vector<int> resultVector;
  for (std::set<int>::iterator iter = resultSet.begin();
       iter != resultSet.end(); ++iter) {
    resultVector.push_back(*iter);
  }

  return resultVector;
}

// Time: O(n)
// Space: O(n)
std::vector<int> SearchSolution::intersectionOptimized(
    std::vector<int>& nums1, std::vector<int>& nums2) {
  std::set<int> record(nums1.begin(), nums1.end());

  std::set<int> resultSet;
  for (size_t i = 0; i < nums2.size(); ++i) {
    if (record.find(nums2[i]) != record.end()) {
      resultSet.insert(nums2[i]);
    }
  }

  return std::vector<int>(resultSet.begin(), resultSet.end());
}
