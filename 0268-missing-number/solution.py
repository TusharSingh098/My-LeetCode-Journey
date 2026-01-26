class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        total = sum(nums)
        length = len(nums)
        expected = length * (length + 1) / 2

        return int(expected - total)
