// https://leetcode.com/problems/last-stone-weight

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue <int> pq;
        int f,s;
        int n = stones.size();
        
        for (int i = 0; i < stones.size();++i)
            pq.push(stones[i]);
        
        while (n > 0) {
            f = pq.top();
            pq.pop();
            s = pq.top();
            pq.pop();
            n -= 2;
            if (f-s > 0) {
                pq.push(f-s);
                n += 1;
            }
        }
        if (!pq.empty())
            return pq.top();
        return 0;
    }
};