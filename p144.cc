#include <list>
#include <vector>
using std::list;
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
 * @brief 二叉树前序遍历, 递归.
 *
 */
class Solution0 {
public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    preOrder(root, res);
    return res;
  }

  void preOrder(TreeNode *root, vector<int> &path) {
    if (root == nullptr)
      return;
    path.push_back(root->val);
    preOrder(root->left, path);
    preOrder(root->right, path);
  }
};

/**
 * @brief 二叉树前序遍历, 迭代.
 *
 */
class Solution1 {
public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    list<TreeNode *> stack;
    if (root != nullptr)
      stack.push_back(root);
    while (!stack.empty()) {
      TreeNode *cur = stack.back();
      stack.pop_back();
      if (cur->right)
        stack.push_back(cur->right);
      if (cur->left)
        stack.push_back(cur->left);
      res.push_back(cur->val);
    }
    return res;
  }
};