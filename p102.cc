#include "tree_node.h"
#include <list>
#include <vector>
using std::list;
using std::vector;

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    list<TreeNode *> queue;
    if (!root) {
      return ans;
    }

    queue.push_back(root);

    while (!queue.empty()) {
      ans.push_back(vector<int>());
      int size = queue.size();
      for (int i = 0; i < size; ++i) {
        TreeNode *node = queue.front();
        queue.pop_front();
        ans.back().push_back(node->val);
        if (node->left) {
          queue.push_back(node->left);
        }
        if (node->right) {
          queue.push_back(node->right);
        }
      }
    }

    return ans;
  }
};