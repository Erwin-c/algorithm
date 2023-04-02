/*
 * LCS 问题.
 *
 *  动态规划, 躲避边界条件.
 *
 *  时间复杂度: O(len(s1) * len(s2)).
 *  空间复杂度: O(len(s1) * len(s2)).
 *
 *  Author: Erwin
 */

#include <iostream>
#include <string>
#include <vector>

class LCS {
 public:
  std::string getLCS(const std::string& s1, const std::string& s2) {
    int m = s1.size();
    int n = s2.size();

    // memo 是 (m + 1) * (n + 1) 的动态规划表格.
    // memo[i][j] 表示 s1 的前 i 个字符和 s2 前 j 个字符的最长公共子序列的长度.
    // 其中 memo[0][j] 表示 s1 取空字符串时, 和 s2 的前 j 个字符作比较.
    // memo[i][0] 表示 s2 取空字符串时, 和 s1 的前 i 个字符作比较.
    // 所以, memo[0][j] 和 memo[i][0] 均取0.
    // 我们不需要对 memo 进行单独的边界条件处理.
    std::vector<std::vector<int> > memo(m + 1, std::vector<int>(n + 1));

    // 动态规划的过程.
    // 注意, 由于动态规划状态的转变, 下面的 i 和 j 可以取到 m 和 n.
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (s1[i - 1] == s2[j - 1]) {
          memo[i][j] = 1 + memo[i - 1][j - 1];
        } else {
          memo[i][j] = std::max(memo[i - 1][j], memo[i][j - 1]);
        }
      }
    }

    // 通过 memo 反向求解 s1 和 s2 的最长公共子序列.
    m = s1.size();
    n = s2.size();
    std::string res = "";
    while (m > 0 && n > 0)
      if (s1[m - 1] == s2[n - 1]) {
        res = s1[m - 1] + res;
        --m;
        --n;
      } else if (memo[m - 1][n] > memo[m][n - 1]) {
        --m;
      } else {
        --n;
      }

    return res;
  }
};

int main() {
  std::string s1, s2;
  std::cin >> s1 >> s2;
  std::cout << LCS().getLCS(s1, s2) << std::endl;

  return 0;
}