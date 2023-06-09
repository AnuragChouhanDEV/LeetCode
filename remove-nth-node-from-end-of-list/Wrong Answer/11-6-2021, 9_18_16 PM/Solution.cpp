// https://leetcode.com/problems/remove-nth-node-from-end-of-list

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head)
            return head;
        if (head->next == NULL && n == 1) {
            delete(head);
            return NULL;
        }
        ListNode *prev = NULL;
        ListNode *first = head;
        ListNode *second = head;
        while (first && n--) {
            first = first->next;
        }
        if (first == NULL && !n)
            return head;
        while (first) {
            prev = second;
            second = second->next;
            first = first->next;
        }
        ListNode *tmp = second;
        prev->next = second->next;
        delete(tmp);
        return head;
    }
};