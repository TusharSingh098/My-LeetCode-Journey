class Solution {
public:
    string removeOuterParentheses(string s) {
        std::string ans;
        int oCount{0};

        for (const char ch: s)
        {
            if (ch == '(') 
            {
                if (oCount > 0) ans += ch;
                oCount++;
            }
            else 
            {
                oCount--;
                if (oCount > 0) ans += ch;
            }            
        }
        return ans;
    }
};
