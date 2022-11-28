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
  // 70. Climbing Stairs (记忆化搜索).
  // 时间复杂度: O(n).
  // 空间复杂度: O(n).
  int climbStairs(int n);

  // 70. Climbing Stairs (DP).
  // 时间复杂度: O(n).
  // 空间复杂度: O(n).
  int climbStairsDP(int n);

  // 343. Integer Break (记忆化搜索).
  // 时间复杂度: O(n ^ 2).
  // 空间复杂度: O(n).
  int integerBreak(int n);

  // 343. Integer Break (DP).
  // 时间复杂度: O(n ^ 2).
  // 空间复杂度: O(n).
  int integerBreakDP(int n);

  // 198. House Robber (记忆化搜索).
  // 时间复杂度: O(n ^ 2).
  // 空间复杂度: O(n).
  int rob(std::vector<int>& nums);

  // 198. House Robber (DP).
  // 时间复杂度: O(n ^ 2).
  // 空间复杂度: O(n).
  int robDP(std::vector<int>& nums);

  // 背包问题 (记忆化搜索).
  // 时间复杂度: O(n * C), 其中 n 为物品个数, C 为背包容积.
  // 空间复杂度: O(n * C).
  int knapsack01(const std::vector<int>& w, const std::vector<int>& v, int C);

  // 背包问题 (DP).
  // 时间复杂度: O(n * C), 其中 n 为物品个数, C 为背包容积.
  // 空间复杂度: O(n * C).
  int knapsack01DP(const std::vector<int>& w, const std::vector<int>& v, int C);

  // 背包问题 (DP Optimized).
  // 时间复杂度: O(n * C) 其中 n 为物品个数, C 为背包容积.
  // 空间复杂度: O(C), 只使用了 C 的额外空间.
  int knapsack01DPOptimized(const std::vector<int>& w,
                            const std::vector<int>& v, int C);

 private:
  std::vector<int> memo;  // 70. Climbing Stairs (记忆化搜索).
                          // 343. Integer Break (记忆化搜索).
                          // 198. House Robber (记忆化搜索).

  std::vector<std::vector<int>> memo2;  // 背包问题 (记忆化搜索).

  // 70. Climbing Stairs (记忆化搜索).
  int calcWays(int n);

  int max3(int a, int b, int c);

  // 343. Integer Break (记忆化搜索).
  // 将 n 进行分割 (至少分割两部分), 可以获得的最大乘积.
  int breakInteger(int n);

  // 198. House Robber (记忆化搜索).
  // 考虑抢劫 nums[index...nums.size()) 这个范围的所有房子.
  int tryRob(const std::vector<int>& nums, int index);

  // 背包问题 (记忆化搜索).
  // 用 [0 ... index] 的物品, 填充容积为 c 的背包的最大价值.
  int bestValue(const std::vector<int>& w, const std::vector<int>& v, int index,
                int c);
};

#endif  // DP_SOLUTION_H_
