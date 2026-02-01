class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        next_map = {}
        stack = []
        
        for num in nums2:
            while stack and num > stack[-1]:
                next_map[stack.pop()] = num
            stack.append(num)
            
        while stack:
            next_map[stack.pop()] = -1
            
        return [next_map[i] for i in nums1]

