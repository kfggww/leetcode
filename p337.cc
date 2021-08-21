// 思路:
// 递归求解, 在递归计算过程中保存子问题的解.

#include "tree_node.h"
#include <map>
#include <utility>
using std::map;
using std::pair;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

class Solution {
  public:
    int rob(TreeNode *root) {

        int score1 = 0;
        int score2 = 0;
        score1 = dfs(root, 0);
        score2 = dfs(root, 1);

        return score1 > score2 ? score1 : score2;
    }

  private:
    int dfs(TreeNode *root, int used) {
        if (root == nullptr)
            return 0;

        pair<TreeNode *, int> key = {root, used};
        if (table.find(key) != table.end())
            return table[key];

        int left0 = tryLookUp(root->left, 0);
        int left1 = tryLookUp(root->left, 1);

        int right0 = tryLookUp(root->right, 0);
        int right1 = tryLookUp(root->right, 1);

        int score = 0;
        if (used == 1)
            score = root->val + left0 + right0;
        else
            score = MAX(left0, left1) + MAX(right0, right1);

        table[key] = score;
        return score;
    }

    int tryLookUp(TreeNode *root, int used) {
        pair<TreeNode *, int> key = {root, used};
        if (table.find(key) != table.end())
            return table[key];

        return dfs(root, used);
    }

  private:
    map<pair<TreeNode *, int>, int> table;
};