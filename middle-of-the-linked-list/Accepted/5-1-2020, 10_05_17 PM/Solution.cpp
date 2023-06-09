// https://leetcode.com/problems/middle-of-the-linked-list

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
    ListNode* middleNode(ListNode* head) {
        struct ListNode *fastptr = head;
        struct ListNode *slowptr = head;
        
        while (fastptr != NULL && fastptr->next != NULL) {
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }
        return slowptr;
        
    }
};