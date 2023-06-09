// https://leetcode.com/problems/time-based-key-value-store

class TimeMap {
public:
    unordered_map<string, string> ma;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        ma[key]=value;
    }
    
    string get(string key, int timestamp) {
        if (ma.find(key) != ma.end())
            return ma[key];
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */