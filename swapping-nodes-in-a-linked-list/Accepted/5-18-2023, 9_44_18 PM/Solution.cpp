// https://leetcode.com/problems/swapping-nodes-in-a-linked-list

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

    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* sptr = head;
        ListNode* fptr = head;
        int i = 1;
        while (i < k && fptr) {

            fptr = fptr->next;
            ++i;
        }
        ListNode* first = fptr;
        while (fptr->next) {
            sptr = sptr->next;
            fptr = fptr->next;
        }
        swap(sptr->val, first->val);
        return head;
    }
};