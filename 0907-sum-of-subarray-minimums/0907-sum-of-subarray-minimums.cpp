class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> stk;
        long long ans = 0;
        long long mod = 1e9 + 7;

        for (int i = 0; i <= n; i++) 
        {
            int currVal = (i == n) ? 0 : arr[i];

            while (!stk.empty() && arr[stk.top()] > currVal) 
            {
                int mid = stk.top();
                stk.pop();

                int lBound = stk.empty() ? -1 : stk.top();
                int rBound = i;

                long long lCount = mid - lBound;
                long long rCount = rBound - mid;

                ans = (ans + (lCount * rCount % mod * arr[mid] % mod)) % mod;
            }
            stk.push(i);
        }
        return ans;
    }
};