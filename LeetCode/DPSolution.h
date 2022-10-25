/*
 * DPSolution.h
 *
 *  Author: Erwin
 */

#ifndef DP_SOLUTION_H_
#define DP_SOLUTION_H_

#include <vector>

class DPSolution {
 public:
  // 70. Climbing Stairs.
  /// 记忆化搜索.
  /// 时间复杂度: O(n).
  /// 空间复杂度: O(n).
  int climbStairs(int n);

  // 70. Climbing Stairs (DP).
  // DP
  // 时间复杂度: O(n).
  // 空间复杂度: O(n).
  int climbStairsDP(int n);

 private:
  std::vector<int> memo;  // 70. Climbing Stairs.

  // 70. Climbing Stairs.
  int calcWays(int n);
};

#endif  // DP_SOLUTION_H_
