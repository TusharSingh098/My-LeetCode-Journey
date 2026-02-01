class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        length = len(nums) + 1
        s = [0] * (length)
        ans = []
        for x in nums:
            if not s[x]:
                s[x] = 1

        for i in range(1, length):
            if not s[i]:
                ans.append(i)
            
        return ans
