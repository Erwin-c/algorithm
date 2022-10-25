/*
 * ArraySolution.cc
 *
 *  Author: Erwin
 */

#include "LeetCode/ArraySolution.h"

#include <cassert>
#include <stdexcept>

void ArraySolution::moveZeros(std::vector<int>& nums) {
  // nums 中, [0 ... k) 的元素均为非 0 元素.
  size_t k = 0;

  // 遍历到第 i 个元素后, 保证 [0 ... i] 中所有非 0 元素,
  // 都按照顺序排列在 [0 ... k) 中, 同时, [k ... i] 为 0.
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

void ArraySolution::sortColors(std::vector<int>& nums) {
  // 存放 0, 1, 2 三个元素的频率.
  int count[3] = {0};

  for (size_t i = 0; i < nums.size(); ++i) {
    assert(nums[i] >= 0 && nums[i] <= 2);
    ++count[nums[i]];
  }

  int index = 0;
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

void ArraySolution::sortColorsOptimized(std::vector<int>& nums) {
  int zero = -1;             // nums[0 ... zero] = 0.
  size_t two = nums.size();  // nums[two ... n) = 2.

  for (size_t i = 0; i < two;) {  // nums[(zero + 1) ... i) = 1.
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

std::vector<int> ArraySolution::twoSumOptimized(std::vector<int>& numbers,
                                                int target) {
  assert(numbers.size() >= 2);

  std::vector<int> res;

  int l = 0, r = (int)numbers.size() - 1;
  while (l < r) {
    if (target == numbers[l] + numbers[r]) {
      res.push_back(l + 1);
      res.push_back(r + 1);
      return res;
    } else if (target > numbers[l] + numbers[r]) {
      ++l;
    } else {
      --r;
    }
  }

  // throw std::invalid_argument("The input has no solution!");
  return res;
}

int ArraySolution::minSubArrayLen(int target, std::vector<int>& nums) {
  assert(target > 0);

  int size = (int)nums.size();
  // 滑动窗口为 nums[l ... r].
  int l = 0, r = -1;
  int res = size + 1;

  int sum = 0;
  while (l < size) {  // 窗口的左边界在数组范围内, 则循环继续.
    if (target > sum && r + 1 < size) {
      sum += nums[++r];
    } else {  // r 已经到头 或者 sum >= s.
      sum -= nums[l++];
    }

    if (target <= sum) {
      res = std::min(res, r - l + 1);
    }
  }

  if (res == size + 1) {
    return 0;
  }

  return res;
}

int ArraySolution::lengthOfLongestSubstring(std::string s) {
  int size = (int)s.size();
  int freq[256] = {0};
  //滑动窗口为 s[l ... r].
  int l = 0, r = -1;
  int res = 0;

  // TBD: 在这里, 循环中止的条件可以是 r + 1 < s.size(), 想想看为什么?
  while (l < size) {
    if (freq[(int)s[r + 1]] == 0 && r + 1 < size) {
      ++freq[(int)s[++r]];
    } else {
      --freq[(int)s[l++]];
    }

    res = std::max(res, r - l + 1);
  }

  return res;
}
