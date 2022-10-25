/*
 * DPSolution.cc
 *
 *  Author: Erwin
 */

#include "LeetCode/DPSolution.h"

int DPSolution::climbStairs(int n) {
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

int DPSolution::calcWays(int n) {
  if (n == 0 || n == 1) {
    return 1;
  }

  if (memo[n] == -1) {
    memo[n] = calcWays(n - 1) + calcWays(n - 2);
  }

  return memo[n];
}
