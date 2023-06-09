// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node *_flatten(Node *head) {
        if (!head)
            return NULL;
        Node *tail = head;
        Node *curr = head;
        while(curr) {
            Node *next = curr->next;
            Node *child = curr->child;
            if (child) {
                Node *_tail = _flatten(child);
                _tail->next = next;
                if (next)
                    next->prev = _tail;
                curr->next = child;
                child->prev = curr;
                curr->child = NULL;
                curr = _tail;
            } else {
                curr = next;
            }
            if (curr)
                tail = curr;
        }
        return tail;
    }
    Node* flatten(Node* head) {
        if (head) _flatten(head);
        return head;
    }
};