// https://leetcode.com/problems/design-circular-deque

class MyCircularDeque {
public:
    int front, rear, size;
    unsigned capacity;
    int* array;
    
    MyCircularDeque(int k) {
        capacity = k;
        front = size = 0;
        rear = capacity - 1;
        array = new int[capacity];
    }
    
    bool insertFront(int value) {
        if (isFull())
            return false;
        front = (front - 1) % capacity;
        array[front] = value;
        size = size + 1;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull())
            return false;
        rear = (rear + 1) % capacity;
        array[rear] = value;
        size = size + 1;
        return true;
    //cout << item << " enqueued to queue\n";
    }
    
    bool deleteFront() {
        if (isEmpty())
            return false;
        int item = array[front];
        front = (front + 1) % capacity;
        size = size - 1;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty())
            return false;
        int item = array[rear];
        rear = (rear - 1) % capacity;
        size = size - 1;
        return true;
    }
    
    int getFront() {
        if (isEmpty())
            return INT_MIN;
        return array[front];
    }
    
    int getRear() {
        if (isEmpty())
            return INT_MIN;
        return array[rear];
    }
    
    bool isEmpty() {
        return (size == 0);
    }
    
    bool isFull() {
        return (size == capacity);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */