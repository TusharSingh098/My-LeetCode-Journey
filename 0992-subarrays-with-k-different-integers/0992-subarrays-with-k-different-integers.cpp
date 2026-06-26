class Solution {
private:
    int solve(const vector<int>& nums, int k)
    {
        if (k <= 0) return 0;
        
        int n = nums.size();
        int left{0}, distincts{0}, count{0};
        vector<int> freqs(n + 1, 0);

        for (int right{0}; right < n; right++)
        {
            if (freqs[nums[right]]++ == 0) distincts++;

            while (distincts > k)
            {
                if (freqs[nums[left++]]-- == 1) distincts--;
            }

            count += right - left + 1;
        }

        return count;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};