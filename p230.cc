#include "tree_node.h"
#include <list>
using std::list;

class Solution {
  public:
    int kthSmallest(TreeNode *root, int k) {
        // 初始化栈
        list<TreeNode *> stack;
        while (root) {
            stack.push_back(root);
            root = root->left;
        }

        int res = 0;
        // 执行k次出栈操作
        for (int i = 0; i < k && !stack.empty(); ++i) {
            TreeNode *top = stack.back();
            res = top->val;
            stack.pop_back();
            TreeNode *right = top->right;
            while (right) {
                stack.push_back(right);
                right = right->left;
            }
        }

        return res;
    }
};