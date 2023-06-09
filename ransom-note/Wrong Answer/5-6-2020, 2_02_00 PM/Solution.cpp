// https://leetcode.com/problems/ransom-note

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> map;
        for (int i = 0; i < magazine.length(); ++i) {
            map[magazine[i]]++;
        }
        
        for (int j=0;ransomNote[j]!='\0';++j) {
            if (map.find(ransomNote[j])!=map.end()) {
                map[ransomNote[j]]--;
            }
        }
        for (auto i:map) {
            if (i.second < 0)
                return false;
        }
        return true;
    }
};