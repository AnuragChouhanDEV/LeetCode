// https://leetcode.com/problems/kth-largest-element-in-a-stream

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int size;
    KthLargest(int k, vector<int>& nums) {
        if (nums.size() == 0) {size = k;return;}
        for(auto num:nums)
            pq.push(num);
        while (pq.size() > k)
            pq.pop();
        size = k;
    }
    
    int add(int val) {
        if (pq.size() == size) {
            if (pq.top() > val)
                return pq.top();
            else {
                pq.pop();
                pq.push(val);
            }
            return pq.top();
        } else {
            if (pq.size() <= size)
                pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */