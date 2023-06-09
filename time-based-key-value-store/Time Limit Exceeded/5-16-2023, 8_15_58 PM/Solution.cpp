// https://leetcode.com/problems/time-based-key-value-store

class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> ma;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        ma[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = ma.find(key);
        if (it != ma.end()) {
            vector<pair<int, string>> tmp(it->second.begin(), it->second.end());
            int left = 0;
            int right = tmp.size()-1;
            int mid = 0;

            while (left <= right) {
                mid = left + (right-left)/2;
                if (tmp[mid].first < timestamp) {
                    if (mid == right || tmp[mid+1].first > timestamp) return tmp[mid].second;
                    left = mid+1;
                } else if (tmp[mid].first > timestamp) right = mid-1; 
                else return tmp[mid].second;
            }
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */