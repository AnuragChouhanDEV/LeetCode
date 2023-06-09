// https://leetcode.com/problems/remove-k-digits

class Solution {
public:
    string removeKdigits(string num, int k) {
        int size = num.size();
        stack<char> s;
        
        for (char c : num) {
            while(!s.empty() && k > 0 && s.top() > c){
                s.pop();
                k--;
            }
            if (!s.empty() || c!='0'){
                s.push(c);
            }
        }
        while (!s.empty() && k--) {
            s.pop();
        }
        if (s.empty())
            return "0";
        while(!s.empty()) {
            num[size-1] = s.top();
            s.pop();
            size--;
        }
        return num.substr(size);
    }
};