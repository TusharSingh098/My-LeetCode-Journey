class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        groups = s.replace('01', '0 1').replace('10', '1 0').split()
        
        lengths = [len(g) for g in groups]
        
        return sum(min(a, b) for a, b in zip(lengths, lengths[1:]))

