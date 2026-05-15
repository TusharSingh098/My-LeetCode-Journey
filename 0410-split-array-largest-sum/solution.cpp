class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        if (nums.size() < k) return -1;

        int low{0}, high{0};
        for (const int num: nums)
        {
            low = std::max(low, num);
            high += num;
        }

        while (low <= high)
        {
            int mid{low + (high - low) / 2};
            int count{1}, sum{0};
            for (const int num: nums)
            {
                if (sum + num > mid)
                {
                    sum = 0;
                    if (count++ >= k) break;
                }
                sum += num;
            }
            if (count > k) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};
