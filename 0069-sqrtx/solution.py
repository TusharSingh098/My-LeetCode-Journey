class Solution:
    def mySqrt(self, x: int) -> int:
        n = 1
        for _ in range(40):
            n = (n + x/n) * 0.5
        return int(n)
        
