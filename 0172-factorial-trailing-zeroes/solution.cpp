class Solution {
public:
    int trailingZeroes(int n) {
        int twoPowers{0}, fivePowers{0};
        int twoMultiples{2}, fiveMultiples{5};

        while (twoMultiples <= n)
        {
            twoPowers += n / twoMultiples;
            twoMultiples *= 2;
        }
        while (fiveMultiples <= n)
        {
            fivePowers += n / fiveMultiples;
            fiveMultiples *= 5;
        }

        return min(twoPowers, fivePowers);
    }
};
