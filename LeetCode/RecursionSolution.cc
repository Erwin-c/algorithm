/*
 * RecursionSolution.cc
 *
 *  Author: Erwin
 */

#include "LeetCode/RecursionSolution.h"

std::vector<std::string> RecursionSolution::letterCombinations(
    std::string digits) {
  res.clear();

  if (digits == "") {
    return res;
  }

  findCombinations(digits, 0, "");

  return res;
}
