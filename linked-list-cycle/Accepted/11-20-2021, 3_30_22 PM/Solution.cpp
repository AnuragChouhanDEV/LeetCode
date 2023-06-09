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
            return false;
        ListNode *sp = head;
        ListNode *fp = head->next;
        while (fp && fp->next) {
            if (sp == fp)
                return true;
            sp = sp->next;
            fp = fp->next->next;
        }
        return false;
    }
};