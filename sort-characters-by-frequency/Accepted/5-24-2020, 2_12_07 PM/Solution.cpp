// https://leetcode.com/problems/sort-characters-by-frequency

class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char>> vec('z'+1,{0,0});
        for (auto c : s)
            vec[c] = {vec[c].first+1,c};
        sort(vec.begin(),vec.end());
        string res = "";
        for (auto i:vec) {
            //cout << i.first << " " << i.second << endl;
            res = string(i.first,i.second) + res;
        }
        return res;
    }
};