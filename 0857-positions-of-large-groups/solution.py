class Solution:
    def largeGroupPositions(self, s: str) -> List[List[int]]:
        start = end = 0
        groups = []
        for i in range(len(s) - 1):
            if (s[i] == s[i + 1]):
                end += 1
            else:
                if (end - start + 1 >= 3):
                    groups.append([start, end])
                start = end = i + 1
        if (end - start + 1 >= 3):
            groups.append([start, end])
        return groups
