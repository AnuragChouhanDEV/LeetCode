// https://leetcode.com/problems/total-cost-to-hire-k-workers

class Solution {
public:
    struct comp {
        bool operator()(const pair<int,int> &p1, const pair<int,int> &p2) {
            if (p1.first != p2.first) {
                return p1.first > p2.first;
            } else {
                return p1.second > p2.second;
            }
        }
    };
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long total_cost = 0;
        int n = costs.size()-1;
        if (n == 0) return costs[n];
        priority_queue<pair<int,int> , vector<pair<int,int>>, comp> p1;
        int i = 0;
        while (i < n && candidates) {
            candidates--;
            p1.push({costs[i],i});
            p1.push({costs[n],n});
            i++;
            n--;
        }

        while(k && i <= n) {
            k--;
            auto p = p1.top();
            p1.pop();
            total_cost += p.first;
            if (p.second < i) {
                p1.push({costs[i],i});
                i++;
            } else {
                p1.push({costs[n],n});
                n--;
            }
        }
        // cout << k << " " <<  i << " " << n << " " << endl;
        while(k && !p1.empty()) {
            total_cost += p1.top().first;
            p1.pop();
            k--;
        }
        return total_cost; 
    }
};