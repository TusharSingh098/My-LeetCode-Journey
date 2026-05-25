/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        Node* tailOld{head};
        
        while (tailOld != NULL)
        {
            Node* newNode{new Node(tailOld->val)};
            Node* temp{tailOld->next};
            tailOld->next = newNode;
            newNode->next = temp;
            tailOld = temp;
        }

        tailOld = head;
        while (tailOld != NULL)
        {
            if (tailOld->random != nullptr) 
            {
                tailOld->next->random = tailOld->random->next;
            }
            tailOld = tailOld->next->next;
        }

        tailOld = head;
        Node *newHead{head->next}, *tailNew{newHead};
        while (tailOld != NULL)
        {
            tailOld->next = tailOld->next->next;
            tailOld = tailOld->next;
            if (tailNew->next != nullptr) 
            {
                tailNew->next = tailNew->next->next;
                tailNew = tailNew->next;
            }
        }

        return newHead;

    }
};
