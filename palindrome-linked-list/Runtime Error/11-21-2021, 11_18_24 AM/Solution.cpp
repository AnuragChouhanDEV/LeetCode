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
        ListNode *sp = head;
        ListNode *fp = head;
        while(fp && fp->next) {
            st.push(sp);
            sp = sp->next;
            fp = fp->next->next;
        }
        if (fp) {
            //cout << "popped here " << endl;
            st.pop();
        }
        while (sp) {
            if (!st.empty()) {
                if (sp->val != st.top()->val) {
                    //cout << sp->val << " " << st.top()->val << endl;
                    return false;
                }
            }
            st.pop();
            sp = sp->next;
        }
        return true;
    }
};