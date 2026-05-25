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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        ListNode* tail{&dummy};
        ListNode* ptr1{head}, *ptr2{head};
        int n{1};
        while (ptr1 != nullptr)
        {
            while (n < k && ptr2->next != nullptr) 
            {
                ptr2 = ptr2->next;
                n++;
            }
            ListNode* temp{ptr2->next};
            ptr2->next = nullptr;
                
            ListNode* oldptr1{ptr1};
            if (n == k) 
            {
                ptr1 = reverseList(ptr1);
                tail->next = ptr1;
                tail = oldptr1;
            }
            else
            {
                tail->next = ptr1;
                while (tail->next != nullptr) tail = tail->next;
            }
            
            ptr1 = ptr2 = temp;
            n = 1;
        }
        return dummy.next;
    }
};
