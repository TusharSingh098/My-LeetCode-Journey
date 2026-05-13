class Solution {
public:
    double myPow(double x, int n) {
        double ans{1.0};
        long long power = n;
        if (power < 0) power = -power;
        
        while (power > 0)
        {
            if (power % 2 == 1) ans *= x;
            power /= 2;
            x *= x;
        }
        return n >= 0 ? ans : 1 / ans;
    }
};
