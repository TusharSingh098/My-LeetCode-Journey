class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        rows, cols, perimeter = len(grid), len(grid[0]), 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j]:
                    perimeter += 4
                    if i and grid[i-1][j]:
                        perimeter -= 2
                    if j and grid[i][j-1]:
                        perimeter -= 2
        return perimeter
