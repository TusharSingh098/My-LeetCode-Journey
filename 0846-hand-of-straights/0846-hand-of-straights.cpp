class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        unordered_map<int, int> count;
        for (int card: hand) count[card]++;

        for (int card: hand)
        {
            if (count[card] == 0) continue;

            int start{card};
            while (count[start - 1] > 0) start--;
            
            while (start <= card)
            {
                while (count[start] > 0)
                {
                    int start_freq = count[start];
                    for (int i{0}; i < groupSize; i++)
                    {
                        if (count[start + i] < start_freq) return false;
                        count[start + i] -= start_freq;
                    }
                }
                start++;
            }
        }
        return true;
    }
};