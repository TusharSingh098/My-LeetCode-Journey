class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int left{0}, right{0}, maxi{0};
        bool unique[128] = {false};

        while (right < n)
        {
            char ch{s[right]};

            while (unique[ch])
            {
                unique[s[left]] = false;
                left++;
            }

            unique[ch] = true;
            maxi = max(maxi, right - left + 1);
            right++;
        }
        return maxi;
    }
};