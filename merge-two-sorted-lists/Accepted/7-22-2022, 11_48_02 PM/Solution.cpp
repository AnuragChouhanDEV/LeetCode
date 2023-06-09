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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode *curr = &dummy;
        curr->next = NULL;
        while(1) {
            if (list1 == NULL) {
                curr->next = list2;
                break;
            }
            if (list2 == NULL) {
                curr->next = list1;
                break;
            }
            if (list1->val < list2->val) {
                ListNode *tmp = list1;
                list1 = list1->next;
                tmp->next = curr->next;
                curr->next = tmp;
            } else {
                ListNode *tmp = list2;
                list2 = list2->next;
                tmp->next = curr->next;
                curr->next = tmp;
            }
            curr = curr->next;
        }
        return dummy.next;
#if 0
        ListNode *curr = NULL;
        if (list2 == NULL)
            return list1;
        else if (list1 == NULL)
            return list2;
        if (list1->val >= list2->val) {
            curr = list2;
            curr->next = mergeTwoLists(list1, list2->next);
        } else {
            curr = list1;
            curr->next = mergeTwoLists(list1->next, list2);
        }
        return curr;
#endif
    }
};