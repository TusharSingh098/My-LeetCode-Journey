class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        size = len(nums)
        if not size:
            return None
        def build_subtree(left: int, right: int) -> Optional[TreeNode]:
            if left > right:
                return None
            
            mid = (left + right) >> 1
            node = TreeNode(nums[mid])

            node.left = build_subtree(left, mid - 1)
            node.right = build_subtree(mid + 1, right)
            
            return node
            
        return build_subtree(0, len(nums) - 1)
