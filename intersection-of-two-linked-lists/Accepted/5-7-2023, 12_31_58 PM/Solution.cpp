// https://leetcode.com/problems/intersection-of-two-linked-lists

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
    int length(ListNode *head) {
        int len = 0;
        ListNode *tmp = head;
        while(tmp) {
            len++;
            tmp = tmp->next;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = length(headA);
        int l2 = length(headB);
        int el;
        ListNode *t1 = headA;
        ListNode *t2 = headB;
        if (l1 > l2) {
            el = l1-l2;
            while (el) {
                t1 = t1->next;
                el--;
            }
        } else {
            el = l2-l1;
            while (el) {
                t2 = t2->next;
                el--;
            }
        }
        while (t1 && t2) {
            if (t1 == t2)
                return t1;
            t1 = t1->next;
            t2 = t2->next;
        }
        return NULL;
    }
};