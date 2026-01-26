class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        curr = head
        
        while curr:
            temp_next = curr.next  # 1. Save the next node
            curr.next = prev       # 2. Reverse the pointer
            prev = curr            # 3. Move prev forward
            curr = temp_next       # 4. Move curr forward
            
        return prev  # prev will be the new head

