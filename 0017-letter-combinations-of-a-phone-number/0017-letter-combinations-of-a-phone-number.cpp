class Solution {
private:
    void solve(vector<string>& ans, string combos[], string& digits, string str, int idx)
    {
        if (idx == digits.length())
        {
            ans.push_back(str);
            return;
        }

        int digit{digits[idx] - '0'};

        for (int i{0}; i < combos[digit].size(); i++)
        {
            solve(ans, combos, digits, str + combos[digit][i], idx + 1);
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string str;
        solve(ans, combos, digits, str, 0);
        return ans;
    }
};