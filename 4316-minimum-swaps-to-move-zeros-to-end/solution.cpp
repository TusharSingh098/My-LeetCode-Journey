class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size(), count{0};
        int left{0}, right{n - 1};
        while (left < right)
            {
                if (nums[left] == 0 && nums[right] != 0)
                {
                    count++;
                    left++;
                    right--;
                }
                else if (nums[left] != 0) left++;
                else if (nums[right] == 0) right--;                
            }
        return count;
    }
};
