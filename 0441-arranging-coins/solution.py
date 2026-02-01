class Solution:
    def arrangeCoins(self, n: int) -> int:
        
        left, right = 0, n
        while left <= right:
            mid = left + (right - left) // 2
            coins_used = (mid * (mid + 1)) // 2
            if (coins_used == n):
                return mid
            elif ((mid * (mid - 1)) // 2 > n):
                right = mid - 1
            elif (coins_used > n):
                return mid - 1
            else:
                left = mid + 1
