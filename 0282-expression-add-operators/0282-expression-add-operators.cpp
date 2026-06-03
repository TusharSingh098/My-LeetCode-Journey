class Solution {
private:
    void solve(string& num, int target, vector<string>& ans, int start, string exp, long long currVal, long long lastOpr)
    {
        if (start == num.length())
        {
            if (currVal == target) ans.emplace_back(exp);
            return;
        }

        for (int i{start}; i < num.size(); i++)
        {
            if (i > start && num[start] == '0') return;

            string currNum{num.substr(start, i - start + 1)};
            long long currNumVal{stoll(currNum)};

            if (start == 0) solve(num, target, ans, i + 1, currNum, currNumVal, currNumVal);
            else
            {
                solve(num, target, ans, i + 1, exp + "+" + currNum, currVal + currNumVal, currNumVal);
                solve(num, target, ans, i + 1, exp + "-" + currNum, currVal - currNumVal, -currNumVal);
                solve(num, target, ans, i + 1, exp + "*" + currNum, currVal - lastOpr + lastOpr * currNumVal, lastOpr * currNumVal);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        solve(num, target, ans, 0, "", 0, 0);
        return ans;
    }
};