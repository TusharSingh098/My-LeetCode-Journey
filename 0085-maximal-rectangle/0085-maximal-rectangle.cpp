class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> temp(n, 0);
        stack<int> stk;
        int ans{0};

        for (int i{0}; i < m; i++)
        {
            for (int j{0}; j < n; j++)
            {
                temp[j] = (matrix[i][j] == '1') ? temp[j] + 1 : 0;
            }

            for (int j{0}; j <= n; j++)
            {
                int currVal{(j == n) ? 0 : temp[j]};

                while (!stk.empty() && temp[stk.top()] >= currVal)
                {
                    int mid{stk.top()};
                    stk.pop();

                    int pse{stk.empty() ? -1 : stk.top()}, nse{j};

                    ans = max(ans, (nse - pse - 1) * temp[mid]);
                }
                if (j < n) stk.push(j);
            }
        }
        return ans;
    }
};