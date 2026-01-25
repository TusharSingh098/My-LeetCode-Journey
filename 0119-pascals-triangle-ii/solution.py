def factorial(num):
    if num == 0 or num == 1:
        return 1
    else:
        result = 1
        for i in range(2, num + 1):
            result *= i
        return result

def combinations(n_fact, n, r):
    if r < 0 or r > n:
        return 0

    r_fact = factorial(r)
    n_minus_r_fact = factorial(n - r)
    
    result = n_fact // (r_fact * n_minus_r_fact)
    return result


class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        pscl_trngl = []
        for i in range(rowIndex + 1):
            row = [1] * (i + 1)
            for j in range(1, i):
                row[j] = pscl_trngl[i-1][j-1] + pscl_trngl[i-1][j]
            pscl_trngl.append(row)
        return pscl_trngl[rowIndex]

