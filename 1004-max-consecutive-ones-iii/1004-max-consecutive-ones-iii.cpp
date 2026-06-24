class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left{0}, right{0}, numZeros{0}, maxLen{0};

        while (right < n)
        {
            if (nums[right] == 0)
            {
                if (numZeros < k) numZeros++;
                else
                {
                    while (left < right && nums[left]) left++;
                    left++;
                }
            }
            right++;
            maxLen = max(maxLen, right - left);          
        }
        return maxLen;
    }
};