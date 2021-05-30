#include "tree_node.h"
#include <list>
#include <vector>
using std::list;
using std::vector;

class Solution {
public:
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    vector<vector<int>> res;
    list<vector<int>> top_down;

    vector<int> level_vals;
    int level_size = 0;
    list<TreeNode *> queue;

    if (root != nullptr) {
      queue.push_back(root);
      level_size += 1;
    }

    while (level_size > 0) {
      // walk through current level
      for (int i = 0; i < level_size; ++i) {
        TreeNode *cur_node = queue.front();
        queue.pop_front();
        level_vals.push_back(cur_node->val);

        if (cur_node->left != nullptr)
          queue.push_back(cur_node->left);
        if (cur_node->right != nullptr)
          queue.push_back(cur_node->right);
      }

      top_down.push_front(level_vals);
      level_vals.clear();
      level_size = queue.size();
    }

    for (auto itr = top_down.cbegin(); itr != top_down.cend(); itr++)
      res.push_back(*itr);

    return res;
  }
};
