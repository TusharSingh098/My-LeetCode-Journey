class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        mapping = {}
        for i in range(len(t)):
            if (s[i] not in mapping):
                if t[i] in mapping.values():
                    return False
                mapping[s[i]] = t[i]
            else:
                if (mapping[s[i]] != t[i]):
                    return False
        return True

        
