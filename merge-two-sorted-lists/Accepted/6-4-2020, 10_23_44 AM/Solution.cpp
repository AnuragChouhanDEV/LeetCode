// https://leetcode.com/problems/merge-two-sorted-lists

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode tmp;
        ListNode *res = &tmp;
        while(l1 && l2) {
            
            if (l1->val < l2->val) {
                res->next = l1;
                l1 = l1->next;
                res = res->next;
               // cout << l1->val << endl;
            } else {
               // cout << l2->val << endl;
                res->next = l2;
                l2= l2->next;
                res = res->next;
                
            }
        }
        while (l1) {
            res->next = l1;
            l1 = l1->next;
            res = res->next;
        }
        while (l2) {
            res->next = l2;
            l2= l2->next;
            res = res->next;
        }
        return tmp.next;
              
    }
};