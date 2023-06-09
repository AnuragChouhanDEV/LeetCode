// https://leetcode.com/problems/ransom-note

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> map;
        for (int i = 0; i < ransomNote.length(); ++i)
            map[ransomNote[i]]++;
        
        int count = 0;
        for (int j=0;magazine[j]!='\0';++j) {
            if (map.find(magazine[j])!=map.end())
                count++;
        }
        return count==ransomNote.length();
    }
};