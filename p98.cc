#include "tree_node.h"
#include <vector>

/**
 * 思路:
 * 中序遍历, 看是否出现逆序.
 */
class Solution {

public:
  bool isValidBST(TreeNode *root) {
    inOrder(root);
    if (values.size() <= 1)
      return true;

    for (int i = 0; i < values.size() - 1; ++i) {
      if (values[i] >= values[i + 1])
        return false;
    }

    return true;
  }

private:
  void inOrder(TreeNode *root) {
    if (root == nullptr)
      return;

    inOrder(root->left);
    values.push_back(root->val);
    inOrder(root->right);
  }

private:
  std::vector<int> values;
};
