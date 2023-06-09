// https://leetcode.com/problems/number-of-recent-calls

class RecentCounter {
public:
    queue<int> q;
    int arr[2];
    RecentCounter() {
        arr[0] = -3000;
        arr[1] = 0;
    }
    
    int ping(int t) {
        q.push(t);
        arr[0] = t-3000;
        arr[1] = t;
        //cout << arr[0] << " " << arr[1] <<endl;
        while (!q.empty()) {
            int f = q.front();
            if (f < arr[0]) q.pop();
            else break;
        }
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */