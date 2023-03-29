/*
 * 416. Partition Equal Subset Sum.
 *
 *  动态规划.
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

    int n = nums.size(), C = sum / 2;
    std::vector<bool> memo(C + 1, false);
    for (int i = 0; i <= C; ++i) {
      memo[i] = (nums[0] == i);
    }

    for (int i = 1; i < n; ++i) {
      for (int j = C; j >= nums[i]; --j) {
        memo[j] = memo[j] || memo[j - nums[i]];
      }
    }

    return memo[C];
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
