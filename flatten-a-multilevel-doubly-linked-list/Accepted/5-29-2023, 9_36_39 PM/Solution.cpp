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
    Node* flatten(Node* head) {
        stack<Node *> st;
        Node *curr = head;
        Node *tail;
        
        while (curr) {
            if (curr->child) {
                if (curr->next != NULL) {
                    curr->next->prev = NULL;
                    st.push(curr->next);
                }
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = NULL;
            }
            tail = curr;
            curr = curr->next;
        }
        while(!st.empty()) {
            curr = st.top();
            tail->next = curr;
            curr->prev = tail;
            st.pop();
            while (curr) {
                tail = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};