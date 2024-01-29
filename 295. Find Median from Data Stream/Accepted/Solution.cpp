// https://leetcode.com/problems/find-median-from-data-stream/description/

class MedianFinder {
public:
    priority_queue<int> pq_min;
    priority_queue<int, vector<int>, greater<int>> pq_max;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        pq_min.push(num);
        pq_max.push(pq_min.top());
        pq_min.pop();
        if (pq_max.size() > pq_min.size()) {
            pq_min.push(pq_max.top());
            pq_max.pop();
        }
    }
    
    double findMedian() {
        return (double) (pq_min.size() == pq_max.size()) ? (pq_min.top()+pq_max.top())/2.0 : pq_min.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */