class Solution {
public:
    int numberOfSpecialChars(string word) {
        int lows{0}, ups{0};

        for (char ch: word)
        {
            if (islower(ch)) lows |= (1 << (ch - 'a'));
            else ups |= (1 << (ch - 'A'));
        }

        return __builtin_popcount(ups & lows);
    }
};
