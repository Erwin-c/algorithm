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

}  // namespace
