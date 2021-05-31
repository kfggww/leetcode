#include <functional>
#include <queue>
#include <vector>
using std::priority_queue;
using std::vector;

/*
 * 问题: 寻找第k大的元素.
 *
 * 思路: 用一个小顶堆, 维护k个元素, 最后堆顶元素即为所求.
 */
class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, std::greater<int>> heap;

    for (auto itr = nums.cbegin(); itr != nums.cend(); itr++) {
      if (heap.size() < k) {
        heap.push(*itr);
      } else {
        heap.push(*itr);
        heap.pop();
      }
    }

    return heap.top();
  }
};
