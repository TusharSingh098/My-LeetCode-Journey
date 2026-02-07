class Solution:
    def toLowerCase(self, s: str) -> str:
        result = ""
        for i in s:
            if (i >= "A") and (i <= "Z"):
                result += chr(ord(i) + 32)
            else:
                result += i
        return result
