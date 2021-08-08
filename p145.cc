#include <list>
#include <utility>
#include <vector>
using std::list;
using std::pair;
using std::vector;
#include "tree_node.h"

class Solution {
    enum Action { Visit, Fetch };

  public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        list<pair<TreeNode *, Action>> stack;
        if (root)
            stack.push_back(pair<TreeNode *, Action>(root, Action::Visit));
        while (!stack.empty()) {
            auto cur = stack.back();
            stack.pop_back();
            if (cur.second == Action::Fetch) {
                res.push_back(cur.first->val);
            } else {
                TreeNode *root = cur.first;
                stack.push_back(pair<TreeNode *, Action>(root, Action::Fetch));
                if (root->right)
                    stack.push_back(
                        pair<TreeNode *, Action>(root->right, Action::Visit));
                if (root->left)
                    stack.push_back(
                        pair<TreeNode *, Action>(root->left, Action::Visit));
            }
        }
        return res;
    }
};