// https://leetcode.com/problems/reorganize-string

class Solution {
public:
    class node {
        public:
        char key;
        int freq;
        node(int k,int f) {key = k;freq = f;}
    };
    string reorganizeString(string s) {
        unordered_map<char, int> ma;
        for (auto c:s)
            ma[c]++;
        auto cmp = [](node a,node b){return a.freq < b.freq;};
        priority_queue<node, vector<node>, decltype(cmp)> pq(cmp);
        for(auto it:ma) {
            pq.push(node(it.first,it.second));
        }
        node g('$',-1);
        string res = "";
        while (!pq.empty()) {
            node tmp = pq.top();
            pq.pop();
            res += tmp.key;
            cout << res << endl;
            tmp.freq--;
            if (g.freq > 0) {
                pq.push(g);
            }
            g=tmp;
        }
        if (s.size() == res.size())
            return res;
        return "";
    }
};