import numpy as np

class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        a = np.sort(np.array(arr))
        diff_a = np.diff(a)
        min_abs = np.min(diff_a)

        inds, = np.where(diff_a == min_abs)
        
        res = []
        for i in inds:
            res.append([int(a[i]), int(a[i+1])])

        return res
