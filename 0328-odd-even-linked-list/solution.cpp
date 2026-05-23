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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) return head;

        ListNode *eveHead{head->next};
        ListNode *odd{head}, *eve{head->next};

        while (eve != nullptr && eve->next != nullptr)
        {
            odd->next = odd->next->next;
            eve->next = eve->next->next;
            odd = odd->next;
            eve = eve->next;
        }
        odd->next = eveHead;
        return head;
    }
};
