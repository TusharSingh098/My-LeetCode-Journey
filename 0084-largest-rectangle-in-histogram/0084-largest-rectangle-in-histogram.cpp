class Solution {
private:
    vector<pair<int,int>> prevNextSmallerIndices(vector<int>& arr) 
    {
        int n = arr.size();
        vector<pair<int,int>> ans(n, {-1,n});
        stack<int> stk;

        for (int i{0}; i < n; i++)
        {
            while (!stk.empty() && arr[stk.top()] > arr[i]) stk.pop();

            if (!stk.empty()) ans[i].first = stk.top();
            stk.push(i);
        }
        stk = {};
        for (int i{n - 1}; i >= 0; i--)
        {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) stk.pop();

            if (!stk.empty()) ans[i].second = stk.top();
            stk.push(i);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int ans{0};
        vector<pair<int, int>> indices{prevNextSmallerIndices(heights)};

        for (int i{0}; i < heights.size(); i++)
        {
            ans = max(ans, (indices[i].second - indices[i].first - 1) * heights[i]);
        }
        return ans;

    }
};