// https://leetcode.com/problems/rotate-list

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
    ListNode* rotateRight(ListNode* head, int k) {
        start:
        ListNode *sp = head;
        ListNode *fp = head;
        while (sp && k--) {
            sp = sp->next;
        }
        if (!sp)
            goto start;
        //cout << sp->val << endl;
        while (sp->next) {
            sp = sp->next;
            fp = fp->next;
        }
        //cout << fp->val << endl;
        ListNode *new_head = sp = fp->next;
        fp->next = NULL;
        while (sp->next) {
            sp = sp->next;
        }
        sp->next = head;
        return new_head;
    }
};