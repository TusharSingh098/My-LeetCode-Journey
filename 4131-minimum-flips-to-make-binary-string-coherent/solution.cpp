class Solution {
public:
    int minFlips(string s) {
        int numOnes{0}, numZeros{0};
        for (char bit: s)
            {
                if (bit == '1') numOnes++;
                else numZeros++;
            }
        if (numOnes <= 1) return 0;
        if (numZeros == 0) return 0;
        if (s[0] == '1' && s[s.length() - 1] == '1')
        {
            if (numZeros < numOnes - 2) return numZeros;
            else return numOnes - 2;
        }
        if ((s[0] == '0' && s[s.length() - 1] == '1') || (s[0] == '1' && s[s.length() - 1] == '0'))
        {
            if (numZeros < numOnes- 1) return numZeros;
            else return numOnes - 1;
        }
        if (s[0] == '0' && s[s.length() - 1] == '0')
        {
            if (numZeros < numOnes- 1) return numZeros;
            else return numOnes - 1;
        }
        return 0;
    }
};
