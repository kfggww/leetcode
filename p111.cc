#include "tree_node.h"

/**
 * @brief 二叉树的最小深度.
 *
 */
class Solution {
  public:
    int minDepth(TreeNode *root) {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return 1;

        int leftHeight = minDepth(root->left);
        int rightHeight = minDepth(root->right);

        int height = 0;
        if (leftHeight == 0)
            height = rightHeight;
        else if (rightHeight == 0)
            height = leftHeight;
        else
            height = leftHeight < rightHeight ? leftHeight : rightHeight;
        return 1 + height;
    }
};