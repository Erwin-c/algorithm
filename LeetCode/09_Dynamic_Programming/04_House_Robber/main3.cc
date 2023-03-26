/*
 * 198. House Robber.
 *
 *  记忆化搜索, 改变状态定义.
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
    memo.assign(nums.size(), -1);

    return tryRob(nums, nums.size() - 1);
  }

 private:
  // memo[i] 表示考虑抢劫 nums[0, i] 所能获得的最大收益.
  std::vector<int> memo;

  // 考虑抢劫 nums[0, index] 这个范围的所有房子.
  int tryRob(const std::vector<int>& nums, int index) {
    if (index < 0) {
      return 0;
    }

    if (memo[index] != -1) {
      return memo[index];
    }

    int res = 0;
    for (int i = 0; i <= index; ++i) {
      res = std::max(res, nums[i] + tryRob(nums, i - 2));
    }

    memo[index] = res;

    return res;
  }
};

int main() {
  int nums[] = {2, 7, 9, 3, 1};
  std::vector<int> vec(nums, nums + sizeof(nums) / sizeof(int));

  std::cout << Solution().rob(vec) << std::endl;

  return 0;
}
