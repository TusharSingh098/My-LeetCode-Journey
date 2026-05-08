class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::unordered_map<int, int> mpp;
        mpp.reserve(nums.size());

        mpp[0] = 1;

        int prefixSum{0};
        int count{0};

        for (int num: nums)
        {
            prefixSum += num;

            auto it{mpp.find(prefixSum - k)};
            if (it != mpp.end())
            {
                count += it->second;
            }
            mpp[prefixSum]++;
        }
        return count;
    }
};
