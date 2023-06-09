// https://leetcode.com/problems/design-circular-queue

class MyCircularQueue {
public:
    int front;
    int rear;
    int capacity;
    int *arr;
    MyCircularQueue(int k) {
        capacity = k;
        front = -1;
        rear = -1;
        arr = new int[k];
    }
    
    bool enQueue(int value) {
        if (isFull())
            return false;
        if (isEmpty()) {
            front = rear = 0;
            arr[rear] = value;
        } else {
            arr[++rear] = value;
        }
        return true;
    }
    
    bool deQueue() {
        if (isEmpty())
            return false;
        --front;
        --rear;
        return true;
    }
    
    int Front() {
        if (isEmpty())
            return -1;
        return arr[front];
    }
    
    int Rear() {
        if (isEmpty())
            return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        if (front == -1)
            return true;
        return false;
    }
    
    bool isFull() {
        if (rear == capacity-1)
            return true;
        return false;
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