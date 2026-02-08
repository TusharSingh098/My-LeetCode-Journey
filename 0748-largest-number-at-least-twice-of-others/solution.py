class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        sort_nums = sorted(nums, reverse=True)
        if (sort_nums[0] >= sort_nums[1] * 2):
            return nums.index(sort_nums[0])
        else:
            return -1
