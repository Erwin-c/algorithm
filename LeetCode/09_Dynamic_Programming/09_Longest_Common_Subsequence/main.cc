/*
 * LCS 问题.
 *
 *  记忆化搜索.
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
    memo.assign(s1.size(), std::vector<int>(s2.size(), -1));

    __LCS(s1, s2, s1.size() - 1, s2.size() - 1);

    return __getLCS(s1, s2);
  }

 private:
  std::vector<std::vector<int> > memo;

  // 求 s1[0, m] 和 s2[0, n] 的最长公共子序列的长度值.
  int __LCS(const std::string& s1, const std::string& s2, int m, int n) {
    if (m < 0 || n < 0) {
      return 0;
    }

    if (memo[m][n] != -1) {
      return memo[m][n];
    }

    int res = 0;
    if (s1[m] == s2[n]) {
      res = 1 + __LCS(s1, s2, m - 1, n - 1);
    } else {
      res = std::max(__LCS(s1, s2, m - 1, n), __LCS(s1, s2, m, n - 1));
    }

    memo[m][n] = res;

    return res;
  }

  // 通过 memo 反向求解 s1 和 s2 的最长公共子序列.
  std::string __getLCS(const std::string& s1, const std::string& s2) {
    int m = s1.size() - 1;
    int n = s2.size() - 1;

    std::string res = "";
    while (m >= 0 && n >= 0)
      if (s1[m] == s2[n]) {
        res = s1[m] + res;
        --m;
        --n;
      } else if (m == 0) {
        --n;
      } else if (n == 0) {
        --m;
      } else {
        if (memo[m - 1][n] > memo[m][n - 1]) {
          --m;
        } else {
          --n;
        }
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
