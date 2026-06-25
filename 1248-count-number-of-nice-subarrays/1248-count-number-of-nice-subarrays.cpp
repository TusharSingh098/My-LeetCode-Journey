class Solution {
private:
    int solve(const vector<int>& nums, int k)
    {
        if (k < 0) return 0;
        int left{0}, numOdds{0}, count{0};

        for (int right{0}; right < nums.size(); right++)
        {
            if (nums[right] & 1) numOdds++;

            while (numOdds > k)
            {
                if (nums[left] & 1) numOdds--;
                left++;
            }

            count += right - left + 1;
        }
        return count;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};