#include "tree_node.h"
#include <list>
using std::list;

/**
 * @brief 普通解法, 按照中序遍历得到一个BST的序列, 进而迭代.
 *
 */
class BSTIterator0 {
public:
  BSTIterator0(TreeNode *root) { midOrder(root); }

  int next() {
    int res = queue_.front();
    queue_.pop_front();
    return res;
  }

  bool hasNext() { return !queue_.empty(); }

private:
  void midOrder(TreeNode *root) {
    if (root == nullptr)
      return;
    midOrder(root->left);
    queue_.push_back(root->val);
    midOrder(root->right);
  }

private:
  list<int> queue_;
};

class BSTIterator1 {
public:
  BSTIterator1(TreeNode *root) {
    if (root)
      stack_.push_back(root);
    // 找到当前的最小值, 并记录访问路径.
    while (root->left != nullptr) {
      root = root->left;
      stack_.push_back(root);
    }
  }

  int next() {
    TreeNode *top = stack_.back();
    stack_.pop_back();
    TreeNode *right = top->right;
    if (right != nullptr) {
      stack_.push_back(right);
      TreeNode *left = right->left;
      while (left != nullptr) {
        stack_.push_back(left);
        left = left->left;
      }
    }
    return top->val;
  }

  bool hasNext() { return !stack_.empty(); }

private:
  list<TreeNode *> stack_;
};