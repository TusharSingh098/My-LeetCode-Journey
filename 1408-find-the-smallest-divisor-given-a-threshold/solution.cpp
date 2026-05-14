class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low{1}, high{0};
        long long total{0};
        for (const int num: nums)
        {
            high = max(high, num);
            total += num;
        }
        int min_div = (total + threshold - 1) / threshold;
        low = max(low, min_div);

        while (low <= high)
        {
            int mid{low + (high - low) / 2};
            long long div_sum{0};

            for (const int num: nums) div_sum += (num + mid - 1) / mid;
            if (div_sum > threshold) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};
