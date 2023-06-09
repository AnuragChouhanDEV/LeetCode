// https://leetcode.com/problems/lfu-cache

class LFUCache {
public:
    class Node {
		public:
		pair<int,int> kv;
		Node *prev;
		Node *next;
		Node (int key, int value) {
			kv.first = key;
			kv.second = value;
			prev = NULL;
			next = NULL;
		}
	};
    int cap;
	map<int, Node*> ma;
	Node *head;
	Node *tail;
    LFUCache(int capacity) {
        cap = capacity;
        head = NULL;
        tail = NULL;
    }
    void add_node(Node *new_node) {
		//cout << "add_node ENTER" << endl;
		if (head == NULL || tail == NULL) {
			head = tail = new_node;
		} else {
			new_node->next = head;
			head->prev = new_node;
			head = new_node;
		}
		//cout << "add_node EXIT" << endl;
	}
	
	void del_node(Node *del) {
		//cout << "del_node ENTER " << endl;
		if (del == head) {
			head = head->next;
			if (head && head->prev)
				head->prev = NULL;
			delete del;
			//cout << "del_node EXIT 1" << endl;
			return;
		}
		if (del == tail) {
			tail = tail->prev;
			if (tail && tail->next)
				tail->next = NULL;
			delete del;
			//cout << "del_node EXIT 2" << endl;
			return;
		}
		del->next->prev = del->prev;
		del->prev->next = del->next;
		delete del;
		//cout << "del_node EXIT 3" << endl;
	}
    int get(int key) {
		if (ma.find(key) != ma.end()) {
			Node *tmp = ma[key];
			int val = tmp->kv.second;
			del_node(tmp);
			ma.erase(key);
			tmp = new Node({key, val});
			add_node(tmp);
			ma[key] = tmp;
			//cout << "get EXIT " << endl;
			return tmp->kv.second;
		}
		//cout << "get EXIT null " << endl;
        return -1;
    }
    
    void put(int key, int value) {
        if (ma.find(key) != ma.end()) {
			Node *tmp = ma[key];
			del_node(tmp);
			ma.erase(key);
			tmp = new Node({key, value});
			add_node(tmp);
			ma[key] = tmp;
		} else if (ma.size() == cap) {
			ma.erase(tail->kv.first);
			del_node(tail);
			Node *tmp = new Node({key, value});
			add_node(tmp);
			ma[key]=tmp;
		} else {
			Node *tmp = new Node({key, value});
			add_node(tmp);
			ma[key]=tmp;
		}
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */