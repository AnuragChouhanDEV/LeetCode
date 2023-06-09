// https://leetcode.com/problems/palindrome-linked-list

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
    bool isPalindrome(ListNode* head) {
        stack<ListNode *> st;
        ListNode *first = head;
        ListNode *second = head;

        while (first && first->next) {
            st.push(second);
            second = second->next;
            first = first->next->next;
        }
        if (first && !first->next)
            second = second->next;
        while (!st.empty() && second) {
            ListNode *tmp = st.top();
            st.pop();
            if (tmp->val != second->val)
                return false;
            second = second->next;
        }
        if (st.empty() && second == NULL)
            return true;
        return false;
    }
};