class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        length = len(t)
        if (length < len(s)):
            return False
        idx = 0
        length = len(t)
        for i in s:
            while (idx < length):
                if (t[idx] == i):
                    break
                idx += 1
            else:
                return False
            idx += 1
        else:
            return True
        

