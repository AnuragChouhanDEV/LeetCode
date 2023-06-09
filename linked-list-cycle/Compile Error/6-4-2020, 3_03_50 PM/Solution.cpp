// https://leetcode.com/problems/linked-list-cycle

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
    if (head == null || head->next == null) {
        return false;
    }
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (slow != fast) {
        if (fast == null || fast->next == null) {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
    }
};