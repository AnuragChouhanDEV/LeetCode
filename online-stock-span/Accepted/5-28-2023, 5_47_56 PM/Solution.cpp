// https://leetcode.com/problems/online-stock-span

class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        if (st.empty()) {
            st.push({price,1});
            return 1;
        }
        
        if (!st.empty() && price < st.top().first) {
            st.push({price,1});
            return 1;
        }

        int count = 1;
        while (!st.empty() && price >= st.top().first) {
            count += st.top().second;
            st.pop();
        }
        st.push({price,count});
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */