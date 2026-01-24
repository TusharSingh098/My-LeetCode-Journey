from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        result = ListNode()
        end = result
        while (head):
            end.next = head
            head = head.next
            end = end.next
            while (head and end.val == head.val):
                head = head.next
            else:
                end.next = None
        return result.next
            
        
