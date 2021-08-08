#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::string;
using std::vector;

/*
 * 问题: 是否能够重新排列字符串, 使得相邻的字符都不同.
 *
 * 思路: 记录每个字符的数量, 每次从数量最多的字符开始消耗.
 */
class Solution {
  public:
    string reorganizeString(string s) {

        map<char, int> counter;

        // 记录每个字符的出现次数
        for (auto ch_itr = s.cbegin(); ch_itr != s.cend(); ch_itr++) {
            if (counter.find(*ch_itr) != counter.end())
                counter[*ch_itr] += 1;
            else
                counter[*ch_itr] = 1;
        }

        // 转换成(ch, num)的vector
        vector<pair<char, int>> pairs;
        for (auto item = counter.cbegin(); item != counter.cend(); item++)
            pairs.push_back(std::make_pair(item->first, item->second));

        std::sort(pairs.begin(), pairs.end(), __pair_greater);

        string res;
        while (!pairs.empty() && __to_be_continued(pairs)) {
            vector<pair<char, int>> pairs_tmp = __split_vector(pairs);
            res += __reorganize(pairs_tmp);
            pairs_tmp.clear();

            for (auto itr = pairs.cbegin(); itr != pairs.cend(); itr++) {
                if (itr->second != 0)
                    pairs_tmp.push_back(*itr);
            }

            pairs = pairs_tmp;
            std::sort(pairs.begin(), pairs.end(), __pair_greater);
        }

        if (pairs.size() > 0)
            return "";

        return res;
    }

  private:
    static bool __pair_greater(const pair<char, int> &a,
                               const pair<char, int> &b) {
        return a.second > b.second;
    }

    // 对pairs中包含的元素进行重组
    string __reorganize(vector<pair<char, int>> &pairs) {
        string res;
        int count = pairs.size() == 1 ? 0 : pairs[1].second;
        int index = 1;

        for (int i = 0; i < pairs[0].second - 1; ++i) {
            res += pairs[0].first;
            res += pairs[index].first;
            count--;

            if (count == 0 && index + 1 < pairs.size()) {
                index += 1;
                count = pairs[index].second;
            }
        }

        res += pairs[0].first;
        return res;
    }

    // 判断是否能够继续重组
    bool __to_be_continued(vector<pair<char, int>> &pairs) {
        if (pairs.size() == 0)
            return false;

        int total_from_second = 0;
        for (auto itr = pairs.cbegin() + 1; itr != pairs.cend(); itr++)
            total_from_second += itr->second;

        return pairs[0].second - total_from_second <= 1;
    }

    // 分割pairs
    vector<pair<char, int>> __split_vector(vector<pair<char, int>> &pairs) {
        vector<pair<char, int>> res;
        res.push_back(pairs[0]);

        int first_count = pairs[0].second;
        int total_from_second = 0;
        pairs[0].second = 0;

        for (auto itr = pairs.begin() + 1;
             itr != pairs.end() && first_count - total_from_second > 1; itr++) {
            if (total_from_second + itr->second < first_count) {
                total_from_second += itr->second;
                res.push_back(*itr);
                itr->second = 0;
            } else {
                int decrease_num = first_count - total_from_second - 1;
                itr->second -= decrease_num;
                res.push_back(std::make_pair(itr->first, decrease_num));
                break;
            }
        }

        return res;
    }
};

int main() {

    Solution sol;
    string s = "aaaaabbc";

    cout << sol.reorganizeString(s) << endl;

    return 0;
}
