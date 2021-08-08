#include <vector>
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

class Solution {
  public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        vector<int> path;
        vector<vector<int>> paths;
        preOrder(root, targetSum, path, paths);
        return paths;
    }

  private:
    void preOrder(TreeNode *root, int targetSum, vector<int> &path,
                  vector<vector<int>> &paths) {
        // 当前是nil
        if (root == nullptr)
            return;

        // 当前是叶子, 但不满足条件
        if (root->left == nullptr && root->right == nullptr &&
            root->val != targetSum) {
            return;
        }

        // 当前是叶子, 且满足条件
        if (root->left == nullptr && root->right == nullptr &&
            root->val == targetSum) {
            path.push_back(root->val);
            vector<int> copyOf(path);
            paths.push_back(copyOf);
            path.pop_back();
            return;
        }

        // 当前是内部节点
        targetSum -= root->val;
        path.push_back(root->val);
        preOrder(root->left, targetSum, path, paths);
        preOrder(root->right, targetSum, path, paths);
        path.pop_back();
    }
};