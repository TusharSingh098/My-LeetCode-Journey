class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        if (s == goal):
            return True
        for _ in range(len(s) - 1):
            s = s[1:] + s[:1]
            if (s == goal):
                return True
        return False
