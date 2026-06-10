class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> stk;
        int ans{0};

        for (int i{0}; i <= n; i++)
        {
            int currVal{(i == n) ? 0 : heights[i]};

            while (!stk.empty() && heights[stk.top()] >= currVal)
            {
                int mid{stk.top()};
                stk.pop();

                int pse{stk.empty() ? -1 : stk.top()}, nse{i};

                ans = max(ans, (nse - pse - 1) * heights[mid]);
            }
            stk.push(i);
        }
        return ans;
    }
};