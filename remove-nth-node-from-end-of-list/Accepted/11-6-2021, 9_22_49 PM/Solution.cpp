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
        ListNode* prev = head;
        ListNode* slow = head;
        ListNode* fast = head;
        int  t = n;
           
        while (fast && t--) {
            //cout << fast->val << endl;
            fast = fast->next;
        }
        if (n == 1 && fast == NULL) {
            delete head;
            return NULL;
        }
        if (fast == NULL) {
            ListNode *temp = slow;
            head = slow->next;
            delete temp;
            return head;
        }
        //cout <<  fast->val << endl;
        while (fast) {
            //cout << fast->val << endl;
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