/*
 * DPSolution.cc
 *
 *  Author: Erwin
 */

#include "LeetCode/DPSolution.h"

#include <cassert>

int DPSolution::climbStairs(int n) {
  memo.clear();

  memo = std::vector<int>(n + 1, -1);

  return calcWays(n);
}

int DPSolution::climbStairsDP(int n) {
  std::vector<int> memo(n + 1, -1);

  memo[0] = 1;
  memo[1] = 1;

  for (int i = 2; i <= n; ++i) {
    memo[i] = memo[i - 1] + memo[i - 2];
  }

  return memo[n];
}

int DPSolution::integerBreak(int n) {
  assert(n >= 2);

  memo.clear();

  memo = std::vector<int>(n + 1, -1);

  return breakInteger(n);
}

int DPSolution::integerBreakDP(int n) {
  assert(n >= 2);

  // memo[i] 表示将数字 i 分割 (至少分割成两部分) 后得到的最大乘积.
  std::vector<int> memo(n + 1, -1);

  memo[1] = 1;
  for (int i = 2; i <= n; ++i) {
    // 求解 memo[i].
    for (int j = 1; j <= i - 1; ++j) {
      // j + (i - j).
      memo[i] = max3(memo[i], j * (i - j), j * memo[i - j]);
    }
  }

  return memo[n];
}

int DPSolution::rob(std::vector<int>& nums) {
  memo.clear();

  // memo[i] 表示考虑抢劫 nums[i...n) 所能获得的最大收益.
  memo = std::vector<int>(nums.size(), -1);

  return tryRob(nums, 0);
}

int DPSolution::robDP(std::vector<int>& nums) {
  int n = (int)nums.size();

  if (n == 0) {
    return 0;
  }

  // memo[i] 表示考虑抢劫 nums[i...n) 所能获得的最大收益.
  std::vector<int> memo(n, -1);
  memo[n - 1] = nums[n - 1];

  for (int i = n - 2; i >= 0; --i) {
    for (int j = i; j < n; ++j) {
      memo[i] = std::max(memo[i], nums[j] + (j + 2 < n ? memo[j + 2] : 0));
    }
  }

  return memo[0];
}

int DPSolution::calcWays(int n) {
  if (n == 0 || n == 1) {
    return 1;
  }

  if (memo[n] == -1) {
    memo[n] = calcWays(n - 1) + calcWays(n - 2);
  }

  return memo[n];
}

int DPSolution::max3(int a, int b, int c) {
  return std::max(a, std::max(b, c));
}

int DPSolution::breakInteger(int n) {
  if (n == 1) {
    return 1;
  }

  if (memo[n] != -1) {
    return memo[n];
  }

  int res = -1;
  for (int i = 1; i <= n - 1; ++i) {
    // i * (n - i).
    res = max3(res, i * (n - i), i * breakInteger(n - i));
  }

  memo[n] = res;

  return res;
}

int DPSolution::tryRob(const std::vector<int>& nums, int index) {
  if (index >= (int)nums.size()) {
    return 0;
  }

  if (memo[index] != -1) {
    return memo[index];
  }

  int res = 0;
  for (int i = index; i < (int)nums.size(); ++i) {
    res = std::max(res, nums[i] + tryRob(nums, i + 2));
  }

  memo[index] = res;

  return res;
}
