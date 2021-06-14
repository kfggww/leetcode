#include <iostream>
#include <string>
using std::string;

class Solution {
public:
  string longestPalindrome(string s) {

    string res;
    int max_len = 1;

    for (int i = 0; i < s.size(); ++i) {
      for (int j = i; j < s.size(); ++j) {
        string ss = s.substr(i, j - i + 1);
        if (is_palindrom(ss) && ss.size() > max_len) {
          max_len = ss.size();
          res = ss;
        }
      }
    }

    return res;
  }

private:
  bool is_palindrom(string s) {

    int len = s.size();

    for (int i = 0; i <= len / 2; ++i) {
      if (s[i] != s[len - i - 1])
        return false;
    }

    return true;
  }
};

int main(int argc, char **argv) {

  string s = "abab";
  if (argc != 1)
    s = string(argv[1]);

  Solution sol;

  std::cout << sol.longestPalindrome(s) << std::endl;

  return 0;
}
