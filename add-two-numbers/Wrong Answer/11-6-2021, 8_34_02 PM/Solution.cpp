// https://leetcode.com/problems/add-two-numbers

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
    struct ListNode *Node (int x) {
        struct ListNode *new_node = new ListNode;
        new_node->val = x;
        new_node->next = NULL;
        return new_node;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode head = ListNode();
        ListNode *curr = &head;
        while(l1 && l2) {
            curr->next = Node(l1->val + l2->val + carry);
            curr = curr->next;
            if (curr->val >= 10) {
                curr->val = curr->val - 10;
                carry = 1;
            } else {
                carry = 0;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            curr->next = Node(l1->val + carry);
            carry = 0;
            curr = curr->next;
            l1 = l1->next;
        }
        while (l2) {
            curr->next = Node(l2->val + carry);
            carry = 0;
            curr = curr->next;
            l2 = l2->next;
        }
        return head.next;
    }
};