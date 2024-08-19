// Valid Parentheses

class Solution {
public:
    bool isValid(string s) {
        stack<char> checker;
        for (auto c : s) {
            if (c == '(' or c == '{' or c == '[')
                checker.push(c);
            else {
                if (checker.empty()) return false;
                char ch = checker.top();
                if ((c == ')' and ch == '(') or (c == '}' and ch == '{') or
                    (c == ']' and ch == '['))
                    checker.pop();
                else
                    return false;
            }
        }
        if (checker.empty()) return true;
        return false;
    }
};