class Solution
{
    private:
        void reverseArray(std::vector<int>& arr, int start, int end)
        {
            while (start < end)
            {
                std::swap(arr[start], arr[end]);
                start++;
                end--;
            }
        }

    public:
        void nextPermutation(std::vector<int>& nums)
        {
            if (nums.size() <= 1) return;
            else if (nums.size() == 2)
            {
                std::swap(nums[1], nums[0]);
                return;
            }

            int n = nums.size();
            int idx = n - 2;
            while (idx >= 0 && nums[idx] >= nums[idx + 1]) idx--;
            if (idx == -1)
            {
                reverseArray(nums, 0, n - 1);
                return;
            }

            for (int i = n - 1; i > idx; i--)
            {
                if (nums[i] > nums[idx])
                {
                    std::swap(nums[idx], nums[i]);
                    break;
                }
            }
            
            reverseArray(nums, idx + 1, n - 1);
        }
};
