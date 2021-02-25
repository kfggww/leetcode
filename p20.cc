#include <list>
using std::list;

class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 0) {
            return true;
        }
        list<char> stack;
        stack.push_back(s[0]);

        for(int i = 1; i < s.size(); ++i) {
            char currentChar = s[i];
	    // list为空时也可以调用back
            char topChar = stack.back();
            int dis = currentChar - topChar;
	    // 括号字符之间的距离为1或者2
            if(dis == 1 || dis == 2) {
                stack.pop_back();
            }
            else {
                stack.push_back(currentChar);
            }
        }

        return stack.empty();
    }
};
