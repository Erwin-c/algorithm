/*
 * QueueSolutionTest.cc
 *
 *  Author: Erwin
 */

#include "LeetCode/QueueSolution.h"
#include "gtest/gtest.h"

namespace {

TEST(QueueSolutionTest, numSquares) {
  int n = 12;
  int res = 3;

  EXPECT_EQ(QueueSolution().numSquares(n), res);
}

TEST(QueueSolutionTest, topKFrequent) {
  std::vector<int> vec{1, 1, 1, 2, 2, 3};
  int k = 2;

  std::vector<int> res{2, 1};

  EXPECT_EQ(QueueSolution().topKFrequent(vec, k), res);
}

}  // namespace
