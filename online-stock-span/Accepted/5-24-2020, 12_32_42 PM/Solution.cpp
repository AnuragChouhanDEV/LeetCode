// https://leetcode.com/problems/online-stock-span

class StockSpanner {
    stack<pair<int,int>> s;
    int idx;
public:
    StockSpanner() {
        idx = -1;
    }
    
    int next(int price) {
        idx++;
        
        while(!s.empty() && s.top().second<=price)    //Find the previous greater element
            s.pop();
        //If there is no previous greater element
        if(s.empty()) {
            s.push({idx,price});
            //cout << idx << endl;
            return idx+1;
        }
        
        int result = s.top().first;
        s.push({idx,price});
        return idx-result;  
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */