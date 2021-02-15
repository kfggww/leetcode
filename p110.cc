#include "tree_node.h"

/**
 * @brief 判断平衡二叉树
 *
 */
class Solution {
public:
  // 要求root->left平衡 && root->right平衡 && root本身平衡
  bool isBalanced(TreeNode *root) {
    if (root == nullptr) {
      return true;
    } else if (!isBalanced(root->left) || !isBalanced(root->right)) {
      return false;
    } else {
      int left = height(root->left);
      int right = height(root->right);
      return (left - right <= 1) && (left - right >= -1);
    }
  }

private:
  int height(TreeNode *root) {
    if (root == nullptr)
      return 0;
    else if (root->left == nullptr && root->right == nullptr)
      return 1;
    else {
      int left = height(root->left);
      int right = height(root->right);
      return 1 + (left > right ? left : right);
    }
  }
};