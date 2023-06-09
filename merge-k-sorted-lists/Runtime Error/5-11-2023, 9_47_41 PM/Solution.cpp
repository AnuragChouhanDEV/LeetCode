// https://leetcode.com/problems/merge-k-sorted-lists

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
    ListNode *reverse(ListNode *head) {
        if (!head)
            return head;
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *next;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return NULL;
        auto cmp = [](ListNode*a,ListNode*b){return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>,decltype(cmp)> pq(cmp);
        for (auto it:lists)
            if (it) pq.push(it);
        ListNode* head = pq.top();
        pq.pop();
        if (head->next)
            pq.push(head->next);
        ListNode *curr = head;
        while (!pq.empty()) {
            ListNode *tmp = pq.top();
            pq.pop();
            curr->next = tmp;
            curr = tmp;
            if (tmp->next)
                pq.push(tmp->next);
        }
        return head;
    }
};