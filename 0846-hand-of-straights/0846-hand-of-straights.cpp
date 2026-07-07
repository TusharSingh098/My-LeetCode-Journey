class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        map<int, int> mpp;
        for (int val: hand) mpp[val]++;

        auto it{mpp.begin()};

        while (it != mpp.end())
        {
            if (it->second == 0)
            {
                it++;
                continue;
            }

            int start{it->first}, count{it->second};

            for (int i{0}; i < groupSize; i++)
            {
                if (mpp[start + i] < count) return false;
                mpp[start + i] -= count;
            }
            it++;
        }

        return true;
    }
};