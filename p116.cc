// 思路:
// 填充i层时, i-1层已经填充完毕, 因此可以利用i-1层的结果.

#include "tree_node.h"

class Solution {
  public:
    Node *connect(Node *root) {
        if (root == nullptr)
            return root;

        root->next = nullptr;
        Node *start = root;

        while (start != nullptr) {
            Node *nextStart = start->left;
            while (start != nullptr) {
                connect(start, start->next);
                start = start->next;
            }
            start = nextStart;
        }

        return root;
    }

  private:
    // first和second是同一层上相邻的两个节点
    void connect(Node *first, Node *second) {
        if (first != nullptr && first->left != nullptr)
            first->left->next = first->right;

        if (second != nullptr && second->left != nullptr) {
            second->left->next = second->right;
            if (first != nullptr && first->right != nullptr)
                first->right->next = second->left;
        }
    }
};