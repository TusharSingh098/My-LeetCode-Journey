class Solution {
public:
    int characterReplacement(string s, int k) {
        int left{0}, maxFreq{0}, maxLen{0};
        int freqs[26] = {0};
        for (int right{0}; right < s.length(); right++)
        {
            maxFreq = max(maxFreq, ++freqs[s[right] - 'A']);

            if (right - left + 1 - maxFreq > k) 
            {
                freqs[s[left] - 'A']--;
                left++; 
            }

            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};