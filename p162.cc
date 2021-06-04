#include <vector>
using std::vector;

/**
 * 问题: 寻找峰值.
 * */
class Solution {
public:
  int findPeakElement(vector<int> &nums) {

    if (nums.size() == 1 || nums[0] > nums[1])
      return 0;

    if (nums[nums.size() - 1] > nums[nums.size() - 2])
      return nums.size() - 1;

    for (int i = 1; i < nums.size() - 1; ++i) {
      if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
        return i;
    }

    return 0;
  }
};

/**
 * 思路: 题目保证任意相邻两个元素不想等, 因此, nums中上升和下降序列交替出现, 或
 * 者只有上升(下降序列). 采用二分法:
 *
 * 1. mid位于下降序列, 则左侧必存在一个峰值;
 *
 * 2. mid位于上升序列, 则右侧必存在一个峰值;
 *
 * 3. mid位于谷底, 左右都存在峰值, 此时取一个默认的方向进行之后的搜索即可;
 *
 */
class Solution1 {
public:
  int findPeakElement(vector<int> &nums) {
    int left = 0;
    int right = nums.size() - 1;
    int mid;

    // 二分法注意避免死循环
    while (left + 1 < right) {
      mid = (left + right) / 2;

      // 这里判断序列是上升还是下降, 只需要和mid+1处的元素比较即可, mid+1必定小
      // 于等于right
      if (nums[mid] > nums[mid + 1])
        right = mid;
      else
        left = mid;
    }

    return nums[left] > nums[right] ? left : right;
  }
};
