// https://leetcode.com/problems/reverse-nodes-in-k-group

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
    ListNode* helper(ListNode* head, int k, int nodeleft) {
        if (!head)
            return NULL;
        if (nodeleft < k)
            return head;
        ListNode* curr = head;
        ListNode* next = NULL;
        ListNode* prev = NULL;
        int i = 0;
        while (i < k && curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            ++i;
        }
        if (next)
            head->next = helper(next, k, nodeleft-k);
        return prev;
    }
    int length(ListNode *head) {
        int len = 0;
        ListNode *tmp = head;
        while(tmp) {
            len++;
            tmp = tmp->next;
        }
        return len;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = length(head);
        head = helper(head, k, len);
        return head;
    }
};