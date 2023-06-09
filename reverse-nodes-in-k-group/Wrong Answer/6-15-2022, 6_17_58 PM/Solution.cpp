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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *curr = head;
        ListNode *next;
        ListNode *prev = NULL;
        int i = 0;
        while (curr && i < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            ++i;
        }
        if (next)
            head->next = reverseKGroup(next, k);
        return prev;        
    }
};