#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> tmp;
        int i;

        for (i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                tmp.push(s[i]);
            else if (tmp.size() > 0 && tmp.top() == '(' && s[i] == ')')
                tmp.pop();
            else if (tmp.size() > 0 && tmp.top() == '{' && s[i] == '}')
                tmp.pop();
            else if (tmp.size() > 0 && tmp.top() == '[' && s[i] == ']')
                tmp.pop();
            else
                tmp.push(s[i]);
        }
        
        return tmp.size() == 0;
    }
};
