class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        lengths = []
        count = 1
        for i in range(len(nums) - 1):
            if (nums[i + 1] > nums[i]):
                count += 1
            else:
                lengths.append(count)
                count = 1
        else:
            lengths.append(count)
        return max(lengths)
