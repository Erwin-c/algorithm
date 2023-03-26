/*
 * ArraySolution.cc
 *
 *  Author: Erwin
 */

#include "LeetCode/ArraySolution.h"

#include <cassert>
#include <stdexcept>

void ArraySolution::moveZeros(std::vector<int>& nums) {
  // nums 中, [0, fast) 的元素均为非 0 元素.

  // 遍历到第 fast 个元素.
  // 保证 [0, fast] 中所有非 0 元素, 都按照顺序排列在 [0, slow) 中.
  // 同时, [slow...fast] 为 0.

  int slow = 0, fast = 0;
  while (fast < (int)nums.size()) {
    if (nums[fast] != 0) {
      if (fast != slow) {
        std::swap(nums[fast], nums[slow++]);
      } else {
        ++slow;
      }
    }

    ++fast;
  }

  return;
}

void ArraySolution::sortColors(std::vector<int>& nums) {
  int n = nums.size();
  if (n == 0) {
    return;
  }

  // 存放 0, 1, 2 三个元素的频率.
  int count[3] = {0};

  for (int i = 0; i < n; ++i) {
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
  int left = -1;            // nums[0, left] = 0.
  int right = nums.size();  // nums[right, n) = 2.

  for (int i = 0; i < right;) {  // nums[(left + 1), i) = 1.
    if (nums[i] == 1) {
      ++i;
    } else if (nums[i] == 2) {
      std::swap(nums[--right], nums[i]);
    } else {
      assert(nums[i] == 0);
      std::swap(nums[++left], nums[i++]);
    }
  }

  return;
}

std::vector<int> ArraySolution::twoSumOptimized(std::vector<int>& numbers,
                                                int target) {
  assert(numbers.size() >= 2);

  std::vector<int> res;

  int l = 0, r = numbers.size() - 1;
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

  int size = nums.size();
  int res = size + 1;

  // 滑动窗口为 nums[l, r].
  int sum = 0;
  int l = 0, r = -1;
  while (l < size) {  // 窗口的左边界在数组范围内, 则循环继续.
    if (sum <= target && r + 1 < size) {
      sum += nums[++r];
    } else {  // r 已经到头 或者 sum >= s.
      sum -= nums[l++];
    }

    if (sum >= target) {
      res = std::min(res, r - l + 1);
    }
  }

  return res == size + 1 ? 0 : res;
}

int ArraySolution::lengthOfLongestSubstring(std::string s) {
  int freq[256] = {0};

  int size = s.size();
  int res = 0;

  // 滑动窗口为 s[l, r].
  int l = 0, r = -1;
  // 整个循环从 l == 0; r == -1 这个空窗口开始.
  // 到 l == s.size(); r == s.size() - 1 这个空窗口截止.
  // 在每次循环里逐渐改变窗口, 维护 freq.
  // 并记录当前窗口中是否找到了一个新的最优值.
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
