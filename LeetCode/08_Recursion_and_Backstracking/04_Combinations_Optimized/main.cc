/*
 * 77. Combinations.
 *
 *  时间复杂度: O(n ^ k).
 *  空间复杂度: O(k).
 *
 *  Author: Erwin
 */

#include <iostream>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> combine(int n, int k) {
    res.clear();
    if (n <= 0 || k <= 0 || k > n) {
      return res;
    }

    std::vector<int> c;
    generateCombinations(n, k, 1, c);

    return res;
  }

 private:
  std::vector<std::vector<int>> res;

  // 求解 C(n, k), 当前已经找到的组合存储在 c 中, 需要从 start 开始搜索新的元素.
  void generateCombinations(int n, int k, int start, std::vector<int>& c) {
    if ((int)c.size() == k) {
      res.emplace_back(c);
      return;
    }

    // 还有 k - c.size() 个空位, 所以, [i, n] 中至少要有 k - c.size() 个元素.
    // i 最多为 n - (k - c.size()) + 1.
    for (int i = start; i <= n - (k - (int)c.size()) + 1; ++i) {
      c.emplace_back(i);
      generateCombinations(n, k, i + 1, c);
      c.pop_back();
    }

    return;
  }
};

int main() {
  std::vector<std::vector<int>> res = Solution().combine(4, 2);

  for (int i = 0; i < (int)res.size(); ++i) {
    for (int j = 0; j < (int)res[i].size(); ++j) {
      std::cout << res[i][j] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
