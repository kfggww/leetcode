#include "tree_node.h"

/**
 * @brief 根到叶子节点的数字之和.
 *
 */
class Solution {
  public:
    int sumNumbers(TreeNode *root) {
        int last = 0;
        int sum = 0;
        if (root != nullptr)
            dfs(root, last, sum);
        return sum;
    }

    void dfs(TreeNode *root, int &last, int &sum) {
        // 如果是叶子节点, 更新sum的值
        if (root->left == nullptr && root->right == nullptr) {
            int value = last * 10 + root->val;
            sum += value;
            return;
        }

        //当前不是叶子节点
        last = last * 10 + root->val;

        if (root->left != nullptr) {
            dfs(root->left, last, sum);
        }

        if (root->right != nullptr) {
            dfs(root->right, last, sum);
        }

        last /= 10;
    }
};