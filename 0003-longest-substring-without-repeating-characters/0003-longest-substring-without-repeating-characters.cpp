class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left{0}, maxi{0};
        int nextIdx[128] = {0};

        for (int right{0}; right < s.length(); right++)
        {
            char ch{s[right]};

            left = max(left, nextIdx[ch]);
            maxi = max(maxi, right - left + 1);
            nextIdx[ch] = right + 1;
        }
        return maxi;
    }
};