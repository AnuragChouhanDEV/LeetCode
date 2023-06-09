// https://leetcode.com/problems/min-stack

class MinStack {
public:
    stack<pair<int,int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if (st.empty())
            st.push({val,val});
        else {
            int m = min(val, st.top().second);
            st.push({val,m});
        }

    }
    
    void pop() {
        if (!st.empty())
            st.pop();
    }
    
    int top() {
        if (!st.empty())
            return st.top().first;
        return 0;
    }
    
    int getMin() {
        if (!st.empty())
            return st.top().second;
        return 0;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */