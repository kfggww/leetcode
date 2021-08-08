#include <queue>
#include <vector>
using std::queue;
using std::vector;

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
 * @brief 判断二叉树是否对称.
 *
 * 思路:
 * 使用层次遍历, 检查是否每层的节点是对称的.
 */
class Solution0 {
  public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr)
            return true;
        queue<TreeNode *> qu;
        qu.push(root);
        int levelCount = 1;
        vector<int> vec;
        while (!qu.empty()) {
            int nextLevelCount = 0;

            for (int i = 0; i < levelCount; ++i) {
                TreeNode *node = qu.front();
                qu.pop();
                if (node->left != nullptr) {
                    qu.push(node->left);
                    nextLevelCount++;
                    vec.push_back(node->left->val);
                } else {
                    vec.push_back(-1024);
                }
                if (node->right != nullptr) {
                    qu.push(node->right);
                    nextLevelCount++;
                    vec.push_back(node->right->val);
                } else {
                    vec.push_back(-1024);
                }
            }

            if (!checkVec(vec) || nextLevelCount % 2 == 1)
                return false;
            vec.clear();
            levelCount = nextLevelCount;
        }
        return true;
    }

    bool checkVec(vector<int> &vec) {
        int n = vec.size();
        for (int i = 0; i < n / 2; i++) {
            if (vec[i] != vec[n - i - 1])
                return false;
        }
        return true;
    }
};

/**
 * @brief 使用递归方法求解.
 *
 * 思路:
 * 对于根的左子树, 按照"根->左->右"的顺序遍历
 * 对于根的右子树, 按照"根->右->左"的顺序遍历
 * 如果树是对称的, 两种方式应该得到相同的序列.
 */
class Solution1 {
  public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr)
            return true;
        exchange(root->right);
        return isSame(root->left, root->right);
    }

    /**
     * @brief 递归交换左右子树.
     *
     * @param root
     */
    void exchange(TreeNode *root) {
        if (root == nullptr)
            return;
        exchange(root->left);
        exchange(root->right);
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
    }

    /**
     * @brief 判断两个树是否相同, 递归. 根相同 && 左子树相同 && 右子树相同
     *
     * @param root1
     * @param root2
     * @return true
     * @return false
     */
    bool isSame(TreeNode *root1, TreeNode *root2) {
        if (root1 == root2)
            return true;
        if (root1 == nullptr && root2 != nullptr ||
            root1 != nullptr && root2 == nullptr || root1->val != root2->val)
            return false;
        return isSame(root1->left, root2->left) &&
               isSame(root1->right, root2->right);
    }
};