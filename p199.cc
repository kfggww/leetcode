#include "tree_node.h"
#include <list>
#include <vector>
using std::list;
using std::vector;

/**
 * @brief 二叉树的右视图.
 *
 * 思路:
 * 使用层次遍历, 获取每层最后一个元素即为所求.
 */
class Solution {
  public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        list<TreeNode *> queue;
        int levelCount = 0;
        if (root) {
            queue.push_back(root);
            levelCount += 1;
        }

        while (!queue.empty()) {
            int nextLevelCount = 0;
            // 遍历当前层
            for (int i = 0; i < levelCount; ++i) {
                TreeNode *cur = queue.front();
                queue.pop_front();
                // 记录当前层最后一个节点
                if (i == levelCount - 1)
                    res.push_back(cur->val);

                // 添加下一层元素
                if (cur->left) {
                    queue.push_back(cur->left);
                    nextLevelCount += 1;
                }
                if (cur->right) {
                    queue.push_back(cur->right);
                    nextLevelCount += 1;
                }
            }
            levelCount = nextLevelCount;
        }

        return res;
    }
};