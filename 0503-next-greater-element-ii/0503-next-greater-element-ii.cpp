class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ans(n, -1);
        std::stack<int> stk;

        for (int i{2 * n - 1}; i >= 0; i--)
        {
            while (!stk.empty() && nums[stk.top() % n] <= nums[i % n]) stk.pop();
            if (i < n && !stk.empty()) ans[i] = nums[stk.top() % n];
            stk.push(i);
        }
        return ans;
    }
};