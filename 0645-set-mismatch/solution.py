class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        uniq_sum = sum(set(nums))
        length = len(nums)
        return [sum(nums) - uniq_sum, length * (length + 1) // 2 - uniq_sum]
