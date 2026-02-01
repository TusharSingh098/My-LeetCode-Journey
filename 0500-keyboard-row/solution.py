class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        row1 = set("qwertyuiop")
        row2 = set("asdfghjkl")
        row3 = set("zxcvbnm")
        result = []
        for i in words:
            r1 = r2 = r3 = 1
            for j in i.lower():
                if not (r1 or r2 or r3):
                    break
                if j not in row1:
                    r1 = 0
                if j not in row2:
                    r2 = 0
                if j not in row3:
                    r3 = 0
            if (r1 or r2 or r3):
                result.append(i)
        return result



        
