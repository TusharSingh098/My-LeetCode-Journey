class Solution:
    def reverseBits(self, n: int) -> int:
        # 1. Normalize signed input to its 32-bit unsigned equivalent
        n &= 0xFFFFFFFF
        
        # 2. Divide and Conquer Swaps
        # Swap 16-bit blocks
        n = (n >> 16) | (n << 16) & 0xFFFFFFFF
        # Swap 8-bit blocks
        n = ((n & 0xFF00FF00) >> 8) | ((n & 0x00FF00FF) << 8)
        # Swap 4-bit blocks
        n = ((n & 0xF0F0F0F0) >> 4) | ((n & 0x0F0F0F0F) << 4)
        # Swap 2-bit blocks
        n = ((n & 0xCCCCCCCC) >> 2) | ((n & 0x33333333) << 2)
        # Swap 1-bit blocks
        n = ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1)
        
        # 3. Re-interpret as a 32-bit signed integer
        # Max signed value is 2,147,483,647 (0x7FFFFFFF)
        if n > 0x7FFFFFFF:
            return n - 0x100000000
        return n

