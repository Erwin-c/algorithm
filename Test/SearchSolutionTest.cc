/*
 * SearchSolutionTest.cc
 *
 *  Author: Erwin
 */

#include "LeetCode/SearchSolution.h"
#include "gtest/gtest.h"

namespace {

TEST(SearchSolutionTest, intersection) {
  std::vector<int> vec1{4, 9, 5};
  std::vector<int> vec2{9, 4, 9, 8, 4};
  std::vector<int> res{4, 9};

  EXPECT_EQ(SearchSolution().intersection(vec1, vec2), res);
}

TEST(SearchSolutionTest, intersectionOptimized) {
  std::vector<int> vec1{4, 9, 5};
  std::vector<int> vec2{9, 4, 9, 8, 4};
  std::vector<int> res{4, 9};

  EXPECT_EQ(SearchSolution().intersectionOptimized(vec1, vec2), res);
}

TEST(SearchSolutionTest, intersect) {
  std::vector<int> vec1{1, 2, 2, 1};
  std::vector<int> vec2{2, 2};
  std::vector<int> res{2, 2};

  EXPECT_EQ(SearchSolution().intersect(vec1, vec2), res);
}

TEST(SearchSolutionTest, intersectOptimized) {
  std::vector<int> vec1{1, 2, 2, 1};
  std::vector<int> vec2{2, 2};
  std::vector<int> res{2, 2};

  EXPECT_EQ(SearchSolution().intersectOptimized(vec1, vec2), res);
}

TEST(SearchSolutionTest, twoSum) {
  int target = 6;
  std::vector<int> vec{3, 2, 4};
  std::vector<int> res{1, 2};

  EXPECT_EQ(SearchSolution().twoSum(vec, target), res);
}

TEST(SearchSolutionTest, containNearbyDuplicate) {
  int k = 2;
  std::vector<int> vec{1, 2, 3, 1, 2, 3};

  EXPECT_FALSE(SearchSolution().containNearbyDuplicate(vec, k));
}

}  // namespace
