class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        max_count = 0
        current_count = 0
        
        for num in nums:
            if num:
                current_count += 1
                if current_count > max_count:
                    max_count = current_count
            else:
                current_count = 0
        
        return max(max_count, current_count)

