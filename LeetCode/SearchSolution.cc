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

std::vector<int> SearchSolution::intersection(std::vector<int>& nums1,
                                              std::vector<int>& nums2) {
  std::unordered_set<int> record;
  for (int i = 0; i < (int)nums1.size(); ++i) {
    record.insert(nums1[i]);
  }

  std::unordered_set<int> resultSet;
  for (int i = 0; i < (int)nums2.size(); ++i) {
    if (record.find(nums2[i]) != record.end()) {
      resultSet.insert(nums2[i]);
    }
  }

  std::vector<int> resultVector;
  for (std::unordered_set<int>::iterator iter = resultSet.begin();
       iter != resultSet.end(); ++iter) {
    resultVector.push_back(*iter);
  }

  return resultVector;
}

std::vector<int> SearchSolution::intersectionOptimized(
    std::vector<int>& nums1, std::vector<int>& nums2) {
  std::unordered_set<int> record(nums1.begin(), nums1.end());

  std::unordered_set<int> resultSet;
  for (int i = 0; i < (int)nums2.size(); ++i) {
    if (record.find(nums2[i]) != record.end()) {
      resultSet.insert(nums2[i]);
    }
  }

  return std::vector<int>(resultSet.begin(), resultSet.end());
}

std::vector<int> SearchSolution::intersect(std::vector<int>& nums1,
                                           std::vector<int>& nums2) {
  std::unordered_map<int, int> record;
  for (int i = 0; i < (int)nums1.size(); ++i) {
    if (record.find(nums1[i]) == record.end()) {
      record.insert(std::make_pair(nums1[i], 1));
    } else {
      ++record[nums1[i]];
    }
  }

  std::vector<int> resultVector;
  for (int i = 0; i < (int)nums2.size(); ++i) {
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

std::vector<int> SearchSolution::intersectOptimized(std::vector<int>& nums1,
                                                    std::vector<int>& nums2) {
  std::unordered_map<int, int> record;
  for (int i = 0; i < (int)nums1.size(); ++i) {
    ++record[nums1[i]];
  }

  std::vector<int> resultVector;
  for (int i = 0; i < (int)nums2.size(); ++i) {
    if (record[nums2[i]] > 0) {
      resultVector.push_back(nums2[i]);
      --record[nums2[i]];
    }
  }

  return resultVector;
}

std::vector<int> SearchSolution::twoSum(std::vector<int> nums, int target) {
  assert(nums.size() >= 2);

  std::unordered_map<int, int> record;
  for (int i = 0; i < (int)nums.size(); ++i) {
    int complement = target - nums[i];
    if (record.count(complement) != 0) {
      int res[2] = {record[complement], (int)i};
      return std::vector<int>(res, res + 2);
    }

    record[nums[i]] = i;
  }

  // throw std::invalid_argument("The input has no solution!");
  return std::vector<int>();
}

int SearchSolution::fourSumCount(std::vector<int>& nums1,
                                 std::vector<int>& nums2,
                                 std::vector<int>& nums3,
                                 std::vector<int>& nums4) {
  std::unordered_map<int, int> record;
  for (const auto& p : nums1) {
    for (const auto& q : nums2) {
      ++record[p + q];
    }
  }

  int res = 0;
  for (const auto& p : nums3) {
    for (const auto& q : nums4) {
      if (record.count(0 - p - q) != 0) {
        res += record[0 - p - q];
      }
    }
  }

  return res;
}

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

bool SearchSolution::containNearbyAlmostDuplicate(std::vector<int> nums,
                                                  int indexDiff,
                                                  int valueDiff) {
  std::set<int> record;
  for (size_t i = 0; i < nums.size(); ++i) {
    if (record.lower_bound(nums[i] - valueDiff) != record.end() &&
        *record.lower_bound(nums[i] - valueDiff) <= nums[i] + valueDiff) {
      return true;
    }

    record.insert(nums[i]);

    if ((int)record.size() == indexDiff + 1) {
      record.erase(nums[i - indexDiff]);
    }
  }

  return false;
}
