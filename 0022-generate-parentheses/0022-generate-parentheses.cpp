class Solution {
private:
    void solve(vector<string>& ans, string& str, int n, int open, int close)
    {
        if (str.length() == 2 * n)
        {
            ans.push_back(str);
            return;
        }

        if (open < n) 
        {
            str.push_back('(');
            solve(ans, str, n, open + 1, close);
            str.pop_back();
        }

        if (close < open) 
        {
            str.push_back(')');
            solve(ans, str, n, open, close + 1);
            str.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        if (n == 1) return {"()"};
        
        string str;
        vector<string> ans;

        solve(ans, str, n, 0, 0);

        return ans;
    }
};