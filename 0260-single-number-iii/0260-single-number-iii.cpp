class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long n{0};
        for (int num: nums) n ^= num;
        n = n & -n;

        int b1{0}, b2{0};
        for (int num: nums)
        {
            if (num & n) b1 ^= num;
            else b2 ^= num;
        }

        return {b1, b2};
    }
};