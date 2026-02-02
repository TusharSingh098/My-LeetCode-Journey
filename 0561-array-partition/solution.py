import numpy as np
class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        return int(np.sum(np.sort(np.array(nums))[::2]))
