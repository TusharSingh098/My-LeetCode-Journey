class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char mapS[256] = {0}, mapT[256] = {0};
        for (int i{0}; i < s.length(); i++)
        {
            if (mapS[s[i]] && mapS[s[i]] != t[i]) return false;
            if (mapT[t[i]] && mapT[t[i]] != s[i]) return false;

            mapS[s[i]] = t[i];
            mapT[t[i]] = s[i];
        }
        return true;
    }
};
