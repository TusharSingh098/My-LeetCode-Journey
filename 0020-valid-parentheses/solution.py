class Solution:
    def isValid(self, s: str) -> bool:
        map = {")": "(", "}": "{", "]": "["}
        stk = []
        for i in s:
            if (i == '(' or i == '{' or i == '['):
                stk.append(i)
                continue
            if (not stk) or (stk.pop() != map[i]):
                return False
        return not stk
