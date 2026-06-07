class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> rMax(n);
        int x{height[n - 1]};
        for (int i{n - 1}; i >= 0; i--)
        {
            x = max(x, height[i]);
            rMax[i] = x;
        }

        int ans{0};
        x = height[0];
        for (int i{0}; i < n; i++)
        {
            x = max(x, height[i]);
            ans += min(x, rMax[i]) - height[i];
        }

        return ans;
    }
};