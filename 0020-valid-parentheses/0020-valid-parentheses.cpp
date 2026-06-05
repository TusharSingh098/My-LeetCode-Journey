class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mpp{{')','('},{'}','{'},{']','['}};
        stack<char> stk;
        for (char ch: s)
        {
            if (ch == '(' || ch == '{' || ch == '[') stk.push(ch);
            else if (!stk.empty() && stk.top() == mpp[ch]) stk.pop();
            else return false;
        }
        return stk.empty();
    }
};