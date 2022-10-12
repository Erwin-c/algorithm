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

  void findCombinations(const std::string& digits, size_t index,
                        const std::string& s) {
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

 public:
  // 17.
  std::vector<std::string> letterCombinations(std::string digits);
};

#endif  // RECURSION_SOLUTION_H_
