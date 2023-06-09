// https://leetcode.com/problems/design-circular-queue

class MyCircularQueue {
public:
    vector<int> vec;
    int size;
    int front_idx = 0;
    int rear_idx = -1;
    MyCircularQueue(int k) {
        size = k;
        vec.resize(k,-1);
    }
    
    bool enQueue(int value) {
        if (isFull())
            return false;
        rear_idx = (rear_idx+1)%size;
        vec[rear_idx] = value;
        
        return true;
    }
    
    bool deQueue() {
        if (isEmpty())
            return false;
        vec[front_idx] = -1;
        front_idx = (front_idx+1)%size;
        return true;
    }
    
    int Front() {
        return vec[front_idx];
    }
    
    int Rear() {
        return vec[rear_idx];
    }
    
    bool isEmpty() {
        return front_idx == rear_idx;
    }
    
    bool isFull() {
        return front_idx == 0 ? (rear_idx == size - 1 ? true:false):(front_idx - 1 == rear_idx);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */