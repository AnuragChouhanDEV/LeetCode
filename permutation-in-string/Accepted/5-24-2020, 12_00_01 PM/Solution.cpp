// https://leetcode.com/problems/permutation-in-string

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<int> ans;
        vector<int> hash(26,0);
        vector<int> phash(26,0);
        int window = s1.size();
        int len = s2.size();
        if(len<window)
            return false;
        int left = 0,right = 0;
        while(right<window)
        {
            phash[s1[right]-'a'] +=1;
            hash[s2[right++]-'a'] +=1;
        }
        right -=1;
        cout << "len " << len << endl;
        cout << "window " << window << endl;
        while(right<len)
        {
            //cout << "phash " << phash << " " << "hash " << hash << endl;
            if(phash == hash) {
                //cout << left << endl;
                //cout << right << endl;
                return true;
                ans.push_back(left);
            }
            right+=1;
            if(right!=len)
                hash[s2[right]-'a'] +=1;
            hash[s2[left]-'a'] -=1;
            left+=1;
        }
        return false;
    }
};