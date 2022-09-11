/*
 * main.cc
 *
 *  Author: Erwin
 */

#include "gtest/gtest.h"

int main() {
  // Begin test
  ::testing::InitGoogleTest();

  ::testing::GTEST_FLAG(filter) = "*SolutionTest*";

  return RUN_ALL_TESTS();
}
