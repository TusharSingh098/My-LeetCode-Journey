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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry{0};
        ListNode *n1{l1}, *n2{l2}, *prev;

        while (n1 != nullptr && n2 != nullptr)
        {
            int sum{n1->val + n2->val + carry};
            carry = sum / 10;
            n1->val = sum % 10;

            prev = n1;
            n1 = n1->next, n2 = n2->next;
        }
        if (n1 == nullptr && n2 != nullptr) 
        {
            prev->next = n2;
            n1 = n2;
        }
        while (carry != 0 && n1 != nullptr)
        {
            int sum{n1->val + carry};
            carry = sum / 10;
            n1->val = sum % 10;

            prev = n1;
            n1 = n1->next;
        }

        if (carry != 0)
        {
            ListNode* newtail{new ListNode(carry)};
            prev->next = newtail;
            return l1;
        }

        return l1;
    }
};
