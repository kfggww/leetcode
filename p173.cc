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
    // 找到当前的最小值, 并记录访问路径.
    while (root != nullptr) {
      stack_.push_back(root);
      root = root->left;
    }
  }

  int next() {
    TreeNode *top = stack_.back();
    stack_.pop_back();
    TreeNode *root = top->right;
    while (root != nullptr) {
      stack_.push_back(root);
      root = root->left;
    }
    return top->val;
  }

  bool hasNext() { return !stack_.empty(); }

private:
  list<TreeNode *> stack_;
};