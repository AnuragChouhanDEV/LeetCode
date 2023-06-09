// https://leetcode.com/problems/design-hashmap

class MyHashMap {
public:
    vector<int> hmap;
    MyHashMap() {
        hmap.resize(1e6+1,-1);
    }
    
    void put(int key, int value) {
        hmap[key] = value;
    }
    
    int get(int key) {
        return hmap[key];
    }
    
    void remove(int key) {
        hmap[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */