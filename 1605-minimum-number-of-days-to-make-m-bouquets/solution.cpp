class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (bloomDay.size() < (long long)m * k) return -1;

        int low{INT_MAX}, high{INT_MIN};
        for (const int day: bloomDay)
        {
            low = min(low, day);
            high = max(high, day);
        }
        
        while (low <= high)
        {
            int mid{low + (high - low) / 2};

            int bouquets{0}, count{0};
            for (const int day: bloomDay)
            {
                if (day <= mid) 
                {
                    count++;
                    if (count == k) 
                    {
                        bouquets++;
                        count = 0;
                        if (bouquets >= m) break;
                    }
                } 
                else count = 0;
            }

            if (bouquets >= m) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};
