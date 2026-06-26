class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> targetFreqs(58, 0);
        int target{0};
        for (char ch: t)
        {
            if (targetFreqs[ch - 'A'] == 0) target++;
            targetFreqs[ch - 'A']++;
        }

        vector<int> freqs(58, 0);
        int left{0}, right{0}, curr{0};
        int minLen{INT_MAX}, startIdx{0};

        while (right < s.length())
        {
            char ch{s[right]};
            freqs[ch - 'A']++;

            if (targetFreqs[ch - 'A'] > 0 && freqs[ch - 'A'] == targetFreqs[ch - 'A']) curr++;

            while (left <= right && curr == target)
            {
                if (right - left + 1 < minLen)
                {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                char leftCh{s[left]};
                freqs[leftCh - 'A']--;

                if (targetFreqs[leftCh - 'A'] > 0 && freqs[leftCh - 'A'] < targetFreqs[leftCh - 'A']) curr--;
                left++;
            }
            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};