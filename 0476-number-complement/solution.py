class Solution:
    def findComplement(self, num: int) -> int:
        bin_num = bin(num)[2:]
        result = ""
        for i in bin_num:
            if (i == "0"):
                result += "1"
            else:
                result += "0"
        return int(result, 2)

