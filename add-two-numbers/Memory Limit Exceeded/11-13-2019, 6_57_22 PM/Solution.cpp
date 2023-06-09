// https://leetcode.com/problems/add-two-numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL)
            return NULL;
        else if (l1 == NULL && l2 != NULL)
            return l2;
        else if (l1 != NULL && l2 == NULL)
            return l1;
        int sum, carry = 0;
        sum = l1->val + l2->val + carry;
        carry = sum/10;
        sum = sum%10;
        ListNode *head = new ListNode(sum);
        ListNode *temp = head;
        l1 = l1->next;
        l2 = l2->next;
        
        if (l1 == NULL && l2 == NULL && carry) {
            ListNode *new_node = new ListNode(carry);
            temp->next = new_node;
            temp = temp->next;
        }
        while (l1 != NULL && l2 != NULL) {
            sum = l1->val + l2->val + carry;
            carry = sum/10;
            sum = sum%10;
            ListNode *new_node = new ListNode(sum);
            temp->next = new_node;
            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;        
        }
        while ((l1 == NULL && l2 != NULL) || (l1 != NULL && l2 == NULL)) {
            if (l1 == NULL)
                l1 = l2;
            if (l1 == NULL)
                break;
            sum = l1->val + carry;
            carry = sum/10;
            sum = sum%10;
            ListNode *new_node = new ListNode(sum);
            temp->next = new_node;
            temp = temp->next;
            l1 = l1->next;        
        }
        return head;
    }
};