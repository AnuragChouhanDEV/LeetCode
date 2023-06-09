// https://leetcode.com/problems/reorder-list

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
    int length(ListNode* head) {
        int len = 0;
        ListNode* tmp = head;
        while (tmp) {
            len++;
            tmp = tmp->next;
        }
        return len;
    } 
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        int len = length(head);
        int itr = len/2;
        ListNode* tmp = head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while (tmp) {
            if (itr) {
                itr--;
                prev = tmp;
                tmp = tmp->next;
                continue;
            }
            st.push(tmp);
            tmp = tmp->next;
        }
        prev->next = NULL;
        while (curr && !st.empty()) {
            next = curr->next;
            ListNode* tmp = st.top();
            st.pop();
            curr->next = tmp;
            tmp->next = next;
            if (!next)
                prev = tmp;
            curr = next;
        }
        if (!st.empty()) {
            ListNode* tmp = st.top();
            st.pop();
            tmp->next = NULL;
            prev->next = tmp;
        }
    }
};