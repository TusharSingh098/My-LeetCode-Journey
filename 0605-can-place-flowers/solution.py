class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        if (n == 0):
            return True
            
        i = count = 0
        length = len(flowerbed)

        while (i < length):
            if not flowerbed[i]:
                if ((i == 0) or not flowerbed[i - 1]) and ((i == len(flowerbed) - 1) or not flowerbed[i + 1]):
                    count += 1
                    i += 1
            if (count == n):
                return True
                
            i += 1
        
        return False
