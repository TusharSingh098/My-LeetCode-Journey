class Solution:
    def convertToBase7(self, num: int) -> str:
        if num == 0: 
            return "0"
        
        is_negative = num < 0
        n = abs(num)
        res = []
        
        while n:
            res.append(str(n % 7))
            n //= 7
            
        return ("-" if is_negative else "") + "".join(reversed(res))

