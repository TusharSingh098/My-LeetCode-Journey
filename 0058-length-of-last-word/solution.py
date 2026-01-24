class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        started = 0
        length = 0
        for i in reversed(s):
            if (i != " "):
                started = 1
            if (i == " " and started):
                break
            if started:
                length += 1 
        return length
           
