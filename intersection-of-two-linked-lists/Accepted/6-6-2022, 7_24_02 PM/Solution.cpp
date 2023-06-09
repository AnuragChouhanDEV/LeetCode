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
    int get_length(ListNode *head) {
        int len = 0;
        while(head) {
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = get_length(headA);
        int lenB = get_length(headB);
        int len = abs(lenA - lenB);
        ListNode *head1 = NULL;
        ListNode *head2 = NULL;
        if (lenA > lenB) {
            head1 = headA;
            head2 = headB;
        } else {
            head1 = headB;
            head2 = headA;
        }
        while(len) {
            head1 = head1->next;
            len--;
        }
        while (head1 != head2) {
            head1 = head1->next;
            head2 = head2->next;
        }
        return head1;
    }
};