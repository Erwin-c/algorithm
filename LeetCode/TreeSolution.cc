/*
 * TreeSolution.cc
 *
 *  Author: Erwin
 */

#include "LeetCode/TreeSolution.h"

#include <cassert>
#include <stack>
#include <string>

struct Command {
  std::string s;  // go, print
  TreeNode* node;
  Command(std::string s, TreeNode* node) : s(s), node(node) {}
};

std::vector<int> TreeSolution::preorderTraversal(TreeNode* root) {
  std::vector<int> res;
  if (root == nullptr) {
    return res;
  }

  std::stack<Command> stack;
  stack.push(Command("go", root));
  while (!stack.empty()) {
    Command command = stack.top();
    stack.pop();

    if (command.s == "print") {
      res.push_back(command.node->val);
    } else {
      assert(command.s == "go");

      if (command.node->right != nullptr) {
        stack.push(Command("go", command.node->right));
      }
      if (command.node->left != nullptr) {
        stack.push(Command("go", command.node->left));
      }

      stack.push(Command("print", command.node));
    }
  }

  return res;
}
