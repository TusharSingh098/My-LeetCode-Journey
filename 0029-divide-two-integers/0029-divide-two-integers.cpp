class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        bool isPositive{(dividend >= 0) == (divisor >= 0)};
        
        long long n{abs(static_cast<long long>(dividend))};
        long long d{abs(static_cast<long long>(divisor))};
        
        long long ans{0};
        
        for (int i{31}; i >= 0; i--) 
        {
            if ((d << i) <= n) 
            {
                ans += (1LL << i);
                n -= (d << i);
            }
        }
        
        return isPositive ? static_cast<int>(ans) : static_cast<int>(-ans);
    }
};