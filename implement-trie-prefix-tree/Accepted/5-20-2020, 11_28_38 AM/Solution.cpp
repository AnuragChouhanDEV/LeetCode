// https://leetcode.com/problems/implement-trie-prefix-tree

class Trie {
public:
    struct TrieNode
    {
        char val;
        int count;
        int endshere;
        TrieNode *child[26];
    };
    
    TrieNode *root;
    
    TrieNode *get_node(int index)
    {
        TrieNode *newnode = new TrieNode;
        newnode->val = 'a'+index;
        newnode->count = newnode->endshere = 0;
        for(int i=0;i<26;++i)
            newnode->child[i] = NULL;
        return newnode;
    }
    /** Initialize your data structure here. */
    Trie() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        root = get_node('/'-'a');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *curr = root;
        int idx;
        for(int i = 0; word[i]!='\0';++i) {
            idx = word[i]-'a';
            if (curr->child[idx] == NULL)
                curr->child[idx] = get_node(idx);
            curr->child[idx]->count += 1;
            curr = curr->child[idx];
        }
        curr->endshere += 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *curr = root;
        int idx;
        for(int i = 0; word[i]!='\0';++i) {
            idx = word[i]-'a';
            if (curr->child[idx] == NULL)
                return false;
            curr = curr->child[idx];
        }
        return (curr->endshere > 0);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        int idx;
        for(int i = 0; prefix[i]!='\0';++i) {
            idx = prefix[i]-'a';
            if (curr->child[idx] == NULL)
                return false;
            curr = curr->child[idx];
        }
        return (curr->count > 0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */