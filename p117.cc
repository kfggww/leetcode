// 思路:
// 利用已经构造好的next信息, 计算下一层的next, 注意size()的返回值类型
//
#include "tree_node.h"
#include <vector>
using std::vector;

class Solution {
  public:
    Node *connect(Node *root) {
        if (root == nullptr)
            return root;

        root->next = nullptr;
        Node *start = root;

        while (start != nullptr) {
            Node *oldStart = start;

            while (start != nullptr) {
                Node *next = getNext(start->next);
                connect(start, next);
                start = next;
            }

            start = newStart(oldStart);
        }

        return root;
    }

  private:
    void connect(Node *first, Node *second) {
        vector<Node *> nodes;
        if (first != nullptr) {
            if (first->left != nullptr)
                nodes.push_back(first->left);
            if (first->right != nullptr)
                nodes.push_back(first->right);
        }

        if (second != nullptr) {
            if (second->left != nullptr)
                nodes.push_back(second->left);
            if (second->right != nullptr)
                nodes.push_back(second->right);
        }

        // NOTE: size()返回unsigned
        for (int i = 0; i < (int)nodes.size() - 1; ++i)
            nodes[i]->next = nodes[i + 1];
    }

    Node *newStart(Node *oldStart) {
        while (oldStart != nullptr && oldStart->left == nullptr &&
               oldStart->right == nullptr)
            oldStart = oldStart->next;

        if (oldStart != nullptr &&
            (oldStart->left != nullptr || oldStart->right != nullptr)) {
            return oldStart->left != nullptr ? oldStart->left : oldStart->right;
        } else
            return nullptr;
    }

    Node *getNext(Node *root) {
        while (root != nullptr && root->left == nullptr &&
               root->right == nullptr)
            root = root->next;
        return root;
    }
};