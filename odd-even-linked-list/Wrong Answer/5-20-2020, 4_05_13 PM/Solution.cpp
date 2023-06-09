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
        ListNode *last = head;
        int count = 0;
        ListNode *tmp = head;
        while (last->next != NULL) {
            last = last->next;
            count++;
        }
        count = count%1 != 0 ? (count/2)+1:(count/2);
        while (count--) {
            last->next = tmp->next;
            tmp->next = tmp->next->next;
            last->next->next = NULL;
            tmp = tmp->next;
            last = last->next;
        }
        return head;
    }
};