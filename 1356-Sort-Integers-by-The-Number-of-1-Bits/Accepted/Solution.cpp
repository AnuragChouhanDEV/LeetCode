// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/description/?envType=daily-question&envId=2023-10-30

class Solution {
public:
    int num_to_bits[16] = { 0, 1, 1, 2, 1, 2, 2, 3,
                        1, 2, 2, 3, 2, 3, 3, 4 };
    unsigned int countSetBitsRec(unsigned int num) {
        int nibble = 0;
        if (0 == num)
            return num_to_bits[0];
 
        nibble = num & 0xf;
        return num_to_bits[nibble] + countSetBitsRec(num >> 4);
    }
    
    
    vector<int> sortByBits(vector<int>& arr) {
        auto lambda = [&] (int &a, int &b) {
            int ca = countSetBitsRec(a);
            int cb = countSetBitsRec(b);
            if (ca == cb) return b > a;
                return ca < cb;
        };
        sort(arr.begin(), arr.end(), lambda);
        return arr;
    }
};