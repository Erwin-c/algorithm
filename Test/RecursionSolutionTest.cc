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

TEST(RecursionSolutionTest, combine) {
  int n = 4, k = 2;
  std::vector<std::vector<int>> res{{1, 2}, {1, 3}, {1, 4},
                                    {2, 3}, {2, 4}, {3, 4}};

  EXPECT_EQ(RecursionSolution().combine(n, k), res);
}

TEST(RecursionSolutionTest, combineOptimized) {
  int n = 4, k = 2;
  std::vector<std::vector<int>> res{{1, 2}, {1, 3}, {1, 4},
                                    {2, 3}, {2, 4}, {3, 4}};

  EXPECT_EQ(RecursionSolution().combineOptimized(n, k), res);
}

TEST(RecursionSolutionTest, exist) {
  std::vector<std::vector<char>> board{
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  std::string word = "ABCCED";

  EXPECT_TRUE(RecursionSolution().exist(board, word));
}

TEST(RecursionSolutionTest, numIsIslands) {
  std::vector<std::vector<char>> grid{{'1', '1', '1', '1', '0'},
                                      {'1', '1', '0', '1', '0'},
                                      {'1', '1', '0', '0', '0'},
                                      {'0', '0', '0', '0', '0'}};
  int res = 1;

  EXPECT_EQ(RecursionSolution().numIsIslands(grid), res);
}

}  // namespace
