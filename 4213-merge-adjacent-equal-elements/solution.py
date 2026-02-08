class Solution:
    def mergeAdjacent(self, nums: List[int]) -> List[int]:
        while True:
            i = 1
            added = False
            while (i < len(nums)):
                while (i > 0) and (i < len(nums)) and (nums[i] == nums[i - 1]):
                    nums[i - 1: i + 1] = [2 * nums[i]]
                    i -= 1
                    added = True
                i += 1

            if not added:
                break

        return nums
        
