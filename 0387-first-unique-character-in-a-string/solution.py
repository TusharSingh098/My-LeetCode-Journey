class Solution:
    def firstUniqChar(self, s: str) -> int:
        n =len(s)
        for i in set(s):

            if s.count(i)==1:
                n=min(n,s.index(i))

        if n < len(s):
            return n  
        else:
            return -1
