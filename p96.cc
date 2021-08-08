#include "tree_node.h"

/**
 * @brief 二叉搜索树的个数
 *
 */
class Solution {
  public:
    int numTrees(int n) {
        if (n == 0 || n == 1)
            return 1;
        if (n == 2)
            return 2;

        int ans = 0;
        for (int i = 0; i <= (n - 1) / 2; ++i) {
            if (i < n - 1 - i) {
                ans += (numTrees(i) * numTrees(n - 1 - i) * 2);
            } else {
                int num = numTrees(i);
                ans += num * num;
            }
        }
        return ans;
    }
};