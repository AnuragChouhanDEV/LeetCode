// https://leetcode.com/problems/copy-list-with-random-pointer

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
        if (!head) return head;
        Node *curr = head;
        while (curr) {
            Node *next = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = next;
            curr = curr->next->next;
        }
        curr = head;
        while (curr) {
            Node *next = curr->next;
            next->random = curr->random ? curr->random->next:NULL;
            curr = curr->next->next;
        }
        curr = head;
        Node* clonedHead = head->next;
        Node* clonedCurr = clonedHead;
        while (clonedCurr->next != NULL) {
            curr->next = curr->next->next;
            clonedCurr->next = clonedCurr->next->next;
            curr = curr->next;
            clonedCurr = clonedCurr->next;
        }
        curr->next = NULL;
        clonedCurr->next = NULL;
     
        return clonedHead;
/*
        while (curr) {
            cout << " " << curr->val;
            curr = curr->next;
        }
*/

    }
};