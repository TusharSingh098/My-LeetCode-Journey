class Solution {
private:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& vec, int idx)
    {
        ans.push_back(vec);
        for (int i{idx}; i < nums.size(); i++)
        {
            if (i > idx && nums[i] == nums[i - 1]) continue;
            
            vec.push_back(nums[i]);
            solve(nums, ans, vec, i + 1);
            vec.pop_back();
        }

    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> vec;
        solve(nums, ans, vec, 0);
        return ans;
    }
};