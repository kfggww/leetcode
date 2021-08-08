
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

/**
 * @brief PreOrder遍历计算每条路径是否满足条件.
 *
 * 思路:
 * 叶子节点, 左右子树均为nil;
 * 在叶子节点处检查是否满足条件.
 */
class Solution {
  public:
    bool hasPathSum(TreeNode *root, int targetSum) {
        // 当前是nil
        if (root == nullptr)
            return false;
        // 当前是叶子
        if (root->left == nullptr && root->right == nullptr &&
            root->val == targetSum)
            return true;

        if (root->left == nullptr && root->right == nullptr &&
            root->val != targetSum)
            return false;

        // 当前不是叶子
        targetSum -= root->val;
        bool left = hasPathSum(root->left, targetSum);
        bool right = hasPathSum(root->right, targetSum);
        return left || right;
    }
};