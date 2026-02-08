class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        return max(abs(a1 * (b2 - c2) + b1 * (c2 - a2) + c1 * (a2 - b2)) / 2 for (a1, a2), (b1, b2), (c1, c2) in combinations(points, 3))
