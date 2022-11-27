/*
 * DPSolutionTest.cc
 *
 *  Author: Erwin
 */

#include "LeetCode/DPSolution.h"
#include "gtest/gtest.h"

namespace {

TEST(DPSolutionTest, climbStairs) {
  int n = 3;
  int res = 3;

  EXPECT_EQ(DPSolution().climbStairs(n), res);
}

TEST(DPSolutionTest, climbStairsDP) {
  int n = 3;
  int res = 3;

  EXPECT_EQ(DPSolution().climbStairsDP(n), res);
}

TEST(DPSolutionTest, integerBreak) {
  int n = 10;
  int res = 36;

  EXPECT_EQ(DPSolution().integerBreak(n), res);
}

TEST(DPSolutionTest, integerBreakDP) {
  int n = 10;
  int res = 36;

  EXPECT_EQ(DPSolution().integerBreakDP(n), res);
}

TEST(DPSolutionTest, rob) {
  std::vector<int> nums{1, 2, 3, 1};
  int res = 4;

  EXPECT_EQ(DPSolution().rob(nums), res);
}

TEST(DPSolutionTest, robDP) {
  std::vector<int> nums{2, 7, 9, 3, 1};
  int res = 12;

  EXPECT_EQ(DPSolution().rob(nums), res);
}

}  // namespace
