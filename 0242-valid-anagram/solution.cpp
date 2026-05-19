class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        int letters[26] = {0};
        for (char ch: s) letters[ch - 'a']++;
        for (char ch: t) 
        {
            if (--letters[ch - 'a'] < 0) return false;
        }

        return true;
    }
};
