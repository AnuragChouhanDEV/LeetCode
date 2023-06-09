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
    int len(ListNode *head) {
        ListNode* tmp = head;
        int count = 0;
        while (tmp) {
            count++;
            tmp = tmp->next;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* first = head;
        ListNode* second = head;
        ListNode* prev = NULL;
        ListNode* prev_s = NULL;
        int i = 0;
        int l = len(head);
        if (k == 0)
            return head;
        if (k > l) {
            k = k%l;
        }
        while (i < k && first) {
            first = first->next;
            ++i;
        }
        while (first) {
            prev = first;
            first = first->next;
            prev_s = second;
            second = second->next;
        }
        if (prev)
            prev->next = head;
        if (prev_s)
            prev_s->next = NULL;
        head = second;
        return head;
    }
};