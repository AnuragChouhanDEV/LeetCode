// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list

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
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) return NULL;
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *fp = head;
        while (fp && fp->next) {
            prev = curr;
            curr = curr->next;
            fp = fp->next->next;
        }
        
            if (prev) {
                ListNode *next = prev->next->next;
                prev->next = next;
            } 
        
        return head;
    }
};