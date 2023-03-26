/*
 * 70. Climbing Stairs.
 *
 *  记忆化搜索.
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
    memo.assign(n + 1, -1);

    return calcWays(n);
  }

 private:
  std::vector<int> memo;

  int calcWays(int n) {
    if (n == 1) {
      return 1;
    }

    if (n == 2) {
      return 2;
    }

    if (memo[n] == -1) {
      memo[n] = calcWays(n - 1) + calcWays(n - 2);
    }

    return memo[n];
  }
};

int main() {
  std::cout << Solution().climbStairs(10) << std::endl;

  return 0;
}
