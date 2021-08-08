
/**
 * @brief 树节点定义.
 *
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
  public:
    /**
     * @brief 通过Preorder遍历比较树的节点.
     *
     * @param p
     * @param q
     * @return true
     * @return false
     */
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == q) {
            return true;
        } else if (p == nullptr && q != nullptr ||
                   p != nullptr && q == nullptr || p->val != q->val) {
            return false;
        } else {
            return isSameTree(p->left, q->left) &&
                   isSameTree(p->right, q->right);
        }
    }
};