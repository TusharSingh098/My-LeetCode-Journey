class Solution {
public:
    int beautySum(string s) {
        int n = s.length(), sum{0};

        for (int i{0}; i < n; i++)
        {
            int freq[26] = {0};

            for (int j{i}; j < n; j++)
            {
                freq[s[j] - 'a']++;
                int maxi{INT_MIN}, mini{INT_MAX};

                for (int num: freq)
                {
                    if (num > 0)
                    {
                        mini = std::min(mini, num);
                        maxi = std::max(maxi, num);
                    }
                }
                sum += (maxi - mini);
            }
        }
        return sum;
    }
};
