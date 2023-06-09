// https://leetcode.com/problems/can-place-flowers

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i = 0; i < flowerbed.size(); ++i) {
            if (i == 0) {
                if (i+1 < flowerbed.size()) {
                    if (flowerbed[i] == 0 && flowerbed[i+1] == 0) {
                        flowerbed[i] = 1;
                        n--;
                    }
                }
            } else {
                if (i+1 < flowerbed.size() && flowerbed[i-1] == 0 && flowerbed[i+1] == 0 && flowerbed[i] == 0) {
                    n--;
                    flowerbed[i] = 1;
                } else {
                    if (i == flowerbed.size()-1 && flowerbed[i-1] == 0 && flowerbed[i] == 0) {
                        n--;
                        flowerbed[i] = 1;
                    }
                }
            }
        }
        return n <= 0;
    }
};