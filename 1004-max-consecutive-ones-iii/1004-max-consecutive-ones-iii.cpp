class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left{0}, numZeros{0}, maxLen{0};

        for (int right{0}; right < nums.size(); right++)
        {
            if (!nums[right]) 
            {
                numZeros++;
            }

            while (numZeros > k) 
            {
                if (!nums[left]) numZeros--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};