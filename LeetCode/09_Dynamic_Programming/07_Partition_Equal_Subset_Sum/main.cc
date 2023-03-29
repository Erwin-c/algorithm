/*
 * 416. Partition Equal Subset Sum.
 *
 *  记忆化搜索.
 *
 *  时间复杂度: O(len(nums) * O(sum(nums))).
 *  空间复杂度: O(len(nums) * O(sum(nums))).
 *
 *  Author: Erwin
 */

#include <iostream>
#include <vector>

class Solution {
 public:
  bool canPartition(std::vector<int>& nums) {
    int sum = 0;
    for (int n : nums) {
      sum += n;
    }

    if (sum % 2 != 0) {
      return false;
    }

    int n = nums.size();

    memo.assign(n, std::vector<int>(sum / 2 + 1, -1));

    return tryPartition(nums, n - 1, sum / 2);
  }

 private:
  // memo[i][c].
  // 表示使用索引为 [0, i] 的这些元素, 是否可以完全填充一个容量为 c 的背包.
  // -1 表示为未计算; 0 表示不可以填充; 1 表示可以填充.
  std::vector<std::vector<int>> memo;

  // 使用 nums[0, index], 是否可以完全填充一个容量为 sum 的背包.
  bool tryPartition(const std::vector<int>& nums, int index, int sum) {
    if (sum == 0) {
      return true;
    }

    if (sum < 0 || index < 0) {
      return false;
    }

    if (memo[index][sum] != -1) {
      return memo[index][sum] == 1;
    }

    memo[index][sum] = (tryPartition(nums, index - 1, sum) ||
                        tryPartition(nums, index - 1, sum - nums[index]))
                           ? 1
                           : 0;

    return memo[index][sum] == 1;
  }
};

int main() {
  int nums1[] = {1, 5, 11, 5};
  std::vector<int> vec1(nums1, nums1 + sizeof(nums1) / sizeof(int));
  if (Solution().canPartition(vec1)) {
    std::cout << "true" << std::endl;
  } else {
    std::cout << "false" << std::endl;
  }

  int nums2[] = {1, 2, 3, 5};
  std::vector<int> vec2(nums2, nums2 + sizeof(nums2) / sizeof(int));
  if (Solution().canPartition(vec2)) {
    std::cout << "true" << std::endl;
  } else {
    std::cout << "false" << std::endl;
  }

  return 0;
}
