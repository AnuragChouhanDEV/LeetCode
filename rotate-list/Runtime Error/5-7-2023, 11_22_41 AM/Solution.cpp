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
    int length(ListNode* head) {
        int len = 0;
        ListNode* tmp = head;
        while (tmp) {
            len++;
            tmp = tmp->next;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int len = length(head);
        if(k == 0)
            return head;
        if (k > len)
            k = k % len;
        if (len == 0 || k == len)
            return head;
        int itr = len - k;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* kthnode = NULL;
        while(itr > 0 && curr) {
            prev = curr;
            curr = curr->next;
            --itr;
        }
        if (prev)
            prev->next = NULL;
        kthnode = curr;
        while (curr->next) {
            curr = curr->next;
        }
        if (curr)
            curr->next = head;
        head = kthnode;
        return head;
    }
};