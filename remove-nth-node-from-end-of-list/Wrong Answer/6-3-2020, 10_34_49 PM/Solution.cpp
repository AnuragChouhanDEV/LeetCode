// https://leetcode.com/problems/remove-nth-node-from-end-of-list

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev;
        ListNode* slow = head;
        ListNode* fast = head;
        if (n == 1) {
            delete head;
            return NULL;
        }
            
        while (fast && n--) {
            fast = fast->next;
        }
        while (fast) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode *temp = prev->next;
        prev->next = slow->next;
        delete temp;
        return head;
    }
};