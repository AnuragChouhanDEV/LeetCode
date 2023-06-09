// https://leetcode.com/problems/search-suggestions-system

class Solution {
public:
    struct TrieNode 
    { 
        struct TrieNode *children[26];
        bool isEndOfWord; 
    };
    
    struct TrieNode *getNode(void) {
        struct TrieNode *pNode =  new TrieNode;
        pNode->isEndOfWord = false;
        for (int i = 0; i < 26; i++)
            pNode->children[i] = NULL;
        return pNode;
    }
    void insert(struct TrieNode *root, string key)
    {
        struct TrieNode *pCrawl = root; 
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (!pCrawl->children[index])
                pCrawl->children[index] = getNode();
            pCrawl = pCrawl->children[index];
        }
        pCrawl->isEndOfWord = true;
    }
    bool search(struct TrieNode *root, string key)
    {
        struct TrieNode *pCrawl = root;
        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (!pCrawl->children[index])
                return false;
            pCrawl = pCrawl->children[index];
        }
        return (pCrawl->isEndOfWord);
    }
    void dfsWithPrefix(TrieNode * curr, string & word, vector<string> & result) {
        if (result.size() == 3)
            return;
        if (curr->isEndOfWord)
            result.push_back(word);

        for (char c = 'a'; c <= 'z'; c++)
            if (curr->children[c - 'a']) {
                word += c;
                dfsWithPrefix(curr->children[c - 'a'], word, result);
                word.pop_back();
            }
    }
    vector<string> getWordsStartingWith(string & prefix, struct TrieNode *root) {
        struct TrieNode *curr = root;
        vector<string> result;

        // Move curr to the end of prefix in its trie representation.
        for (char &c : prefix) {
            if (!curr->children[c - 'a'])
                return result;
            curr = curr->children[c - 'a'];
        }
        dfsWithPrefix(curr, prefix, result);
        return result;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        struct TrieNode *trie = getNode();
        
        for(string &w:products)
            insert(trie, w);
        string prefix;
        for (char &c : searchWord) {
            prefix += c;
            res.push_back(getWordsStartingWith(prefix, trie));
        }
        return res;
    }
};