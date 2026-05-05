class Solution {
public:
    void reverseArray(std::vector<int>& nums, int start, int end)
    {
        while (start < end)
        {
            std::swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n= nums.size();
        k %= n;
        if (n <= 1) return;

        reverseArray(nums, 0, n - k - 1);
        reverseArray(nums, n - k, n - 1);
        reverseArray(nums, 0, n - 1);
    }
};
