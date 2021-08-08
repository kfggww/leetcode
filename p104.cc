#include "tree_node.h"

/**
 * @brief 二叉树的深度
 *
 */
class Solution {
  public:
    int maxDepth(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        // ?: 优先级有坑
        return 1 + (leftDepth >= rightDepth ? leftDepth : rightDepth);
    }
};