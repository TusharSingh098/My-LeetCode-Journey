class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans{0}, count{0};
        for (const int& num: nums)
        {
            if (count == 0) ans = num;
            
            if (num == ans) count++;
            else count--;
        }
        return ans;
    }
};
