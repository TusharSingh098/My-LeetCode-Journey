# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        result = ListNode()
        end = result
        while head:
            if (head.val != val):
                end.next = head
                end = end.next
            head = head.next
        
        end.next = None
        return result.next
            

        
