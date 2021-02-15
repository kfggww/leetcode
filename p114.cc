#include "tree_node.h"

/**
 * @brief 二叉树展开成链表, 按照先序
 *
 */
class Solution {
public:
  void flatten(TreeNode *root) { root = preOrder(root); }

private:
  // 计算展开结果
  TreeNode *preOrder(TreeNode *root) {
    if (root == nullptr || root->left == nullptr && root->right == nullptr)
      return root;

    TreeNode *left = preOrder(root->left);
    TreeNode *right = preOrder(root->right);

    if (left) {
      root->right = left;
      while (left->right) {
        left = left->right;
      }
      left->right = right;
    } else {
      root->right = right;
    }

    root->left = nullptr;

    return root;
  }
};