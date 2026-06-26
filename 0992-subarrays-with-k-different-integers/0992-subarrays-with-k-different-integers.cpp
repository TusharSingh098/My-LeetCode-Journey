class Solution {
private:
    int solve(vector<int>& nums, int k)
    {
        if (k <= 0) return 0;
        
        int left{0}, distincts{0}, count{0};
        unordered_map<int, int> mpp;

        for (int right{0}; right < nums.size(); right++)
        {
            if (mpp[nums[right]]++ == 0) distincts++;

            while (distincts > k)
            {
                if (mpp[nums[left++]]-- == 1) distincts--;
            }

            count += right - left + 1;
            cout << right - left + 1 << "\n";
        }

        return count;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};