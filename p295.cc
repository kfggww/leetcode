#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using std::cout;
using std::endl;
using std::map;
using std::vector;

/*
 * 问题: 计算中位数.
 * 思路: 使用一个map记录每个数字出现的个数.
 * TODO: 超时, 问题出在每次计算中位数都要排序.
 */
class MedianFinder0 {
public:
  /** initialize your data structure here. */
  MedianFinder0() : _total(0) {}

  void addNum(int num) {
    if (_recorder.find(num) != _recorder.end())
      _recorder[num] += 1;
    else {
      _recorder[num] = 1;
      _keys.push_back(num);
    }

    _total += 1;
  }

  double findMedian() {
    std::sort(_keys.begin(), _keys.end());

    if (_total % 2 == 0) {
      double val1 = getNthValue(_total / 2);
      double val2 = getNthValue(_total / 2 + 1);
      return 0.5 * (val1 + val2);
    } else
      return getNthValue((_total + 1) / 2);
  }

private:
  int getNthValue(const int &N) {
    int cur_total = 0;
    int index = 0;
    while (cur_total < N) {
      cur_total += _recorder[_keys[index++]];
    }
    return _keys[index - 1];
  }

private:
  map<int, int> _recorder;
  vector<int> _keys;
  int _total;
};

/*
 * 改进解法:
 *
 * 维护两个堆, 分别保存前一半和后一半的元素, 计算中位数时使用两个堆顶元素即可.
 */
class MedianFinder {
public:
  MedianFinder() {}

  void addNum(int num) {
    // 确定新的num放到哪个堆中, 必须要保证两个堆顶是有序的, 否则求解的结果不对.
    if (_lo.size() == 0 || num <= _lo.top())
      _lo.push(num);
    else
      _hi.push(num);

    // ATTENTION: 必须做类型转换, 因为size_t是无符号类型的, 直接使用会溢出.
    if ((int)_lo.size() - (int)_hi.size() > 1) {
      _hi.push(_lo.top());
      _lo.pop();
    } else if ((int)_hi.size() - (int)_lo.size() > 1) {
      _lo.push(_hi.top());
      _hi.pop();
    }
  }

  double findMedian() {
    if (_lo.size() > _hi.size())
      return _lo.top();
    else if (_lo.size() < _hi.size())
      return _hi.top();
    else
      return 0.5 * (_lo.top() + _hi.top());
  }

private:
  std::priority_queue<int, vector<int>, std::less<int>> _lo; // 较小的一半
  std::priority_queue<int, vector<int>, std::greater<int>> _hi; // 较大的一半
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
  MedianFinder obj;
  obj.addNum(1);
  obj.addNum(2);
  cout << obj.findMedian() << endl;
  obj.addNum(3);
  cout << obj.findMedian() << endl;
}
