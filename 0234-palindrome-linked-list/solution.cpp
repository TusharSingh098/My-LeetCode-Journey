/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* reverseLL(ListNode* head)
    {
        if (head->next == nullptr) return head;

        ListNode *curr{head}, *prev{nullptr};
        
        while (curr != nullptr)
        {
            ListNode *temp{curr->next};
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if (head->next == nullptr) return true;

        ListNode *ptr1{head}, *ptr2{head};
        while (ptr2 != nullptr && ptr2->next != nullptr)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
        }

        if (ptr2 == nullptr) ptr1 = reverseLL(ptr1);
        else ptr1 = reverseLL(ptr1->next);
        ptr2 = head;

        while (ptr1 != nullptr && ptr2 != nullptr)
        {
            if (ptr1->val != ptr2->val) return false;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return true;
    }
};
