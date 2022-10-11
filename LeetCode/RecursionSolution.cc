/*
 * RecursionSolution.cc
 *
 *  Author: Erwin
 */

#include "LeetCode/RecursionSolution.h"

void RecursionSolution::findCombinations(const std::string& digits,
                                         size_t index, const std::string& s) {
  if (index == digits.size()) {
    res.push_back(s);
    return;
  }

  char c = digits[index];
  assert(c >= '0' && c <= '9' && c != '1');

  std::string letters = letterMap[c - '0'];
  for (size_t i = 0; i < letters.size(); ++i) {
    findCombinations(digits, index + 1, s + letters[i]);
  }

  return;
}

void RecursionSolution::generatePermutaion(const std::vector<int>& nums,
                                           size_t index, std::vector<int>& p) {
  if (index == nums.size()) {
    res2.push_back(p);
    return;
  }

  for (size_t i = 0; i < nums.size(); ++i) {
    if (!used[i]) {
      p.push_back(nums[i]);
      used[i] = true;
      generatePermutaion(nums, index + 1, p);
      p.pop_back();
      used[i] = false;
    }
  }

  return;
}

void RecursionSolution::generateCombinations(int n, int k, int start,
                                             std::vector<int>& c) {
  if (k == (int)c.size()) {
    res2.push_back(c);
    return;
  }

  for (int i = start; i <= n; ++i) {
    c.push_back(i);
    generateCombinations(n, k, i + 1, c);
    c.pop_back();
  }

  return;
}

void RecursionSolution::generateCombinationsOptimized(int n, int k, int start,
                                                      std::vector<int>& c) {
  if (k == (int)c.size()) {
    res2.push_back(c);
    return;
  }

  for (int i = start; i <= n - (k - (int)c.size()) + 1; ++i) {
    c.push_back(i);
    generateCombinations(n, k, i + 1, c);
    c.pop_back();
  }

  return;
}

// Time: O(2 ^ n)
std::vector<std::string> RecursionSolution::letterCombinations(
    std::string digits) {
  res.clear();

  if (digits == "") {
    return res;
  }

  findCombinations(digits, 0, "");

  return res;
}

// Time: O(2 ^ n)
std::vector<std::vector<int>> RecursionSolution::permute(
    std::vector<int>& nums) {
  res2.clear();

  if (nums.size() == 0) {
    return res2;
  }

  used = std::vector<bool>(nums.size(), false);

  std::vector<int> p;
  generatePermutaion(nums, 0, p);

  return res2;
}

// Time: O(2 ^ n)
std::vector<std::vector<int>> RecursionSolution::combine(int n, int k) {
  res2.clear();

  if (n <= 0 || k <= 0 || n < k) {
    return res2;
  }

  std::vector<int> p;
  generateCombinations(n, k, 1, p);

  return res2;
}

std::vector<std::vector<int>> RecursionSolution::combineOptimized(int n,
                                                                  int k) {
  res2.clear();

  if (n <= 0 || k <= 0 || n < k) {
    return res2;
  }

  std::vector<int> p;
  generateCombinationsOptimized(n, k, 1, p);

  return res2;
}
