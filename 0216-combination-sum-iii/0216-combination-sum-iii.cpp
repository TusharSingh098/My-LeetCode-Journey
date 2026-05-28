class Solution {
private:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& vec, int k, int n, int idx)
    {
        if (k == 0)
        {
            if (n == 0) ans.emplace_back(vec);
            return;
        }
        if (n < 0 || (nums.size() - idx) < k) return;

        if (nums[idx] <= n)
        {
            vec.push_back(nums[idx]);
            solve(nums, ans, vec, k - 1, n - nums[idx], idx + 1);
            vec.pop_back();
        }

        solve(nums, ans, vec, k, n, idx + 1);
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> vec, nums{1,2,3,4,5,6,7,8,9};
        solve(nums, ans, vec, k, n, 0);
        return ans;
    }
};