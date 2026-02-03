class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        if (r * c != len(mat) * len(mat[0])):
            return mat
        
        result = [mat[i][j] for i in range(len(mat)) for j in range(len(mat[0]))]
        return [[result[j] for j in range(c * i, c * (i + 1))] for i in range(r)]


        


        
        
