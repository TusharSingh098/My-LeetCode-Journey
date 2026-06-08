class Solution {
private:
    struct Boundaries 
    {
        pair<int, int> minBounds;
        pair<int, int> maxBounds;
    };

    vector<Boundaries> solve(vector<int>& nums) 
    {
        int n = nums.size();
        vector<Boundaries> ans(n, {{-1, n}, {-1, n}});
        stack<int> stk1, stk2;

        for (int i{0}; i < n; i++)
        {
            while (!stk1.empty() && nums[stk1.top()] > nums[i]) stk1.pop();

            if (!stk1.empty()) ans[i].minBounds.first = stk1.top();
            stk1.push(i);

            while (!stk2.empty() && nums[stk2.top()] < nums[i]) stk2.pop();

            if (!stk2.empty()) ans[i].maxBounds.first = stk2.top();
            stk2.push(i);
        }

        stk1 = stk2 = {};
        for (int i{n - 1}; i >= 0; i--)
        {
            while (!stk1.empty() && nums[stk1.top()] >= nums[i]) stk1.pop();

            if (!stk1.empty()) ans[i].minBounds.second = stk1.top();
            stk1.push(i);

            while (!stk2.empty() && nums[stk2.top()] <= nums[i]) stk2.pop();

            if (!stk2.empty()) ans[i].maxBounds.second = stk2.top();
            stk2.push(i);
        }
        return ans;
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        vector<Boundaries> indices{solve(nums)};
        long long ans{0};
        for (int i{0}; i < nums.size(); i++)
        {
            long long maxi{1LL * (i - indices[i].maxBounds.first) * (indices[i].maxBounds.second - i)}, mini{1LL * (i - indices[i].minBounds.first) * (indices[i].minBounds.second - i)};
            ans += (maxi - mini) * nums[i];
        }
        return ans;
    }
};