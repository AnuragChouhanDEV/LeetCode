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
        if (!head)
            return head;
        Node *curr = head;
        Node *next;
        Node *copy;
        while(curr) {
            next = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = next;
            curr = curr->next->next;
        }
        curr = head;
        while(curr) {
            curr->next->random = curr->random ? curr->random->next : NULL;
            curr = curr->next->next;
        }
        curr = head;
        copy = curr->next;
        while(curr && curr->next) {
            next = curr->next;
            curr->next = next->next;
            curr = curr->next;
            if (next && curr)
                next->next = curr->next;
        }
#if 0
        curr = copy;
        while(curr) {
            cout << curr->val << " ";
            curr = curr->next;
        }
#endif
        return copy;
    }
};