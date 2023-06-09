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
    int length(ListNode* head) {
        int len = 0;
        ListNode *tmp = head;
        while (tmp) {
            len++;
            tmp = tmp->next;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i = 0;
        ListNode* first = head;
        //ListNode* second = head;
        ListNode* prev = NULL;
        int len = length(head);
        if (n == len)
            return head->next;
        n = len - n;
        while (first && i < n) {
            prev = first;
            first = first->next;
            ++i;
        }
        if (prev)
            prev->next = first->next;
        
        
        return head;
    }
};