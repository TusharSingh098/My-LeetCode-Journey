class Solution:
    def shortestToChar(self, s: str, c: str) -> List[int]:
        idxs = []
        for i in range(len(s)):
            if (s[i] == c):
                idxs.append(i)
        distances = []
        for i in range(len(s)):
            distances.append(min(abs(i - j) for j in idxs))
        return distances
