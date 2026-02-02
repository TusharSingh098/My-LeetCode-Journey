class Solution:
    def fib(self, n: int) -> int:
        if (n == 0):
            return 0
        
        def _fib(k):
            if k == 0:
                return (0, 1)
            
            # Recurse to find F(k // 2) and F(k // 2 + 1)
            a, b = _fib(k >> 1)
            
            # Use doubling identities
            c = a * ((b << 1) - a)  # F(2*m) = F(m) * [2*F(m+1) - F(m)]
            d = a * a + b * b       # F(2*m+1) = F(m)^2 + F(m+1)^2
            
            if k & 1:  # If k is odd, return (F(2m+1), F(2m+2))
                return (d, c + d)
            else:      # If k is even, return (F(2m), F(2m+1))
                return (c, d)

        return _fib(n)[0]

