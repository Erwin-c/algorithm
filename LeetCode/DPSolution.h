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

 private:
  std::vector<int> memo;  // 70. Climbing Stairs (记忆化搜索).
                          // 343. Integer Break (记忆化搜索).
                          // 198. House Robber (记忆化搜索).

  // 70. Climbing Stairs (记忆化搜索).
  int calcWays(int n);

  int max3(int a, int b, int c);

  // 343. Integer Break (记忆化搜索).
  // 将 n 进行分割 (至少分割两部分), 可以获得的最大乘积.
  int breakInteger(int n);

  // 198. House Robber (记忆化搜索).
  // 考虑抢劫 nums[index...nums.size()) 这个范围的所有房子.
  int tryRob(const std::vector<int>& nums, int index);
};

#endif  // DP_SOLUTION_H_
