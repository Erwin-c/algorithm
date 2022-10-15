/*
 * RecursionSolution.h
 *
 *  Author: Erwin
 */

#ifndef RECURSION_SOLUTION_H_
#define RECURSION_SOLUTION_H_

#include <cassert>
#include <string>
#include <vector>

class RecursionSolution {
 private:
  const std::string letterMap[10] = {
      " ",     // 10
      "",      // 1
      "abc",   // 2
      "def",   // 3
      "ghi",   // 4
      "jkl",   // 5
      "mno",   // 6
      "pqrs",  // 7
      "tuv",   // 8
      "wxyz"   // 9
  };

  std::vector<std::string> res;

  std::vector<std::vector<int>> res2;

  std::vector<bool> used;

  void findCombinations(const std::string& digits, size_t index,
                        const std::string& s);

  void generatePermutaion(const std::vector<int>& nums, size_t index,
                          std::vector<int>& p);

  void generateCombinations(int n, int k, int start, std::vector<int>& c);

  void generateCombinationsOptimized(int n, int k, int start,
                                     std::vector<int>& c);

 public:
  // 17.
  std::vector<std::string> letterCombinations(std::string digits);

  // 46.
  std::vector<std::vector<int>> permute(std::vector<int>& nums);

  // 77.
  std::vector<std::vector<int>> combine(int n, int k);

  // 77 optimized
  std::vector<std::vector<int>> combineOptimized(int n, int k);
};

#endif  // RECURSION_SOLUTION_H_
