class Solution:
    def shortestToChar(self, s: str, c: str) -> List[int]:
        n = len(s)
        distances = [0] * n
        prev_idx = -float('inf') 
        for i in range(n):
            if s[i] == c:
                prev_idx = i
            distances[i] = i - prev_idx
        
        prev_idx = float('inf') 
        for i in range(n - 1, -1, -1):
            if s[i] == c:
                prev_idx = i
            distances[i] = min(distances[i], prev_idx - i)
            
        return distances

