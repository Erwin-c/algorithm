/*
 * SearchSolution.cc
 *
 *  Author: Erwin
 */

#include "LeetCode/SearchSolution.h"

#include <cassert>
#include <set>
#include <unordered_map>
#include <unordered_set>

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

// Time: O(n)
// Space: O(n)
std::vector<int> SearchSolution::intersect(std::vector<int>& nums1,
                                           std::vector<int>& nums2) {
  std::unordered_map<int, int> record;
  for (size_t i = 0; i < nums1.size(); ++i) {
    if (record.find(nums1[i]) == record.end()) {
      record.insert(std::make_pair(nums1[i], 1));
    } else {
      ++record[nums1[i]];
    }
  }

  std::vector<int> resultVector;
  for (size_t i = 0; i < nums2.size(); ++i) {
    if (record.find(nums2[i]) != record.end() && record[nums2[i]] > 0) {
      resultVector.push_back(nums2[i]);
      --record[nums2[i]];

      if (record[nums2[i]] == 0) {
        record.erase(nums2[i]);
      }
    }
  }

  return resultVector;
}

// Time: O(n)
// Space: O(n)
std::vector<int> SearchSolution::intersectOptimized(std::vector<int>& nums1,
                                                    std::vector<int>& nums2) {
  std::unordered_map<int, int> record;
  for (size_t i = 0; i < nums1.size(); ++i) {
    ++record[nums1[i]];
  }

  std::vector<int> resultVector;
  for (size_t i = 0; i < nums2.size(); ++i) {
    if (record[nums2[i]] > 0) {
      resultVector.push_back(nums2[i]);
      --record[nums2[i]];
    }
  }

  return resultVector;
}

// Time: O(n)
// Space: O(n)
std::vector<int> SearchSolution::twoSum(std::vector<int> nums, int target) {
  assert(nums.size() >= 2);

  std::unordered_map<int, int> record;
  for (size_t i = 0; i < nums.size(); ++i) {
    int complement = target - nums[i];
    if (record.find(complement) != record.end()) {
      int res[2] = {record[complement], (int)i};
      return std::vector<int>(res, res + 2);
    }

    record[nums[i]] = i;
  }

  throw std::invalid_argument("The input has no solution!");
}

// Time: O(n)
// Space: O(n)
bool SearchSolution::containNearbyDuplicate(std::vector<int>& nums, int k) {
  std::unordered_set<int> record;
  for (size_t i = 0; i < nums.size(); ++i) {
    if (record.find(nums[i]) != record.end()) {
      return true;
    }

    record.insert(nums[i]);

    if ((int)record.size() == k + 1) {
      record.erase(nums[i - k]);
    }
  }

  return false;
}
