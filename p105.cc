#include "tree_node.h"
#include <vector>
using std::vector;

class Solution {
    using Iter = vector<int>::iterator;

  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0 || preorder.size() != inorder.size()) {
            return nullptr;
        }

        int n = preorder.size();
        int *preOrder = preorder.data();
        int *inOrder = inorder.data();
        return build(preOrder, 0, n, inOrder, 0, n);
    }

    TreeNode *build(int *preOrder, int s1, int e1, int *inOrder, int s2,
                    int e2) {
        if (s1 >= e1)
            return nullptr;
        TreeNode *root = new TreeNode(preOrder[s1]);
        int rootPos = indexOf(inOrder, s2, e2, preOrder[s1]);
        // 构造左子树
        root->left = build(preOrder, s1 + 1, s1 + 1 + rootPos - s2, inOrder, s2,
                           rootPos);
        // 构造右子树
        root->right = build(preOrder, e1 - e2 + rootPos + 1, e1, inOrder,
                            rootPos + 1, e2);
        return root;
    }

    /**
     * @brief 查找val的位置， nums[s, e)
     *
     * @param nums
     * @param s
     * @param e
     * @param val
     * @return int
     */
    int indexOf(int *nums, int s, int e, int val) {
        int index = -1;
        for (int i = s; i < e; ++i) {
            if (nums[i] == val) {
                index = i;
                break;
            }
        }
        return index;
    }
};