class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        left_sum = 0
        right_sum = sum(nums) - nums[0]
        n = len(nums)
        i = 1
        if (right_sum == 0):
            return 0
        while (i < n):
            right_sum -= nums[i]
            left_sum += nums[i - 1]

            if (left_sum == right_sum):
                return i
            i += 1
        return -1
