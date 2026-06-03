class Solution {
private:
    void solve(string& num, int target, vector<string>& ans, int start, string& exp, long long currVal, long long lastOpr)
    {
        if (start == num.length())
        {
            if (currVal == target) ans.push_back(exp);
            return;
        }

        long long currNumVal{0};
        int len = exp.length();

        for (int i{start}; i < num.length(); i++)
        {
            if (i > start && num[start] == '0') break;
            
            currNumVal = currNumVal * 10 + (num[i] - '0');

            if (start == 0) 
            {
                exp += num.substr(start, i - start + 1);
                solve(num, target, ans, i + 1, exp, currNumVal, currNumVal);
                exp.resize(len);
            }
            else
            {
                exp += "+" + num.substr(start, i - start + 1);
                solve(num, target, ans, i + 1, exp, currVal + currNumVal, currNumVal);
                exp.resize(len);

                exp += "-" + num.substr(start, i - start + 1);
                solve(num, target, ans, i + 1, exp, currVal - currNumVal, -currNumVal);
                exp.resize(len);

                exp += "*" + num.substr(start, i - start + 1);
                solve(num, target, ans, i + 1, exp, currVal - lastOpr + (lastOpr * currNumVal), lastOpr * currNumVal);
                exp.resize(len);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string exp;
        exp.reserve(num.length() * 2);
        solve(num, target, ans, 0, exp, 0, 0);
        return ans;
    }
};