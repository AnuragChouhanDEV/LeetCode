// https://leetcode.com/problems/remove-linked-list-elements

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
    void del_node(ListNode* pos)
    {
        if (pos == NULL)
            return;
        else {
            if (pos->next == NULL) {
                delete pos;
                return;
            }
            ListNode* temp = pos->next;
            pos->val = pos->next->val;
            pos->next = pos->next->next;
            delete temp;
        }
    }
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *curr = head;
        while(curr) {
            if (curr->next && curr->next->val == val) {
                if (curr->next->next == NULL) {
                    delete curr->next;
                    curr->next = NULL;
                    break;
                } 
            } else if (curr->val == val)
                del_node(curr);
            curr = curr->next;
        }
        return head;
    }
};