class Solution:
    def isHappy(self, n: int) -> bool:
        sqr_sums = []
        while (n != 1):
            sqr_sum = 0
            while (n > 0):
                sqr_sum += (n % 10) ** 2
                n //= 10
            if (sqr_sum in sqr_sums):
                break
            else:
                n = sqr_sum
                sqr_sums.append(sqr_sum)
        else:
            return True
        
        return False
