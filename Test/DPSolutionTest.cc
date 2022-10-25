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

}  // namespace
