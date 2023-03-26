/*
 * 343. Integer Break.
 *
 *  动态规划.
 *
 *  时间复杂度: O(n ^ 2).
 *  空间复杂度: O(n).
 *
 *  Author: Erwin
 */

#include <iostream>
#include <vector>

class Solution {
 public:
  int integerBreak(int n) {
    // memo[i] 表示将数字 i 分割 (至少分割成两部分) 后得到的最大乘积.
    std::vector<int> memo(n + 1, -1);

    memo[1] = 1;
    for (int i = 2; i <= n; ++i) {
      // 求解 memo[i].
      for (int j = 1; j <= i - 1; ++j) {
        // j 分割成 j + (i - j).
        memo[i] = max3(memo[i], j * (i - j), j * memo[i - j]);
      }
    }

    return memo[n];
  }

 private:
  int max3(int a, int b, int c) { return std::max(a, std::max(b, c)); }
};

int main() {
  std::cout << Solution().integerBreak(2) << std::endl;
  std::cout << Solution().integerBreak(10) << std::endl;

  return 0;
}
