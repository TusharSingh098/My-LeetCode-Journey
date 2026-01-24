class Solution:
    def climbStairs(self, n: int) -> int:
        if (n <= 3):
            return n
        n1, n2 = 2, 3
        for i in range(3, n):
            n1, n2 = n2, n1 + n2
        return n2
