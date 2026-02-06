class Solution:
    def judgeCircle(self, moves: str) -> bool:
        # faster bcz .count() is implemented in c
        return moves.count('U') == moves.count('D') and moves.count('L') == moves.count('R')
