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
    ListNode* merge(ListNode* leftH, ListNode* rightH)
    {
        ListNode dummy(0);
        ListNode* tail{&dummy};

        while (leftH != nullptr && rightH != nullptr)
        {
            if (leftH->val <= rightH->val)
            {
                tail->next = leftH;
                leftH = leftH->next;
            }
            else
            {
                tail->next = rightH;
                rightH = rightH->next;
            }
            tail = tail->next;
        }
        if (leftH != nullptr) tail->next = leftH;
        else tail->next = rightH;

        return dummy.next;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *prev{nullptr}, *slow{head}, *fast{head};
        while (fast != nullptr && fast->next != nullptr)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;

        ListNode *leftSide{sortList(head)}, *rightSide{sortList(slow)};

        return merge(leftSide, rightSide);
    }
};
