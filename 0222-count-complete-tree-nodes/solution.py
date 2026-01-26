# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def countLeftNodes(node: TreeNode):
    if node:
        return 1 + countLeftNodes(node.left) + countRightNodes(node.right)
    else:
        return 0
def countRightNodes(node: TreeNode):
    if node:
        return 1 + countRightNodes(node.right) + countLeftNodes(node.left)
    else:
        return 0
class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        if root:
            return 1 + countRightNodes(root.right) + countLeftNodes(root.left)
        else:
            return 0
        
        
