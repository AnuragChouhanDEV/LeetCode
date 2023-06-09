// https://leetcode.com/problems/detonate-the-maximum-bombs

class Solution {
public:
    typedef long long ll;
    bool in_range(ll x, ll y, ll radius, ll xx, ll yy, ll rradius) {
        ll xd = xx-x;xd *= xd;
        ll yd = yy-y;yd *= yd;
        ll dist = xd+yd;
        if (dist <= radius*radius) return true;
        return false;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<int> visited(n, 1);
        int maxi = 1;
        //cout << "came here 2"<<endl;
        for (int i = 0; i < n; ++i) {
            queue<pair<int,pair<int,int>>> q;
            if (visited[i] != 1) continue;
            
            q.push({bombs[i][2], {bombs[i][0], bombs[i][1]}});
            //cout << "came here 1"<<endl;
            while (!q.empty()) {
                auto it = q.front();
                int x = it.second.first;
                int y = it.second.second;
                
                int radius = it.first;
                q.pop();

                for (int j = 0; j < n; ++j) {
                    //cout << "came here"<<endl;
                    if (i == j) {continue;}
                    if (in_range((ll)x, (ll)y, (ll)radius, (ll)bombs[j][0], (ll)bombs[j][1], (ll)bombs[j][2])) {
                        visited[i] += 1;
                        //cout << i<< " "<< j << endl;
                        maxi = max(maxi, visited[i]);
                        if (maxi == n) return n;
                        q.push({bombs[j][2], {bombs[j][0], bombs[j][1]}});
                    }
                }
            }
        }
        return maxi;
    }
};