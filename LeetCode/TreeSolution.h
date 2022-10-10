/*
 * TreeSolution.h
 *
 *  Author: Erwin
 */

#ifndef TREE_SOLUTION_H_
#define TREE_SOLUTION_H_

#include <string>
#include <vector>

#include "TreeNode/TreeNode.h"

class TreeSolution {
 public:
  // 144.
  std::vector<int> preorderTraversal(TreeNode* root);

  // 94.
  std::vector<int> inorderTraversal(TreeNode* root);

  // 145.
  std::vector<int> postorderTraversal(TreeNode* root);

  // 102.
  std::vector<std::vector<int>> levelOrder(TreeNode* root);

  // 104.
  int maxDepth(TreeNode* root);

  // 226.
  TreeNode* invertTree(TreeNode* root);

  // 112.
  bool hasPathSum(TreeNode* root, int targetSum);

  // 257.
  std::vector<std::string> binaryTreePaths(TreeNode* root);

  // 437, TBD: LeetCode can not pass.
  int pathSum(TreeNode* root, int targetSum);

 private:
  int findPath(TreeNode* node, int num) {
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
};

#endif  // TREE_SOLUTION_H_
