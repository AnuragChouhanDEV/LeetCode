// https://leetcode.com/problems/reverse-linked-list

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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* rest = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return rest;
/*
        ListNode* tmp = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while (tmp) {
            next = tmp->next;
            tmp->next = prev;
            //next->next = tmp;
            prev = tmp;
            tmp = next;
        }
        return prev;
*/
    }
};