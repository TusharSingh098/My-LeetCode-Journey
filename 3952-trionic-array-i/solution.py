class Solution:
    def isTrionic(self, nums: List[int]) -> bool:
        length = len(nums)
        i = 0
        while (i < length - 1) and (nums[i] < nums[i + 1]):
            i += 1
        j = i
        while (j < length - 1) and (nums[j] > nums[j + 1]):
            j += 1
        k = j
        while (k < length - 1) and (nums[k] < nums[k + 1]):
            k += 1
        if (k == length - 1) and (0 < i) and (i < j) and (j < k):
            return True
        return False
