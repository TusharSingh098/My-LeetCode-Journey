class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        const int n = nums.size();
        std::vector<std::vector<int>> ans;
        std::sort(nums.begin(), nums.end());
        for (int i{0}; i < nums.size(); i++)
        {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int j{i + 1};
            int k{n - 1};
            while (j < k)
            {
                int sum{nums[i] + nums[j] + nums[k]};
                if (sum < 0) j++;
                else if (sum > 0) k--;
                else
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++, k--;
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        return ans;
    }
};
