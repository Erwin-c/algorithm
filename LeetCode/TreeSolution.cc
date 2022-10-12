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

int TreeSolution::maxDepth(TreeNode* root) {
  if (root == nullptr) {
    return 0;
  }

  return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

TreeNode* TreeSolution::invertTree(TreeNode* root) {
  if (root == nullptr) {
    return nullptr;
  }

  invertTree(root->left);
  invertTree(root->right);
  std::swap(root->left, root->right);

  return root;
}

bool TreeSolution::hasPathSum(TreeNode* root, int targetSum) {
  if (root == nullptr) {
    return false;
  }

  if (root->left == nullptr && root->right == nullptr) {
    return root->val == targetSum;
  }

  return hasPathSum(root->left, targetSum - root->val) ||
         hasPathSum(root->right, targetSum - root->val);
}

std::vector<std::string> TreeSolution::binaryTreePaths(TreeNode* root) {
  std::vector<std::string> res;

  if (root == nullptr) {
    return res;
  }

  if (root->left == nullptr && root->right == nullptr) {
    res.push_back(std::to_string(root->val));
  }

  std::vector<std::string> leftS = binaryTreePaths(root->left);
  for (size_t i = 0; i < leftS.size(); ++i) {
    res.push_back(std::to_string(root->val) + "->" + leftS[i]);
  }

  std::vector<std::string> rightS = binaryTreePaths(root->right);
  for (size_t i = 0; i < rightS.size(); ++i) {
    res.push_back(std::to_string(root->val) + "->" + rightS[i]);
  }

  return res;
}

int TreeSolution::pathSum(TreeNode* root, int targetSum) {
  if (root == nullptr) {
    return 0;
  }

  int res = findPath(root, targetSum);
  res += pathSum(root->left, targetSum);
  res += pathSum(root->right, targetSum);

  return res;
}

TreeNode* TreeSolution::lowestCommonAncestor(TreeNode* root, TreeNode* p,
                                             TreeNode* q) {
  assert(p != nullptr && q != nullptr);

  if (root == nullptr) {
    return nullptr;
  }

  if (p->val < root->val && q->val < root->val) {
    return lowestCommonAncestor(root->left, p, q);
  }

  if (p->val > root->val && q->val > root->val) {
    return lowestCommonAncestor(root->right, p, q);
  }

  return root;
}

int TreeSolution::findPath(TreeNode* node, int num) {
  if (node == nullptr) {
    return 0;
  }

  int res = 0;
  if (node->val == num) {
    ++res;
  }

  res += findPath(node->left, num - node->val);
  res += findPath(node->right, num - node->val);

  return res;
}
