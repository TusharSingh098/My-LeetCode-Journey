class Solution {
public:
    string frequencySort(string s) {
        pair<int, char> freqs[128] = {};

        for (int i{0}; i < 128; i++) freqs[i] = {0, (char)i};
        for (const char ch: s) freqs[ch].first++;

        sort(freqs, freqs + 128, greater<pair<int, char>>());

        int writeIdx{0};
        for (const auto [freq, ch]: freqs)
        {
            if (freq == 0) break;
            for (int j{0}; j < freq; j++)
            {
                s[writeIdx++] = ch;
            }
        }
        return s;
    }
};
