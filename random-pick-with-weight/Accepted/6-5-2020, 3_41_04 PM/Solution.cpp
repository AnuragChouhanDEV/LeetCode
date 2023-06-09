// https://leetcode.com/problems/random-pick-with-weight

class Solution {
    vector<int> tot_arr;
    int tot = 0;
    #if 1
    int bin_search(int x) 
    {
        int l = 0, r = tot_arr.size(), m;
        while (l < r) {
            m = l + (r - l) / 2;
            if (tot_arr[m] < x)
                l = m +1;
            else
                r = m;
        }
        return l;
    } 
    #endif
public:
    Solution(vector<int>& w) {

        for (int i = 0; i < w.size();++i) {
           // cout << w[i] << endl;
            tot += w[i];
            tot_arr.push_back(tot);
            
            
        }
        //cout << tot << endl;
    }
    
    int pickIndex() {
        int ra = rand() % tot + 1;
        return bin_search(ra);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */