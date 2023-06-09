// https://leetcode.com/problems/lru-cache

class LRUCache {
public:
    class Node {
        public:
        int key;
        int value;
        Node *next;
        Node *prev;
        Node (int k, int v) {
            key = k;
            value = v;
            next = NULL;
            prev = NULL;
        }
    };
    int capacity;
    Node *head;
    Node *tail;
    map<int, Node *> ma;
    
    LRUCache(int cap) {
        capacity = cap;
        head = tail = NULL;
        //cout << "here 1 " << endl;
    }
    
    void add_node(Node *node) {
        if (head == NULL || tail == NULL) {
            cout << "adding " << node->key << " " << node->value << endl;
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
            //cout << "adding " << node->key << " " << node->value << endl;
        }
    }
    
    void del_node(Node *node) {
        if (node == head) {
            head = head->next ? head->next : NULL;
            if (head)
                head->prev = NULL;
            delete node;
            return;
        }
        if (node == tail) {
            tail = tail->prev ? tail->prev : NULL;
            if (tail)
                tail->next = NULL;
            tail->next = NULL;
            delete node;
            return;
        }
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }
    
    int get(int key) {
        if (ma.find(key) != ma.end()) {
            Node *tmp = ma[key];
            int value = tmp->value;
            ma.erase(key);
            del_node(tmp);
            tmp = new Node({key,value});
            add_node(tmp);
            ma[key] = tmp;
            cout << "here 3 " << endl;
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (ma.find(key) != ma.end()) {
            Node *tmp = ma[key];
            ma.erase(key);
            del_node(tmp);
            tmp = new Node({key,value});
            add_node(tmp);
            ma[key] = tmp;
        } else if (ma.size() == capacity){
            ma.erase(tail->key);
            del_node(tail);
            Node *tmp = new Node({key,value});
            add_node(tmp);
            ma[key] = tmp;
        } else {
            Node *tmp = new Node({key,value});
            add_node(tmp);
            ma[key] = tmp;
            //cout << "here 2 " << endl;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */