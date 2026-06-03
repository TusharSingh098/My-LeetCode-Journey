class Solution {
public:
    int countPrimes(int n) {
        int limit{n - 1};
        if (limit < 2)
            return 0;

        int prime_count{1};

        int max_idx{limit / 2};
        std::vector<bool> is_prime(max_idx + 1, true);

        for (int i{3}; i * i <= limit; i += 2) 
        {
            if (is_prime[i / 2]) 
            {
                for (int j{i * i}; j <= limit; j += 2 * i) 
                {
                    is_prime[j / 2] = false;
                }
            }
        }

        for (int i{1}; i <= max_idx; ++i) 
        {
            int odd_num{2 * i + 1};
            if (odd_num < n && is_prime[i]) 
            {
                prime_count++;
            }
        }

        return prime_count;
    }
};