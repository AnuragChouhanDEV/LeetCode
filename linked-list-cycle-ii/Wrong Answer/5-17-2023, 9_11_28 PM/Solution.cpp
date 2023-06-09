// https://leetcode.com/problems/linked-list-cycle-ii

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;
        ListNode *sptr = head;
        ListNode *fptr = head->next;
        ListNode *prev = NULL;
        if (head == head->next) return head;
        while (fptr && fptr->next) {
            if (sptr == fptr) return prev;
            prev = sptr;
            sptr = sptr->next;
            fptr = fptr->next->next;
        }
        return prev;
    }
};