class Solution:
    def dominantIndices(self, nums: List[int]) -> int:
        add = sum(nums)
        length = len(nums)
        count = 0
        for i in nums[:length - 1]:
            add -= i
            length -= 1
            if (i > add / length):
                count += 1
        return count
            
