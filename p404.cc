#include "tree_node.h"

class Solution {
  public:
    int sumOfLeftLeaves(TreeNode *root) {
        // 当前是nil或者是叶子， 返回0
        if (root == nullptr ||
            (root->left == nullptr && root->right == nullptr)) {
            return 0;
        }

        if (hasLeftLeaf(root)) {
            return root->left->val + sumOfLeftLeaves(root->right);
        } else {
            return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        }
    }

    /**
     * @brief 判断当前节点是否有左孩子.
     *
     * @param root
     * @return true
     * @return false
     */
    bool hasLeftLeaf(TreeNode *root) {
        if (root != nullptr && root->left != nullptr &&
            root->left->left == nullptr && root->left->right == nullptr) {
            return true;
        }
        return false;
    }
};