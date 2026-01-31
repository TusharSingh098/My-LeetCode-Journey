class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        lst_s = s.split()
        if (len(lst_s) != len(pattern)):
            return False
        mapping = {}
        idx = 0
        for i in lst_s:
            if i not in mapping:
                if pattern[idx] in set(mapping.values()):
                    return False
                mapping[i] = pattern[idx]
            else:
                if mapping[i] != pattern[idx]:
                    return False
            idx += 1
        return True
