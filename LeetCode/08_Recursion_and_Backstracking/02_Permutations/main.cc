/*
 * 46. Permutations.
 *
 *  时间复杂度: O(n ^ n).
 *  空间复杂度: O(n).
 *
 *  Author: Erwin
 */

#include <iostream>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    res.clear();
    if (nums.size() == 0) {
      return res;
    }

    used.assign(nums.size(), false);
    std::vector<int> p;
    generatePermutation(nums, 0, p);

    return res;
  }

 private:
  std::vector<std::vector<int>> res;
  std::vector<bool> used;

  // p 中保存了一个有 index-1 个元素的排列.
  // 向这个排列的末尾添加第 index 个元素, 获得一个有 index 个元素的排列.
  void generatePermutation(const std::vector<int>& nums, int index,
                           std::vector<int>& p) {
    if (index == (int)nums.size()) {
      res.emplace_back(p);
      return;
    }

    for (int i = 0; i < (int)nums.size(); ++i)
      if (!used[i]) {
        used[i] = true;
        p.emplace_back(nums[i]);
        generatePermutation(nums, index + 1, p);
        p.pop_back();
        used[i] = false;
      }

    return;
  }
};

int main() {
  int nums[] = {1, 2, 3};
  std::vector<int> vec(nums, nums + sizeof(nums) / sizeof(int));

  std::vector<std::vector<int>> res = Solution().permute(vec);
  for (int i = 0; i < (int)res.size(); ++i) {
    for (int j = 0; j < (int)res[i].size(); ++j) {
      std::cout << res[i][j] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
