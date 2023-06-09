// https://leetcode.com/problems/smallest-number-in-infinite-set

class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    SmallestInfiniteSet() {
        for (int i = 1; i <= 2000; ++i)
            pq.push(i);
    }
    
    int popSmallest() {
        int i = pq.top();
        pq.pop();
        return i;
    }
    
    void addBack(int num) {
        if (pq.top() <= num) return;
        pq.push(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */