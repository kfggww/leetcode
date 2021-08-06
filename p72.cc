#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

/**
 * @brief 计算两个字符串的编辑距离
 *
 * 思路: 使用动态规划, 注意边界条件, 只有一个字符的情况.
 *
 */
class Solution {
public:
  int minDistance(string word1, string word2) {
    int n1 = word1.size();
    int n2 = word2.size();

    // 单独考虑空串的情况
    if (n1 == 0 || n2 == 0)
      return n1 + n2;

    // 分配内存空间
    int **dp = new int *[n1];
    for (int i = 0; i < n1; ++i)
      dp[i] = new int[n2];

    // 根据状态转移方程填表
    if (word1.at(0) == word2.at(0))
      dp[0][0] = 0;
    else
      dp[0][0] = 1;

    for (int i = 1; i < n2; ++i) {
      dp[0][i] = dp[0][i - 1] + 1;
      if (word1.at(0) == word2.at(i) && dp[0][i] > i)
        dp[0][i] = i;
    }

    for (int i = 1; i < n1; ++i) {
      dp[i][0] = dp[i - 1][0] + 1;
      if (word1.at(i) == word2.at(0) && dp[i][0] > i)
        dp[i][0] = i;
    }

    for (int i = 1; i < n1; ++i)
      for (int j = 1; j < n2; ++j) {
        if (word1.at(i) == word2.at(j))
          dp[i][j] = dp[i - 1][j - 1];
        else {
          dp[i][j] = dp[i - 1][j - 1] + 1;
          if (dp[i][j] > dp[i][j - 1] + 1)
            dp[i][j] = dp[i][j - 1] + 1;
          if (dp[i][j] > dp[i - 1][j] + 1)
            dp[i][j] = dp[i - 1][j] + 1;
        }
      }

    // 释放内存空间
    int dist = dp[n1 - 1][n2 - 1];
    for (int i = 0; i < n1; ++i)
      delete[] dp[i];
    delete[] dp;

    return dist;
  }
};

int main(int argc, char **argv) {
  if (argc != 3)
    return -1;
  Solution s;
  string word1{argv[1]};
  string word2{argv[2]};
  cout << s.minDistance(word1, word2) << endl;
  return 0;
}