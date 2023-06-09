// https://leetcode.com/problems/jewels-and-stones

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<int,int> map;
        for (int i = 0; i < J.length();++i)
            map[J[i]]++;
        
        int count = 0;
        for (int j=0;S[j]!='\0';++j) {
            if (map.find(S[j])!=map.end())
                count++;
        }
        return count;
    }
};