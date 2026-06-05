class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 != 0) return false;
        
        stack<char> stk;
        for (char ch: s)
        {
            if (ch == '(') stk.push(')');
            else if (ch == '{') stk.push('}');
            else if (ch == '[') stk.push(']');
            else if (stk.empty() || stk.top() != ch) return false;
            else stk.pop();
        }
        return stk.empty();
    }
};