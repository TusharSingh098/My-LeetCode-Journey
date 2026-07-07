class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int maxFreq{INT_MIN};
        vector<int> freqs(26, 0);
        for (char ch: tasks) 
        {
            freqs[ch - 'A']++;
            maxFreq = max(maxFreq, freqs[ch - 'A']);
        }

        int maxFreqCount{0};        
        for (int freq: freqs) if (freq == maxFreq) maxFreqCount++;

        int ans = (maxFreq - 1) * (n + 1) + maxFreqCount;
        return max(ans, (int)(tasks.size()));
    }
};