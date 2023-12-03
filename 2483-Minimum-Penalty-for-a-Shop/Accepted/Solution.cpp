// https://leetcode.com/problems/minimum-penalty-for-a-shop/description/?envType=daily-question&envId=2023-12-03

class Solution {
public:
    int bestClosingTime(string customers) {
        int yes_count = 0;
        int res = 0;
        for (auto c:customers) {
            if (c == 'Y')
                yes_count++;
        }
        int penalty = yes_count;
        if (yes_count == customers.size())
            return yes_count;
        if (yes_count == 0)
            return 0;
        for (int i = 0; i < customers.size(); ++i) {
            if (customers[i] == 'Y')
                yes_count--;
            else
                yes_count++;
            
            if (penalty > yes_count) {
                penalty = yes_count;
                //cout << "i " << i << " ";
                res = i+1;
            }
        }
        return res;
        
    }
};