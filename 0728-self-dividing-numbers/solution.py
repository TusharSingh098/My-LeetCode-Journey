def selfDivide(num: int) -> bool:
    b = num
    while (b > 0):
        last_dgt = b % 10
        if (last_dgt == 0):
            return False
        if (num % last_dgt == 0):
            b //= 10
        else:
            return False
    return True

class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        rslt = []
        for i in range(left, right + 1):
            if (selfDivide(i)):
                rslt.append(i)

        return rslt      
