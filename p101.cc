#include <queue>
#include <vector>
using std::queue;
using std::vector;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

/**
 * @brief 判断二叉树是否对称.
 *
 * 思路:
 * 使用层次遍历, 检查是否每层的节点是对称的.
 */
class Solution {
public:
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr)
      return true;
    queue<TreeNode *> qu;
    qu.push(root);
    int levelCount = 1;
    vector<int> vec;
    while (!qu.empty()) {
      int nextLevelCount = 0;

      for (int i = 0; i < levelCount; ++i) {
        TreeNode *node = qu.front();
        qu.pop();
        if (node->left != nullptr) {
          qu.push(node->left);
          nextLevelCount++;
          vec.push_back(node->left->val);
        } else {
          vec.push_back(-1024);
        }
        if (node->right != nullptr) {
          qu.push(node->right);
          nextLevelCount++;
          vec.push_back(node->right->val);
        } else {
          vec.push_back(-1024);
        }
      }

      if (!checkVec(vec) || nextLevelCount % 2 == 1)
        return false;
      vec.clear();
      levelCount = nextLevelCount;
    }
    return true;
  }

  bool checkVec(vector<int> &vec) {
    int n = vec.size();
    for (int i = 0; i < n / 2; i++) {
      if (vec[i] != vec[n - i - 1])
        return false;
    }
    return true;
  }
};
/**
 * 总结:
 * 栈不能检查是否对称, 括号匹配可以用栈检查, 但对称和括号匹配是不同的.
 * TODO:
 * 此解法空间复杂度过大, 考虑递归求解.
 */