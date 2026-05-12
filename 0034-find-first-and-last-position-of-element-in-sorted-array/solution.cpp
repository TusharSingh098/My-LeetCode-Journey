class Solution {
private:
    int lowerBound(std::vector<int>& nums, int x) 
    {
        int low{0}, high = (int)nums.size() - 1;
        int ans = nums.size();
        while (low <= high)
        {
            int mid{low + (high - low) / 2};
            if (nums[mid] >= x) 
            {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
    
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int start = lowerBound(nums, target);

        if (start == nums.size() || nums[start] != target) return {-1, -1};

        int end = lowerBound(nums, target + 1) - 1;

        return {start, end};
    }
};
