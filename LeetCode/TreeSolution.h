/*
 * TreeSolution.h
 *
 *  Author: Erwin
 */

#ifndef TREE_SOLUTION_H_
#define TREE_SOLUTION_H_

#include <vector>

#include "TreeNode/TreeNode.h"

class TreeSolution {
 public:
  // 144
  std::vector<int> preorderTraversal(TreeNode* root);

  // 94
  std::vector<int> inorderTraversal(TreeNode* root);

  // 145
  std::vector<int> postorderTraversal(TreeNode* root);

  // 102
  std::vector<std::vector<int>> levelOrder(TreeNode* root);
};

#endif  // TREE_SOLUTION_H_
