/*
 * 343. Integer Break.
 *
 *  记忆化搜索.
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
    memo.assign(n + 1, -1);

    return breakInteger(n);
  }

 private:
  std::vector<int> memo;

  int max3(int a, int b, int c) { return std::max(a, std::max(b, c)); }

  // 将 n 进行分割 (至少分割两部分), 可以获得的最大乘积.
  int breakInteger(int n) {
    if (n == 1) {
      return 1;
    }

    if (memo[n] != -1) {
      return memo[n];
    }

    int res = -1;
    for (int i = 1; i <= n - 1; ++i) {
      // n 分割成 i + (n - i).
      res = max3(res, i * (n - i), i * breakInteger(n - i));
    }

    memo[n] = res;

    return res;
  }
};

int main() {
  std::cout << Solution().integerBreak(2) << std::endl;
  std::cout << Solution().integerBreak(10) << std::endl;

  return 0;
}
