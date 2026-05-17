class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> mpp1, mpp2;
        for (char ch: s) mpp1[ch]++;
        for (char ch: t) mpp2[ch]++;

        for (char ch: s)
        {
            if (mpp1[ch] != mpp2[ch]) return false;
        }
        return true;
    }
};
