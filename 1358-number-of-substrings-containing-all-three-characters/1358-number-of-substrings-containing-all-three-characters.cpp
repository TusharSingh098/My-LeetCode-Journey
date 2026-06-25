class Solution {
public:
    int numberOfSubstrings(string s) {
        int left{0}, total{0};
        int freqs[3] = {0};

        for (int right{0}; right < s.length(); right++)
        {
            freqs[s[right] - 'a']++;

            while (freqs[0] > 0 && freqs[1] > 0 && freqs[2] > 0)
            {
                freqs[s[left] - 'a']--;
                left++;
            }

            total += left;
        }
        
        return total;
    }
};