class Solution {
private:
    int solve(string& s, int i, int sign, long long res)
    {
        if (i >= s.length() || !isdigit(s[i]))
            return (int)res * sign;
        
        int digit{s[i] - '0'};
        res = res * 10 + digit;

        if (res > INT_MAX) return sign == 1 ? INT_MAX : INT_MIN;

        return solve(s, i + 1, sign, res);
    }

public:
    int myAtoi(string s) {
        int n = s.length(), i{0}, sign{1};

        while (i < n && s[i] == ' ') i++;

        if (i < n && (s[i] == '+' || s[i] == '-'))
        {
            sign = s[i] == '-' ? -1 : 1;
            i++;
        }

        return solve(s, i, sign, 0);
    }
};
