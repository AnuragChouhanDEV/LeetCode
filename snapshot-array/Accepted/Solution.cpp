// https://leetcode.com/problems/snapshot-array

class SnapshotArray {
public:
    vector<unordered_map<int, int>> ma;
    int idx = 0;
    SnapshotArray(int length) {
        ma.resize(length);
    }
    
    void set(int index, int val) {
        ma[index][idx] = val;
    }
    
    int snap() { 
        return idx++;
    }
    
    int get(int index, int snap_id) {
        while (snap_id >= 0 && ma[index].find(snap_id) == ma[index].end())
            snap_id--;
        if (snap_id < 0)
            return 0;
        return ma[index][snap_id];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */