import math

class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        min1 = min2 = math.inf
        max1 = max2 = max3 = -math.inf
        
        for n in nums:
            if n > max1:
                max3 = max2
                max2 = max1
                max1 = n
            elif n > max2:
                max3 = max2
                max2 = n
            elif n > max3:
                max3 = n
            
            if n < min1:
                min2 = min1
                min1 = n
            elif n < min2:
                min2 = n
        
        prod1 = max1 * max2 * max3
        prod2 = min1 * min2 * max1
        
        return max(prod1, prod2)
