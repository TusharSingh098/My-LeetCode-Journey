class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> stk;
        int ans{0};

        for (int i{0}; i <= n; i++)
        {
            int currHeight{(i == n) ? 0 : heights[i]};

            while (!stk.empty() && heights[stk.top()] > currHeight)
            {
                int height{heights[stk.top()]};
                stk.pop();

                int width{stk.empty() ? i : i - stk.top() - 1};

                ans = max(ans, width * height);
            }
            stk.push(i);
        }
        return ans;
    }
};