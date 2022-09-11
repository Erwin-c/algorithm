/*
 * ArraySolutionTest.cc
 *
 *  Author: Erwin
 */

#include "LeetCode/ArraySolution.h"
#include "gtest/gtest.h"

namespace {

TEST(ArraySolutionTest, moveZeros) {
  std::vector<int> vec{0, 1, 0, 3, 12};
  std::vector<int> res{1, 3, 12, 0, 0};

  ArraySolution().moveZeros(vec);

  EXPECT_EQ(vec, res);
}

TEST(ArraySolutionTest, sortColors) {
  std::vector<int> vec{0, 2, 2, 1, 0, 2, 2, 0, 2, 1, 0};
  std::vector<int> res{0, 0, 0, 0, 1, 1, 2, 2, 2, 2, 2};

  ArraySolution().sortColors(vec);

  EXPECT_EQ(vec, res);
}

TEST(ArraySolutionTest, sortColorsOptimized) {
  std::vector<int> vec{0, 2, 2, 1, 0, 2, 2, 0, 2, 1, 0};
  std::vector<int> res{0, 0, 0, 0, 1, 1, 2, 2, 2, 2, 2};

  ArraySolution().sortColorsOptimized(vec);

  EXPECT_EQ(vec, res);
}

// TBD: TEST(ArraySolutionTest, twoSum)

TEST(ArraySolutionTest, twoSumOptimized) {
  int target = 9;
  std::vector<int> vec{2, 7, 11, 15};
  std::vector<int> res{1, 2};

  EXPECT_EQ(ArraySolution().twoSumOptimized(vec, target), res);
}

TEST(ArraySolutionTest, minSubArrayLen) {
  int target = 7;
  std::vector<int> vec{2, 3, 1, 2, 4, 3};
  int res = 2;

  EXPECT_EQ(ArraySolution().minSubArrayLen(target, vec), res);
}

TEST(ArraySolutionTest, lengthOfLongestSubstring) {
  std::string s = "abcabcbb";
  int res = 3;

  EXPECT_EQ(ArraySolution().lengthOfLongestSubstring(s), res);
}

}  // namespace
