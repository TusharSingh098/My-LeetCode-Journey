class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        n = nums[0]
        for i in nums[1:]:
            n ^= i
        return n
        
