// https://leetcode.com/problems/two-furthest-houses-with-different-colors/

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int i = 0;
        int j = colors.size()-1;
        int dist1 = 0;
        int dist2 = 0;
        while (i < j) {
            if (colors[i] != colors[j])
                dist1 = max(dist1, abs(j-i));
            j--;
        }
        i = 0;
        j = colors.size()-1;
        while (i < j) {
            if (colors[i] != colors[j])
                dist2 = max(dist2, max(dist1,abs(j-i)));
            i++;
        }
        return dist2;
    }
};