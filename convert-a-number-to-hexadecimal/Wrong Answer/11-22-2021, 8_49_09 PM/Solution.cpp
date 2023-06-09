// https://leetcode.com/problems/convert-a-number-to-hexadecimal

class Solution {
public:
    string toHex(int num) {
        string str;
        if (num == -1)
            return "ffffffff";
        while (num) {
            int c = num % 16;
            cout << c << endl;
            if (c <= 9 && c >= 0)
                str.push_back(c+48);
            else if (c >= 10 && c <= 15){
                str.push_back(c+87);
            }
            num = num >> 4;
        }
        if (num == 0)
            return "0";
        reverse(str.begin(),str.end());
        return str;
    }
};