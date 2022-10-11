/*
 * RecursionSolutionTest.cc
 *
 *  Author: Erwin
 */

#include "LeetCode/RecursionSolution.h"
#include "gtest/gtest.h"

namespace {

TEST(RecursionSolutionTest, letterCombinations) {
  std::string digits = "23";
  std::vector<std::string> res{"ad", "ae", "af", "bd", "be",
                               "bf", "cd", "ce", "cf"};

  EXPECT_EQ(RecursionSolution().letterCombinations(digits), res);
}

TEST(RecursionSolutionTest, permute) {
  std::vector<int> nums{1, 2, 3};
  std::vector<std::vector<int>> res{{1, 2, 3}, {1, 3, 2}, {2, 1, 3},
                                    {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};

  EXPECT_EQ(RecursionSolution().permute(nums), res);
}

}  // namespace
