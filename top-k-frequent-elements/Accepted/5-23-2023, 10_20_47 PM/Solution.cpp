// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
public:
    class node {
        public:
        int key;
        int freq;
        node(int k, int f) {key = k;freq = f;}
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> ma;
        for (auto it : nums)
            ma[it]++;
        int count = 0;
        auto cmp = [](node a, node b){return a.freq > b.freq;};
        priority_queue<node, vector<node>, decltype(cmp)> pq(cmp);
        for (auto it:ma) {
            if (count < k) {
                pq.push(node(it.first,it.second));
                count++;
                continue;
            }
            node t = pq.top();
            if (t.freq < it.second) {
                pq.pop();
                pq.push(node(it.first,it.second));
            }
        }
        vector<int> res;
        while(k--) {
            node tmp = pq.top();
            pq.pop();
            res.push_back(tmp.key);
        }
        return res;

    }
};