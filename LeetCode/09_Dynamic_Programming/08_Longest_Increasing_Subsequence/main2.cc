/*
 * 300. Longest Increasing Subsequence.
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
  int lengthOfLIS(std::vector<int>& nums) {
    int n = nums.size();

    if (n == 0) {
      return 0;
    }

    // memo[i] 表示以 nums[i] 为结尾的最长上升子序列的长度.
    std::vector<int> memo(n, 1);
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] > nums[j]) {
          memo[i] = std::max(memo[i], 1 + memo[j]);
        }
      }
    }

    int res = memo[0];
    for (int i = 1; i < n; ++i) {
      res = std::max(res, memo[i]);
    }

    return res;
  }
};

int main() {
  int nums1[] = {10, 9, 2, 5, 3, 7, 101, 18};
  std::vector<int> vec1(nums1, nums1 + sizeof(nums1) / sizeof(int));
  std::cout << Solution().lengthOfLIS(vec1) << std::endl;
  // 4.

  int nums2[] = {4, 10, 4, 3, 8, 9};
  std::vector<int> vec2(nums2, nums2 + sizeof(nums2) / sizeof(int));
  std::cout << Solution().lengthOfLIS(vec2) << std::endl;
  // 3.

  int nums3[] = {2, 2};
  std::vector<int> vec3(nums3, nums3 + sizeof(nums3) / sizeof(int));
  std::cout << Solution().lengthOfLIS(vec3) << std::endl;
  // 1.

  int nums4[] = {1, 3, 6, 7, 9, 4, 10, 5, 6};
  std::vector<int> vec4(nums4, nums4 + sizeof(nums4) / sizeof(int));
  std::cout << Solution().lengthOfLIS(vec4) << std::endl;
  // 6.

  return 0;
}
