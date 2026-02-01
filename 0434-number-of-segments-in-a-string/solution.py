class Solution:
    def countSegments(self, s: str) -> int:
        count = 0
        inword = 0
        for i in s:
            if not inword and (i != " "):
                count += 1
                inword = 1
            elif inword and (i == " "):
                inword = 0
        return count
        
