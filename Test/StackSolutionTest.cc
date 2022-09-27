/*
 * StackSolutionTest.cc
 *
 *  Author: Erwin
 */

#include "LeetCode/StackSolution.h"
#include "gtest/gtest.h"

namespace {

TEST(StackSolutionTest, isValid) {
  std::string s1 = "(){}[]";
  std::string s2 = "{]";

  EXPECT_TRUE(StackSolution().isValid(s1));
  EXPECT_FALSE(StackSolution().isValid(s2));
}

}  // namespace
