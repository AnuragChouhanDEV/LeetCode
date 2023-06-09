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
        if (!head || !head->next)
            return NULL;
        ListNode *sp = head;
        ListNode *fp = head->next;
        while (fp && fp->next) {
            if (sp == fp)
                break;
            sp = sp->next;
            fp = fp->next->next;
        }
        if (fp && fp->next)
            return NULL;
        sp = head;
        while (fp->next != sp) {
            fp = fp->next;
            sp = sp->next;
        }
        return fp->next;
    }
};