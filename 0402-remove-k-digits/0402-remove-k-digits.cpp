class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.length() == k) return "0";

        string ans;
        for (char curr: num)
        {
            while (!ans.empty() && ans.back() > curr && k > 0)
            {
                ans.pop_back();
                k--;
            }
            if (ans.empty() && curr == '0') continue; 
            ans.push_back(curr);
        }

        while (k > 0 && !ans.empty())
        {
            ans.pop_back();
            k--;
        }

        return ans.empty() ? "0" : ans;
    }
};