class Solution {
public:
    int characterReplacement(string s, int k) {
        int left{0}, right{0}, maxFreq{0}, maxLen{0};
        int freqs[26] = {0};
        for (right = 0; right < s.length(); right++)
        {
            maxFreq = max(maxFreq, ++freqs[s[right] - 'A']);

            while (right - left + 1 - maxFreq > k)
            {
                freqs[s[left] - 'A']--;
                left++;
                maxLen = 0;
                for (int freq: freqs) maxLen = max(maxLen, freq);
            }     

            int currLen{right - left + 1};
            if (currLen - maxFreq <= k) maxLen = max(maxLen, currLen);
        }
        return maxLen;
    }
};