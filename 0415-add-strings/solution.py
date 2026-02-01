numbers = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]
mapping = {numbers[i]: i for i in range(10)}
rev_mapping = {i: numbers[i] for i in range(10)}

class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        length1 = len(num1)
        length2 = len(num2)
        if (length1 > length2):
            num2 = num2.zfill(length1)
        else:
            num1 = num1.zfill(length2)

        result = []
        carry = 0
        for i in range(max(length1, length2) - 1, -1, -1):
            digit_sum = mapping[num1[i]] + mapping[num2[i]] + carry
            if (digit_sum > 9):
                carry = 1
                digit_sum %= 10
            else:
                carry = 0
            result.append(rev_mapping[digit_sum])
        if carry:
            result.append(rev_mapping[carry])
        return "".join(result[::-1])

        
