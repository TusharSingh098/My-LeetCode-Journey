class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        result = 0
        place_val = {chr(64 + i): i for i in range(1, 27)}
        multiple = 1
        for i in reversed(columnTitle):
            result += place_val[i] * multiple
            
            multiple *= 26

        return result

