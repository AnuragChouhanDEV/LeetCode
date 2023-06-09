// https://leetcode.com/problems/design-hashset

class MyHashSet {
public:
    vector<vector<int>> bucket;
    int bucket_size;
    int hf(int key) {
        return key%bucket_size;
    }
    MyHashSet() {
        bucket_size = 1000000;
        bucket = vector<vector<int>> (bucket_size, vector<int>{});
    }
    
    void add(int key) {
        int i = hf(key);
        if (find(bucket[i].begin(), bucket[i].end(), key) == bucket[i].end())
            bucket[i].push_back(key);
    }
    
    void remove(int key) {
        int i = hf(key);
        auto it = find(bucket[i].begin(), bucket[i].end(), key);
        if (it != bucket[i].end())
            bucket[i].erase(it);
    }
    
    bool contains(int key) {
        int i = hf(key);
        if (find(bucket[i].begin(), bucket[i].end(), key) == bucket[i].end())
            return false;
        return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */