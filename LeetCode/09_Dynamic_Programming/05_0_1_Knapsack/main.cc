/*
 * 0-1 背包问题.
 *
 *  记忆化搜索.
 *
 *  时间复杂度: O(n * C).
 *  空间复杂度: O(n * C).
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

    if (n == 0 || C == 0) {
      return 0;
    }

    memo.assign(n, std::vector<int>(C + 1, -1));

    return bestValue(w, v, n - 1, C);
  }

 private:
  std::vector<std::vector<int>> memo;

  // 用 [0, index] 的物品, 填充容积为 c 的背包的最大价值.
  int bestValue(const std::vector<int>& w, const std::vector<int>& v, int index,
                int c) {
    if (c <= 0 || index < 0) {
      return 0;
    }

    if (memo[index][c] != -1) {
      return memo[index][c];
    }

    // 不选择 index 物品的策略.
    int res = bestValue(w, v, index - 1, c);
    if (c >= w[index]) {
      res = std::max(res, v[index] + bestValue(w, v, index - 1, c - w[index]));
    }

    memo[index][c] = res;

    return res;
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
