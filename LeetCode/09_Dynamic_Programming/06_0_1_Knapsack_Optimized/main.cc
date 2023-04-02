/*
 * 0-1 背包问题.
 *
 *  动态规划改进: 滚动数组.
 *
 *  时间复杂度: O(n * C).
 *  空间复杂度: O(C), 实际使用了 2 * C 的额外空间.
 *    其中 n 为物品个数; C 为背包容积.
 *
 *  Author: Erwin
 */

#include <iostream>
#include <vector>

class Knapsack01 {
 public:
  int knapsack01(const std::vector<int>& w, const std::vector<int>& v, int C) {
    int n = w.size();
    if (n == 0 && C == 0) {
      return 0;
    }

    std::vector<std::vector<int>> memo(2, std::vector<int>(C + 1));

    for (int j = 0; j <= C; ++j) {
      memo[0][j] = j >= w[0] ? v[0] : 0;
    }

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j <= C; ++j) {
        memo[i % 2][j] = memo[(i - 1) % 2][j];
        if (j >= w[i]) {
          memo[i % 2][j] =
              std::max(memo[i % 2][j], v[i] + memo[(i - 1) % 2][j - w[i]]);
        }
      }
    }

    return memo[(n - 1) % 2][C];
  }
};

int main() {
  int n, W;
  std::cin >> n >> W;

  int v, w;
  std::vector<int> vs, ws;
  for (int i = 0; i < n; ++i) {
    std::cin >> w >> v;
    vs.emplace_back(v);
    ws.emplace_back(w);
  }

  std::cout << Knapsack01().knapsack01(ws, vs, W) << std::endl;

  return 0;
}
