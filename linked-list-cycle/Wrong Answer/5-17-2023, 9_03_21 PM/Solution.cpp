// https://leetcode.com/problems/linked-list-cycle

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
    bool hasCycle(ListNode *head) {
        if (!head)
            return true;
        ListNode *sptr = head;
        ListNode *fptr = head->next;
        while (fptr && fptr->next) {
            if (sptr == fptr)
                return true;
            sptr = sptr->next;
            fptr = fptr->next->next;
        }
        return false;
    }
};