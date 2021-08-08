#include "tree_node.h"
#include <string>
using std::string;

/**
 * @brief 从先序构造二叉树
 *
 */
class Solution {
  public:
    TreeNode *recoverFromPreorder(string S) {
        return buildTree(S, 0, S.size(), 0);
    }

  private:
    bool isNum(char ch) { return ch >= '0' && ch <= '9'; }
    bool isMinus(char ch) { return ch == '-'; }

    TreeNode *buildTree(string s, int begin, int ending, int height) {
        if (ending <= begin) {
            return nullptr;
        }
        int index = begin;
        while (index < ending && isNum(s.at(index))) {
            ++index;
        }
        TreeNode *root = new TreeNode(std::stoi(s.substr(begin, index)));
        if (index >= ending)
            return root;

        // 构造左子树
        int lbegin = index + height + 1;
        int i, j;
        i = j = lbegin;
        while (j < ending && j - i != height + 1) {
            i = j;
            while (i < ending && isNum(s.at(i))) {
                ++i;
            };
            j = i;
            while (j < ending && isMinus(s.at(j))) {
                ++j;
            }
        }
        int rbegin = j;
        root->left = buildTree(s, lbegin,
                               rbegin != ending ? rbegin - height - 1 : ending,
                               height + 1);
        // 构造右子树
        root->right = buildTree(s, rbegin, ending, height + 1);
        return root;
    }
};