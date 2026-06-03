class Solution {
public:
    int minBitFlips(int start, int goal) {
        start ^= goal;
        goal = 0;
        while (start > 0)
        {
            goal++;
            start &= start - 1;
        }
        return goal;
    }
};