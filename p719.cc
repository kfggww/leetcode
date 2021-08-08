// 排序之后, 距离按照由小到大的顺序加入到堆中, 所以当堆的大小等于k时, 就可以返回
// 了, 不必计算全部的距离组合.
#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using std::priority_queue;
using std::vector;

using std::cout;
using std::endl;

/*
 * 问题: 给定一个数组, 数组中任意两个数字之间有一个距离, 计算第k小的距离.
 *
 * 思路: 枚举元素之间的距离, 加入到堆中.
 */
class Solution0 {
  public:
    int smallestDistancePair(vector<int> &nums, int k) {
        priority_queue<int> pq;

        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                int dist = nums[j] - nums[i];
                dist = dist >= 0 ? dist : -dist;
                if (pq.size() < k)
                    pq.push(dist);
                // dist大于等于堆顶的情况, 无须添加
                else if (dist < pq.top()) {
                    pq.push(dist);
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
};

/*
 * 官方题解: 二分法 + 双指针. 距离并不是直接通过元素相减计算出的, 而是猜出来的.
 * 双指针用来计数.
 */
class Solution1 {
  public:
    int smallestDistancePair(vector<int> &nums, int k) {

        sort(nums.begin(), nums.end());
        int lo = 0;
        int hi = *(nums.end() - 1) - *nums.begin();

        while (hi > lo) {
            int mid = (hi + lo) / 2;
            int count = 0;
            int left = 0;
            // 双指针统计距离小于等于mid的数量.
            // left只在for循环的开始被初始化成0,在循 环的过程中,
            // left是动态变化的, 不必再重置为0; 另一种方式是将left初始化为 right
            // - 1, 但实际验证发现这种方式超时了.
            for (int right = 1; right < nums.size(); ++right) {
                while (nums[right] - nums[left] > mid)
                    left++;
                count += (right - left);
            }

            // 注意这里的>=, 以及 mid+1
            if (count >= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};

int main(int argc, char *argv[]) {

    int k = argc == 1 ? 1 : atoi(argv[1]);

    Solution0 sol0;
    Solution1 sol1;
    vector<int> nums = {9, 10, 7, 10, 6, 1, 5, 4, 9, 8};
    int res0 = sol0.smallestDistancePair(nums, k);
    int res1 = sol1.smallestDistancePair(nums, k);
    cout << "sol0: " << res0 << endl << "sol1: " << res1 << endl;
    return 0;
}
