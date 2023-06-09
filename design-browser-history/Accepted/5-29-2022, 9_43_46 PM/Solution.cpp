// https://leetcode.com/problems/design-browser-history

class BrowserHistory {
public:
    string str;
    BrowserHistory *next;
    BrowserHistory *prev;
    BrowserHistory *curr;
    BrowserHistory *head;
    int i = 0;
    BrowserHistory(string homepage) {
        this->str = homepage;
        this->next = NULL;
        this->prev = NULL;      
        if (i == 0) {
            head = this;
            curr = head;
            ++i;
        }
    }
    void deleteNode(BrowserHistory** head_ref, BrowserHistory* del)
    {
        if (*head_ref == NULL || del == NULL)
            return;
        if (*head_ref == del)
            *head_ref = del->next;
        if (del->next != NULL)
            del->next->prev = del->prev;
        if (del->prev != NULL)
            del->prev->next = del->next;
        //free(del);
        return;
    }
    void delete_all_nodes_after(BrowserHistory **head_ref) {
        BrowserHistory* ptr = *head_ref;
        BrowserHistory* next;
        while (ptr != NULL) {
            next = ptr->next;
            deleteNode(head_ref, ptr);
            ptr = next;
        }
    }
    void insert_after(BrowserHistory *curr1, string url) {
        if (curr1 == NULL)
            return;
        BrowserHistory* new_node = new BrowserHistory(url);
        new_node->next = curr1->next;
        curr1->next = new_node;
        new_node->prev = curr1;
    }
    void visit(string url) {
        delete_all_nodes_after(&curr->next);
        insert_after(curr, url);
        curr = curr->next;
    }
    string back(int steps) {
        while (steps && curr != head) {
            curr = curr->prev;
            steps--;
        }
        return curr->str;
    }
    string forward(int steps) {
        while (steps && curr->next != NULL) {
            curr = curr->next;
            steps--;
        }
        return curr->str;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */