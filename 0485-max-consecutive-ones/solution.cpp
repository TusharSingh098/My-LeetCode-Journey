class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_len{0}, curr_len{0};
        for (const int& num: nums)
        {
            if (num) curr_len++;
            else
            {
                if (curr_len > max_len) max_len = curr_len;
                curr_len = 0;
            }
        }
        return max(curr_len, max_len);
    }
};
