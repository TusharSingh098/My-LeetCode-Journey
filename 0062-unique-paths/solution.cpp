class Solution {
public:
    int uniquePaths(int m, int n) {
        if (n > m) swap(m, n);
        m -= 1, n -= 1;
        long long res{1};
        for (int i{1}; i <= n; i++) res = res * (m + i) / i;
        return (int)res;
    }
};
