class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        str1 = str2 = ""
        for i in s:
            if (i == "#"):
                str1 = str1[:-1]
            else:
                str1 += i

        for i in t:
            if (i == "#"):
                str2 = str2[:-1]
            else:
                str2 += i

        return str1 == str2
