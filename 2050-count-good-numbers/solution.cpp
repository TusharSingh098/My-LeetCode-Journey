class Solution {
private:
    const int MOD = 1e9 + 7;

    long long solve(long long base, long long expo)
    {
        if (expo <= 0) return 1;

        long long half{solve(base, expo / 2)};
        long long halfSquare{(half * half) % MOD};

        if (expo % 2 == 1) return (halfSquare * base) % MOD;

        return halfSquare;
    }

public:
    int countGoodNumbers(long long n) {
        long long eveCh{solve(5, (n + 1) / 2)}, oddCh{solve(4, n / 2)};
        return (eveCh * oddCh) % MOD;
    }
};
