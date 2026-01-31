class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        def build_map(num:List[int]) -> {int}:
            res = {}
            for i in num:
                res[i] = res.get(i,0) + 1
            return res

        mapping = build_map(nums1)
        result = []
        for i in nums2:
            if i in mapping and mapping[i] > 0:
                result.append(i)
                mapping[i] -= 1

        return result
                
                
