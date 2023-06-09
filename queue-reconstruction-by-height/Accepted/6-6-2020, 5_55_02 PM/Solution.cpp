// https://leetcode.com/problems/queue-reconstruction-by-height

class Solution {
    static bool sortcol( const vector<int>& v1, 
               const vector<int>& v2 ) { 
        //cout << v1[0] << " " << v2[0] << " . " << v1[1] << " " << v2[1] << endl;
        return (v1[0] > v2[0] || (v1[0] == v2[0] && v1[1] < v2[1])); 
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int len = people.size();
        vector<vector<int>> res;
        sort(people.begin(), people.end(), sortcol);
        int i = 0;
        for (vector<int> x : people) {
            res.insert(res.begin() + x[1], x);
        }
        
        return res;
    }
};