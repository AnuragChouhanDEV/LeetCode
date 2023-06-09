// https://leetcode.com/problems/odd-even-linked-list

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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;
        ListNode* curr = head;
        ListNode* new_head = curr->next;
        ListNode* new_curr = new_head;
        while (curr && new_curr && new_curr->next) {
            curr->next = curr->next->next;
            new_curr->next = new_curr->next->next;
            curr = curr->next;
            new_curr = new_curr->next;
        }
        curr->next = new_head;
        return head;
    }
};