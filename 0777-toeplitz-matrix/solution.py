class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        # Every row (except the last) must match the row below it (shifted)
        for i in range(len(matrix) - 1):
            # Row i from index 0 to end-1 must match Row i+1 from index 1 to end
            if matrix[i][:-1] != matrix[i+1][1:]:
                return False
        return True

