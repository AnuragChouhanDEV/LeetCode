// https://leetcode.com/problems/find-median-from-data-stream

class MedianFinder {
public:
    double median = 0;
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    MedianFinder() {
        
    }
    void balance(void) {
        int ma = maxheap.size();
        int mi = minheap.size();
        if (ma-mi == 2 || ma-mi == -2) {
            if (ma>mi) {
                int element = maxheap.top();
                maxheap.pop();
                minheap.push(element);
            } else {
                int element = minheap.top();
                minheap.pop();
                maxheap.push(element);
            }
        }
    }
    void addNum(int num) {
        if (maxheap.empty() && minheap.empty())
            maxheap.push(num);
        else {
            if (maxheap.top() < num) {
                minheap.push(num);
            } else
                maxheap.push(num);
        }
        balance();
        if (maxheap.size() == minheap.size()) {
            int ma = maxheap.top();
            int mi = minheap.top();
            median = (double)(ma+mi)/2.0;
        } else if (maxheap.size() > minheap.size()) {
            median = maxheap.top();
        } else
            median = minheap.top();
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */