class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n >= 1:
            while n > 1:
                if n%3 == 0:
                    n = (n / 3)
                else:
                    return False
            return True
        return False
