class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        binx = biny = None
        if (x > y):
            binx = bin(x)[2:]
            biny = bin(y)[2:].zfill(len(binx))
        else:
            biny = bin(y)[2:]
            binx = bin(x)[2:].zfill(len(biny))
        count = 0
        for i in range(len(binx) - 1, -1, -1):
            if (binx[i] != biny[i]):
                count += 1 
        return count
