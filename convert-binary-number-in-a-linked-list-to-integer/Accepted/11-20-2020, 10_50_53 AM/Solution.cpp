// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer

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
    int itr;
    int sol;
    static int power(int x, int y) 
    { 
        if (y == 0) 
            return 1; 
        else if (y % 2 == 0) 
            return power(x, y / 2) * power(x, y / 2); 
        else
            return x * power(x, y / 2) * power(x, y / 2); 
    }
    int getDecimalValue_int(ListNode* head) {
        if (head->next == NULL) {
            return head->val * pow(2, itr);
        }
        sol += getDecimalValue_int(head->next);
        
        itr++;
        return head->val * pow(2, itr);
    }
    
public:
    int getDecimalValue(ListNode* head) {
        if (head == NULL)
            return 0;
        sol += getDecimalValue_int(head);
        return sol;
    }
};