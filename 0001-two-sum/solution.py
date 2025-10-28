class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        complement_map = {} 
        for i in range(len(nums)):
            current_num = nums[i]
            complement = target - current_num
            if complement in complement_map:
                return [complement_map[complement], i]
            complement_map[current_num] = i
        return []
