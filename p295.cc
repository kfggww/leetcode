#include <algorithm>
#include <iostream>
#include <map>
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
class MedianFinder {
public:
  /** initialize your data structure here. */
  MedianFinder() : _total(0) {}

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

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
  MedianFinder obj;
  obj.addNum(3);
  obj.addNum(2);
  cout << obj.findMedian() << endl;
  obj.addNum(3);
  cout << obj.findMedian() << endl;
}
