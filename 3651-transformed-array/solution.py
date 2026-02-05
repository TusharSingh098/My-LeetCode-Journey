class Solution:
    def constructTransformedArray(self, nums: List[int]) -> List[int]:
        length = len(nums)
        return [nums[(i + val) % length] for i, val in enumerate(nums)]
