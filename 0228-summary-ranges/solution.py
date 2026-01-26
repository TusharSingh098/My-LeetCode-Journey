class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        length = len(nums)
        result = []
        i = 0

        while (i < length):
            j = i
            while (j + 1 < length and nums[j] + 1 == nums[j + 1]):
                j += 1

            if (j != i):
                result.append(f"{nums[i]}->{nums[j]}")
            else:
                result.append(str(nums[j]))
            
            i = j + 1
        return result

