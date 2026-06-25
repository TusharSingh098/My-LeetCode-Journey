class Solution {
public:
    int numberOfSubstrings(string s) {
        int total{0};
        int lastSeen[3] = {-1, -1, -1}; 

        for (int right{0}; right < s.length(); right++)
        {
            lastSeen[s[right] - 'a'] = right;
            total += min({lastSeen[0], lastSeen[1], lastSeen[2]}) + 1;
        }
        
        return total;
    }
};