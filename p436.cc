#include <vector>
using std::vector;

/*
 * 问题: 计算右侧区间.
 *
 * 暴力求解(TimeOut).
 */
class Solution {
public:
  vector<int> findRightInterval(vector<vector<int>> &intervals) {
    vector<int> res;

    for (int i = 0; i < intervals.size(); ++i) {
      int index = -1;
      for (int j = 0; j < intervals.size(); ++j) {
        if (j != i && intervals[i][1] <= intervals[j][0]) {
          index =
              index == -1 || intervals[j][0] < intervals[index][0] ? j : index;
        }
      }

      res.push_back(index);
    }

    return res;
  }
};
