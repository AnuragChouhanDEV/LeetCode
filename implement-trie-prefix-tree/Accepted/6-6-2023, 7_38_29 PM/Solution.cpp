// https://leetcode.com/problems/implement-trie-prefix-tree

class Trie {
public:
    struct TrieNode {
	    unordered_map<char,TrieNode*> child;
	    bool isEndofWord = false;
    };

    TrieNode* root;
    Trie() {
        root = new TrieNode;
    }
    
    void insert(string word) {
	    TrieNode* curr = root;
	    if (!curr) return;
    	for (auto x : word) {
    		if (curr->child.find(x) == curr->child.end()) {
					//cout << "insert " << x << endl;
					curr->child[x] = new TrieNode;
				}
    		curr = curr->child[x];
    	}
	    curr->isEndofWord = true;
    }
    
    bool search(string word) {
    	TrieNode* curr = root;
	    if (!curr) return false;
	    for (auto x : word) {
				//cout << x << " ";
	    	if (curr->child.find(x) == curr->child.end()) return false;
	        curr = curr->child[x];
	    }
	    return curr->isEndofWord;
    }
    
    bool startsWith(string prefix) {
      TrieNode* curr = root;
	    if (!curr) return false;
	    for (auto x : prefix) {
				if (curr->child.find(x) == curr->child.end()) return false;
	        curr = curr->child[x];
	    }
	    return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */