class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        const int n = nums.size();
        vector<vector<int>> ans;
        if (n < 4) return ans;

        sort(nums.begin(), nums.end());
        for (int i{0}; i < n - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            if ((long long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
            if ((long long)nums[i] + nums[n-3] + nums[n-2] + nums[n-1] < target) continue;

            for (int j{i + 1}; j < n - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                if ((long long)nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                if ((long long)nums[i] + nums[j] + nums[n-2] + nums[n-1] < target) continue;

                int k{j + 1}, l{n - 1};
                while (k < l)
                {
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum < target) k++;
                    else if (sum > target) l--;
                    else
                    {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++, l--;
                        while (k < l && nums[k] == nums[k - 1]) k++;
                        while (k < l && nums[l] == nums[l + 1]) l--;
                    }
                }
            }
        }
        return ans;
    }
};
