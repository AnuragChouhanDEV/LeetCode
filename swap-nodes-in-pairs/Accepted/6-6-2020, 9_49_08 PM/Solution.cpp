// https://leetcode.com/problems/swap-nodes-in-pairs

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
    void swap_pairs(ListNode* head) {
        if (head != NULL && head->next != NULL) {
            swap(head->val, head->next->val);
            swap_pairs(head->next->next);
        }
            
    }
public:
    ListNode* swapPairs(ListNode* head) {
        swap_pairs(head);
        return head;
    }
};