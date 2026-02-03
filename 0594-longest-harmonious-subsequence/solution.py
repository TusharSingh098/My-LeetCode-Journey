class Solution:
    def findLHS(self, nums: List[int]) -> int:
        freq = {}
        max_len = 0
        
        for num in nums:
            freq[num] = freq.get(num, 0) + 1
            
            if num + 1 in freq:
                max_len = max(max_len, freq[num] + freq[num + 1])
            if num - 1 in freq:
                max_len = max(max_len, freq[num] + freq[num - 1])
                
        return max_len
