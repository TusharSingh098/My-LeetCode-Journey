class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        int low{1}, high{0};
        long long total_bananas{0};

        for (const int num: piles)
        {
            high = max(high, num);
            total_bananas += num;
        }
        
        int min_speed = (total_bananas + h - 1) / h;
        low = max(min_speed, low);

        while (low <= high)
        {
            int mid{low + (high - low) / 2};

            long long time{0};
            for (const int num : piles) time += (num + mid - 1) / mid;

            if (time <= h) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};
