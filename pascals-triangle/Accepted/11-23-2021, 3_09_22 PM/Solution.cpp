// https://leetcode.com/problems/pascals-triangle

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //int i = 1;
        int test = 2;
        //numRows = 4;
        vector<vector<int>> res;
        vector<int> v;
        v.push_back(1);
        res.push_back(v);
        if (numRows == 1)
            return res;
        //cout << v.size();
        v.pop_back();
        v.push_back(1);
        v.push_back(1);
        res.push_back(v);
        if (numRows == 2)
            return res;
        //cout << v.size();
        while (test < numRows) {
            int i = 1;
            vector<int> v;
            v.push_back(1);
#if 1
            while (i < test){
                v.push_back(res[test-1][i-1]+res[test-1][i]);
                i++;
            }
#endif
            v.push_back(1);
            //cout << v.size();
            res.push_back(v);
            test++;
        }
        return res;
        
        
    }
};