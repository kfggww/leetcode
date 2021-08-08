#include "tree_node.h"

#include <list>
using std::list;

/**
 * @brief 二叉树节点的公共祖先, 暴力求解
 *
 * TODO: a better solution
 */
class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        list<TreeNode *> pathToP;
        list<TreeNode *> pathToQ;
        list<TreeNode *> pathTmp;
        bool found = false;
        pathTo(root, p, pathTmp, pathToP, found);
        found = false;
        pathTmp.clear();
        pathTo(root, q, pathTmp, pathToQ, found);

        // 计算最近公共祖先
        TreeNode *res = root;
        for (auto pIter = pathToP.rbegin(); pIter != pathToP.rend(); ++pIter) {
            for (auto qIter = pathToQ.rbegin(); qIter != pathToQ.rend();
                 ++qIter) {
                if (*pIter == *qIter) {
                    return *pIter;
                }
            }
        }
        return res;
    }

  private:
    void pathTo(TreeNode *root, TreeNode *target, list<TreeNode *> &path,
                list<TreeNode *> &pathFound, bool &found) {
        if (root == nullptr || found)
            return;
        path.push_back(root);
        if (root == target) { // 找到了
            pathFound.assign(path.begin(), path.end());
            found = true;
            return;
        }
        pathTo(root->left, target, path, pathFound, found);
        pathTo(root->right, target, path, pathFound, found);
        path.pop_back();
    }
};

/**
 * @brief 递归求解.
 *
 */
class Solution2 {

  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        dfs(root, p, q);
        return ans;
    }

  private:
    /**
     * @brief 当root中包含p或者q时, 返回true
     *
     * @param root
     * @param p
     * @param q
     * @return true
     * @return false
     */
    bool dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr)
            return false;

        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);

        // 记录答案
        if ((lson && rson) || ((root == p || root == q) && (lson || rson)))
            ans = root;
        return (lson || rson) || (root == p || root == q);
    }

  private:
    TreeNode *ans;
};