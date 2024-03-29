/*
 * 198. House Robber.
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
  int rob(std::vector<int>& nums) {
    int n = nums.size();

    if (n == 0) {
      return 0;
    }

    // memo[i] 表示考虑抢劫 nums[i, n) 所能获得的最大收益.
    std::vector<int> memo(n);
    memo[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      for (int j = i; j < n; ++j) {
        memo[i] = std::max(memo[i], nums[j] + (j + 2 < n ? memo[j + 2] : 0));
      }
    }

    return memo[0];
  }
};

int main() {
  int nums[] = {2, 7, 9, 3, 1};
  std::vector<int> vec(nums, nums + sizeof(nums) / sizeof(int));

  std::cout << Solution().rob(vec) << std::endl;

  return 0;
}
