class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ans(n);
        int p_idx{0}, n_idx{1};
        
        for (const int& num: nums)
        {
            if (num > 0)
            {
                ans[p_idx] = num;
                p_idx += 2;
            }
            else
            {
                ans[n_idx] = num;
                n_idx += 2;
            }
        }
        return ans;
    }
};
