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
    int sumSubarrayMins(vector<int>& arr) {
        vector<pair<int, int>> indices{prevNextSmallerIndices(arr)};
        long long ans{0}, mod{(int)(1e9 + 7)};
        for (int i{0}; i < arr.size(); i++)
        {
            ans = (ans + ((1LL * (i - indices[i].first) * (indices[i].second - i) * arr[i]) % mod)) % mod;
        }
        return (int)ans;
    }
};