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
    int length(ListNode *head) {
        if (!head)
            return 0;
        return 1+length(head->next);
    }
    
    ListNode* reverseKGroup_rec(ListNode* head, int k, int len) {
        ListNode *curr = head;
        ListNode *next;
        ListNode *prev = NULL;
        int i = 0;
        if (len < k)
            return head;
        while (curr && i < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            ++i;
        }
        if (next)
            head->next = reverseKGroup_rec(next, k, len-k);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = length(head);
        cout << len << endl;
        return reverseKGroup_rec(head, k, len);
    }
};