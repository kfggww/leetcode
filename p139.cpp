/**
 * 题目描述: https://leetcode.cn/problems/word-break/
 */

#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    bool wordBreak(string s, vector<string> &wordDict) {
        std::for_each(
            wordDict.cbegin(), wordDict.cend(),
            [this](const string &word) { this->_words.insert(word); });

        int i = 0;
        int j = 0;
        stack<int> istack;

        while (i != -1 && i < s.size()) {
            j = eatOneWord(s, i);
            if (j != -1) {
                istack.push(i);
                i = j;
            } else {
                i = stepBack(istack, i, s);
            }
        }

        return !istack.empty();
    }

  private:
    int eatOneWord(const string &s, int start) {
        int res = -1;

        for (int end = start; end < s.size(); ++end) {
            string st = s.substr(start, end - start + 1);
            if (_words.count(st) != 0) {
                res = end + 1;
                break;
            }
        }

        return res;
    }

    int stepBack(stack<int> &istack, int i, const string &s) {
        int res = -1;
        while (!istack.empty()) {
            int start = istack.top();
            i = eatOneWordAfter(s, start, i);
            if (i != -1) {
                res = i;
                break;
            } else {
                i = start;
                istack.pop();
            }
        }
        return res;
    }

    int eatOneWordAfter(const string &s, int start, int after) {
        int res = -1;
        for (int end = after; end < s.size(); ++end) {
            string st = s.substr(start, end - start + 1);
            if (_words.count(st) != 0) {
                res = end + 1;
                break;
            }
        }
        return res;
    }

  private:
    set<string> _words;
};

/**
 *二维动态规划.
 */
class Solution2 {
  public:
    bool wordBreak(string s, vector<string> &wordDict) {
        const int N = s.size();
        vector<vector<int>> table(N);

        set<string> words;
        std::for_each(wordDict.cbegin(), wordDict.cend(),
                      [&words](const string &word) { words.insert(word); });

        initTable(s, words, table);
        fillTable(s, words, table);

        return table[0][N - 1] != 0;
    }

  private:
    void initTable(const string &s, const set<string> &words,
                   vector<vector<int>> &table) {
        const int N = s.size();

        for (int i = 0; i < N; ++i) {
            table[i].resize(N);
            if (words.count(s.substr(i, 1)) == 0) {
                table[i][i] = 0;
            } else {
                table[i][i] = 1;
            }
        }
    }

    void fillTable(const string &s, const set<string> &words,
                   vector<vector<int>> &table) {
        const int N = s.size();
        int step = 1;
        int i, j;

        for (int n = N - 1; n >= 1; --n) {
            for (i = 0; i < n; ++i) {
                j = i + step;
                fillTableItem(i, j, table, s, words);
            }
            step += 1;
        }
    }

    void fillTableItem(const int i, const int j, vector<vector<int>> &table,
                       const string &s, const set<string> &words) {

        string st = s.substr(i, j - i + 1);
        if (words.count(st) != 0) {
            table[i][j] = 1;
            return;
        }

        table[i][j] = 0;
        for (int k = i; k < j; ++k) {
            if (table[i][k] == 1 && table[k + 1][j] == 1) {
                table[i][j] = 1;
                return;
            }
        }
    }
};

/**
 *一维动态规划.
 */
class Solution3 {
  public:
    bool wordBreak(string s, vector<string> &wordDict) {
        const int N = s.size();
        vector<int> table(N + 1);

        set<string> words;
        std::for_each(wordDict.cbegin(), wordDict.cend(),
                      [&words](const string &word) { words.insert(word); });

        table[0] = 1;
        for (int i = 1; i <= N; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (table[j] == 1 && words.count(s.substr(j, i - j)) != 0) {
                    table[i] = 1;
                    break;
                }
            }
        }

        return table[N] != 0;
    }
};

int main(int argc, char **argv) {

    const string s = "leetcode";
    vector<string> dict = {"cats", "dog", "sand", "and", "cat"};

    Solution2 sl;
    cout << sl.wordBreak(s, dict) << endl;

    return 0;
}