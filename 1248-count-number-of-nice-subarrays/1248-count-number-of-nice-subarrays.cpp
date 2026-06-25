class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left{0}, numOdds{0}, total{0}, curr{0};

        for (int right{0}; right < nums.size(); right++)
        {
            if (nums[right] & 1) 
            {
                numOdds++;
                curr = 0;
            }

            while (numOdds == k)
            {
                if (nums[left] & 1) numOdds--;
                curr++;
                left++;
            }

            total += curr;
        }
        return total;
    }
};