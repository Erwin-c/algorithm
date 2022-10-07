/*
 * TreeSolution.cc
 *
 *  Author: Erwin
 */

#include "LeetCode/TreeSolution.h"

#include <cassert>
#include <queue>
#include <stack>
#include <string>

struct Command {
  std::string s;  // go, print.
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

std::vector<int> TreeSolution::inorderTraversal(TreeNode* root) {
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

      stack.push(Command("print", command.node));

      if (command.node->left != nullptr) {
        stack.push(Command("go", command.node->left));
      }
    }
  }

  return res;
}

std::vector<int> TreeSolution::postorderTraversal(TreeNode* root) {
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

      stack.push(Command("print", command.node));

      if (command.node->right != nullptr) {
        stack.push(Command("go", command.node->right));
      }

      if (command.node->left != nullptr) {
        stack.push(Command("go", command.node->left));
      }
    }
  }

  return res;
}

std::vector<std::vector<int>> TreeSolution::levelOrder(TreeNode* root) {
  std::vector<std::vector<int>> res;
  if (root == nullptr) {
    return res;
  }

  std::queue<std::pair<TreeNode*, int>> q;
  q.push(std::make_pair(root, 0));
  while (!q.empty()) {
    TreeNode* node = q.front().first;
    int level = q.front().second;
    q.pop();

    if (level == (int)res.size()) {
      res.push_back(std::vector<int>());
    }

    res[level].push_back(node->val);

    if (node->left != nullptr) {
      q.push(std::make_pair(node->left, level + 1));
    }

    if (node->right != nullptr) {
      q.push(std::make_pair(node->right, level + 1));
    }
  }

  return res;
}
