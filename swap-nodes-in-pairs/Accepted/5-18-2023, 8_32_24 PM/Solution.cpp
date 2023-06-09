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
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head) return NULL;
        const static int pair = 2;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        int i = 0;
        while (curr && i < pair) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            ++i;
        }
        if (next)
            head->next = swapPairs(next);
        return prev;
    }
};