// https://leetcode.com/problems/insertion-sort-list

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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* tmp = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* node = NULL;
        if (tmp == NULL) {
            return NULL;
        }
        if (tmp->next == NULL) {
            return tmp;
        }
        while (!tmp->next) {
            if (tmp->val <= tmp->next->val)
                tmp = tmp->next;
            else {
                node = tmp->next;
                prev = tmp;
                tmp = tmp->next;
                next = tmp->next;
            }
        }
    }
};