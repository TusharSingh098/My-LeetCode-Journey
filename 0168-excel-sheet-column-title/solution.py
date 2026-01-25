class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        result = ""
        num = columnNumber
        place_val = {i: chr(65 + i) for i in range(26)}
        while (num > 0):
            num -= 1
            result = place_val[(num % 26)] + result
            num //= 26
        return result

