class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        nums_set = set(nums)
        if (len(nums_set) < 3):
            return max(nums_set)
        for _ in range(2):
            nums_set.remove(max(nums_set))
        return max(nums_set)

        
