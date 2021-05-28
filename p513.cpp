#include "tree_node.h"
#include <list>

using std::list;

/**
 * 通过层次遍历寻找最底层的第一个节点.
 *
 */
class Solution0 {
public:
  int findBottomLeftValue(TreeNode *root) {

    list<TreeNode *> queue;
    queue.push_back(root);
    int cur_level_size = 1;

    int bottom_left_val = root->val;

    while (!queue.empty()) {

      // walk through current level
      for (int i = 0; i < cur_level_size; ++i) {
        TreeNode *cur_node = queue.front();
        if (i == 0)
          bottom_left_val = cur_node->val;
        queue.pop_front();
        if (cur_node->left != nullptr)
          queue.push_back(cur_node->left);
        if (cur_node->right != nullptr)
          queue.push_back(cur_node->right);
      }

      // update cur_level_size
      cur_level_size = queue.size();
    }

    return bottom_left_val;
  }
};

/**
 * 层次遍历改进版.
 * 思路: 维护队列时先放right, 再放left, 这样层次遍历结束之后,
 *      得到的节点就是最底层的最左节点了.
 *
 */
class Solution1 {
public:
  int findBottomLeftValue(TreeNode *root) {

    // root will never be NULL
    list<TreeNode *> queue;
    queue.push_back(root);
    TreeNode *target = nullptr;

    while (!queue.empty()) {
      target = queue.front();
      queue.pop_front();
      if (target->right != nullptr)
        queue.push_back(target->right);
      if (target->left != nullptr)
        queue.push_back(target->left);
    }

    return target->val;
  }
};
