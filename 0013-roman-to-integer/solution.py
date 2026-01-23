class Solution:
    __slots__ = ()

    
    def romanToInt(self, s: str) -> int:
        vals = {'M': 1000, 'D': 500, 'C': 100, 'L': 50, 'X': 10, 'V': 5, 'I': 1}

        sum = 0
        curr = prev = 0

        for i in reversed(s):
            curr = vals[i]
            if (curr < prev):
                sum -= vals[i]
            else:
                sum += vals[i]
            prev = curr

        return sum
        
