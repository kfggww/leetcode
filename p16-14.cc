#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// 表示一条直线
struct Line {
  int index0;
  int index1;
  int count;
};

/*
 * 计算点集中经过最多点的直线.
 */
class Solution {
public:
  vector<int> bestLine(vector<vector<int>> &points) {
    ans = {0, 1, 2};

    // 初始化marked
    for (int i = 0; i < points.size(); ++i)
      marked.push_back(0);

    this->points = points;

    for (int index_before = 0; index_before < this->points.size();
         ++index_before) {
      struct Line tmp_line = {index_before, index_before, 1};

      this->marked[index_before] = 1;
      line_of(index_before, tmp_line, 1, 1);

      clear_marked();
    }

    return {ans.index0, ans.index1};
  }

private:
  // 计算以pt_index为起点通过点最多的直线.
  void line_of(int before_index, struct Line &line, int dx, int dy) {

    struct Line old_line = line;
    int old_dx = dx, old_dy = dy;

    for (int after_index = 0; after_index < this->points.size();
         ++after_index) {
      if (before_index != after_index && marked[after_index] != 1) {

        if (add_point_to(points[before_index], before_index,
                         points[after_index], after_index, dx, dy, line)) {
          marked[after_index] = 1;
          line_of(after_index, line, dx, dy);
        }
        // 还原
        line = old_line;
        dx = old_dx;
        dy = old_dy;
      }
    }

    this->marked[before_index] = 0;
  }
  // 加入一个点到当前直线
  bool add_point_to(vector<int> &point_before, int i, vector<int> &point_after,
                    int j, int &dx, int &dy, struct Line &line) {

    if (line.count == 1) {
      line.index0 = i < j ? i : j;
      line.index1 = i < j ? j : i;
      line.count = 2;
      dx = point_after[0] - point_before[0];
      dy = point_after[1] - point_before[1];
      update_ans(line);
      return true;
    }

    long dx_cur = point_after[0] - point_before[0];
    long dy_cur = point_after[1] - point_before[1];

    if (dx_cur * dy == dy_cur * dx) {
      line.count++;
      if (line.index0 > j) {
        line.index1 = line.index0;
        line.index0 = j;
      } else if (line.index1 > j)
        line.index1 = j;

      update_ans(line);
      return true;
    }

    return false;
  }

  void update_ans(struct Line &tmp_line) {

    if (tmp_line.count > ans.count) {
      ans.index0 = tmp_line.index0;
      ans.index1 = tmp_line.index1;
      ans.count = tmp_line.count;
    } else if (tmp_line.count == ans.count) {
      if (tmp_line.index0 < ans.index0 ||
          tmp_line.index0 == ans.index0 && tmp_line.index1 < ans.index1) {
        ans.index0 = tmp_line.index0;
        ans.index1 = tmp_line.index1;
      }
    }
  }

  void clear_marked() {
    for (int i = 0; i < this->marked.size(); ++i)
      this->marked[i] = 0;
  }

private:
  vector<vector<int>> points;
  vector<char> marked;
  struct Line ans;
};

int main() {
  vector<vector<int>> points = {{1, 1}, {1, 0}, {2, 0}, {0, 0}};
  vector<int> ans;
  Solution s;
  ans = s.bestLine(points);

  cout << ans[0] << ", " << ans[1] << endl;
  return 0;
}
