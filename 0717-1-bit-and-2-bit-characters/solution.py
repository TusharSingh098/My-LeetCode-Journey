class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        i = 0
        length = len(bits)
        while (i < length - 1):
            if (bits[i] == 1):
                i += 2
            else:
                i += 1

        return i == length - 1


