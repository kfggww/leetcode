#include "tree_node.h"
#include <iostream>
#include <list>
#include <map>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::list;
using std::map;
using std::pair;
using std::vector;

/**
 * @brief 二叉树垂直遍历, 使用bfs的方式, 记录队列中的节点所在的列
 *
 */
class Solution {
  public:
    vector<vector<int>> verticalOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;

        minIndex = maxIndex = 0;

        bfs(root);

        for (int i = minIndex; i <= maxIndex; ++i)
            res.push_back(std::move(recorder[i]));

        return res;
    }

  private:
    void bfs(TreeNode *root) {
        if (root == nullptr)
            return;

        list<pair<TreeNode *, int>> queue;
        queue.push_back(std::make_pair(root, 0));

        while (!queue.empty()) {
            int size = queue.size();

            for (int i = 0; i < size; ++i) {

                auto item = queue.front();
                queue.pop_front();

                TreeNode *node = item.first;
                int index = item.second;
                minIndex = index < minIndex ? index : minIndex;
                maxIndex = index > maxIndex ? index : maxIndex;

                recorder[index].push_back(node->val);

                if (node->left != nullptr)
                    queue.push_back(std::make_pair(node->left, index - 1));

                if (node->right != nullptr)
                    queue.push_back(std::make_pair(node->right, index + 1));
            }
        }
    }

  private:
    map<int, vector<int>> recorder;
    int minIndex;
    int maxIndex;
};

int main(int argc, char **argv) {
    Solution s;
    TreeNode n1(1);
    TreeNode n7(7);
    TreeNode n4(4);
    TreeNode n2(2);

    TreeNode n0(0, nullptr, &n2);
    TreeNode n8(8, &n1, &n7);
    TreeNode n9(9, &n4, &n0);
    TreeNode n3(3, &n9, &n8);

    auto res = s.verticalOrder(&n3);
    for (auto items : res) {
        for (auto item : items)
            cout << item << " ";
        cout << endl;
    }

    return 0;
}