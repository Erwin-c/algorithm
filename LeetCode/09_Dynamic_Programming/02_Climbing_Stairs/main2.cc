/*
 * 70. Climbing Stairs.
 *
 *  动态规划.
 *
 *  时间复杂度: O(n).
 *  空间复杂度: O(n).
 *
 *  Author: Erwin
 */

#include <iostream>
#include <vector>

class Solution {
 public:
  int climbStairs(int n) {
    std::vector<int> memo(n + 1, -1);
    memo[0] = 1, memo[1] = 1;

    for (int i = 2; i <= n; ++i) {
      memo[i] = memo[i - 1] + memo[i - 2];
    }

    return memo[n];
  }
};

int main() {
  std::cout << Solution().climbStairs(10) << std::endl;

  return 0;
}
