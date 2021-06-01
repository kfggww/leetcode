#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using std::cout;
using std::endl;
using std::priority_queue;
using std::vector;

/*
 * 问题: 动态计算第K大的元素.
 */
class KthLargest {
public:
  KthLargest(int k, vector<int> &nums) : _k(k) {

    for (auto itr = nums.cbegin(); itr != nums.cend(); itr++) {
      if (_pq.size() < k)
        _pq.push(*itr);
      else if (*itr > _pq.top()) {
        _pq.push(*itr);
        _pq.pop();
      }
    }
  }

  int add(int val) {

    if (_pq.size() < _k)
      _pq.push(val);
    else if (val > _pq.top()) {
      _pq.push(val);
      _pq.pop();
    }

    return _pq.top();
  }

private:
  // greater: 小顶堆
  // less: 大顶堆
  priority_queue<int, vector<int>, std::greater<int>> _pq;
  int _k;
};

int main() {
  vector<int> vecs = {4, 5, 8, 2};
  KthLargest sol(3, vecs);
  int nums[] = {3, 5, 10, 9, 4};

  for (int i = 0; i < 5; ++i)
    cout << sol.add(nums[i]) << endl;

  return 0;
}
