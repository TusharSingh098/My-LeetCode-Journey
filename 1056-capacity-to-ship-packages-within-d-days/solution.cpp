class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low{0}, high{0};
        for (const int weight: weights)
        {
            high += weight;
            low = max(low, weight);
        }
        low = max(low, (high + days - 1) / days);
        while (low <= high)
        {
            int mid{low + (high - low) / 2};
            int currWeight{0}, count{1};

            for (const int weight : weights) 
            {
                currWeight += weight;
                if (currWeight > mid) 
                {
                    count++;
                    currWeight = weight;
                }
            }
            
            if (count <= days) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};
