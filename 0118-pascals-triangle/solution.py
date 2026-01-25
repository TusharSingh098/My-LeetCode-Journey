class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        pscl_trngl = []
        for i in range(numRows):
            row = [1] * (i + 1)
            for j in range(1, i):
                row[j] = pscl_trngl[i-1][j-1] + pscl_trngl[i-1][j]
            pscl_trngl.append(row)
        return pscl_trngl

