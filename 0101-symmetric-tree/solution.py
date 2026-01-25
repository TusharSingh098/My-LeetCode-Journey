from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if not (p or q):
            return True
        elif (not p and q):
            return False
        elif (p and not q):
            return False
        elif (p.val != q.val):
            return False
        else:
            return self.isSameTree(p.left, q.right) and self.isSameTree(p.right, q.left)
        
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if root:
            return self.isSameTree(root.left, root.right)
        else:
            return False
