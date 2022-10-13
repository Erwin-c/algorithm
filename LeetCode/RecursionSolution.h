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

 public:
  // 17.
  std::vector<std::string> letterCombinations(std::string digits);

  // 46.
  std::vector<std::vector<int>> permute(std::vector<int>& nums);
};

#endif  // RECURSION_SOLUTION_H_
