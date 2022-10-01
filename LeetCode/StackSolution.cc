/*
 * StackSolution.cc
 *
 *  Author: Erwin
 */

#include <LeetCode/StackSolution.h>

#include <cassert>
#include <stack>

bool StackSolution::isValid(std::string s) {
  std::stack<char> stack;

  for (size_t i = 0; i < s.size(); ++i) {
    if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
      stack.push(s[i]);
    } else {
      if (stack.size() == 0) {
        return false;
      }

      char c = stack.top();
      stack.pop();

      char match;
      if (s[i] == ')') {
        match = '(';
      } else if (s[i] == '}') {
        match = '{';
      } else {
        assert(s[i] == ']');
        match = '[';
      }

      if (c != match) {
        return false;
      }
    }
  }

  if (stack.size() != 0) {
    return false;
  }

  return true;
}
