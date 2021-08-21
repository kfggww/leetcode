/**
 * @file p75.cc
 * @author kfggww (kfggww@outlook.com)
 * @brief 一次扫描排序, 只有0, 1, 2三种元素
 * @version 0.1
 * @date 2021-08-09
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <vector>
using std::vector;

class Solution {
  public:
    void sortColors(vector<int> &nums) {
        int counter[] = {0, 0, 0};
        for (auto num : nums) {
            counter[num] += 1;
        }

        // 找到第一个不为0的开始填充
        int index = 0;
        for (; index < 3; ++index) {
            if (counter[index] != 0)
                break;
        }

        // 再次遍历然后填充
        for (int i = 0; index < 3 && i < nums.size(); ++i) {
            while (counter[index] == 0) {
                index += 1;
            }
            if (index < 3) {
                nums[i] = index;
                counter[index] -= 1;
            }
        }
    }
};