// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list

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
    ListNode *reverse (ListNode *head) {
        ListNode *curr = head;
        ListNode *next = NULL;
        ListNode *prev = NULL;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode *sptr = head;
        ListNode *fptr = head;
        ListNode *prev;
        while (fptr && fptr->next) {
            prev = sptr;
            sptr = sptr->next;
            fptr = fptr->next->next;
        }
        prev->next = reverse(prev->next);
        ListNode *h1 = head;
        ListNode *h2 = prev->next;
        int maxsum = INT_MIN;
        while (h1 && h2) {
            maxsum = max(maxsum, h1->val + h2->val);
            h1 = h1->next;
            h2 = h2->next;
        }
        return maxsum;
    }
};