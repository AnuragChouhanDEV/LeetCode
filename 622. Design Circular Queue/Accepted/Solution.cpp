// https://leetcode.com/problems/design-circular-queue/description/

class MyCircularQueue {
public:
    vector<int> cq;
    int front;
    int rear;
    int size;
    int count = 0;
    MyCircularQueue(int k) {
        cq.resize(k,-1);
        front = 0;
        rear = 0;
        size=k;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        rear=rear%size;
        cq[rear]=value;
        rear++;count++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        front=front%size;
        cq[front]=-1;
        front++;count--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return cq[front%size];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return cq[rear-1%size];
    }
    
    bool isEmpty() {
        return count==0;
    }
    
    bool isFull() {
        return count==size;
    }
};
/*
f=0
r=2
1 2 3

*/
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