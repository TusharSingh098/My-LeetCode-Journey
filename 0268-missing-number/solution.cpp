class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long sum{0};
        for (int num: nums) sum += num;
        return (((int)nums.size() * (nums.size() + 1)) / 2) - sum;
    }
};
