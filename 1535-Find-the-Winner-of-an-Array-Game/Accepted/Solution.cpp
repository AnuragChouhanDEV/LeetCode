// https://leetcode.com/problems/find-the-winner-of-an-array-game/description/?envType=daily-question&envId=2023-11-05

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if (k > arr.size()) {
            sort(arr.begin(), arr.end());
            return arr[arr.size()-1];
        } else {
            int count = 0;
            int i = 0;
            int j = 1;
            while (count < k && j < arr.size()) {
               //cout << "i " << arr[i] << " " << "j " << arr[j] << endl;
                if (arr[i] < arr[j]) {
                    swap(arr[i], arr[j]);
                    count = 0;
                } else {
                    count++;
                    j++;
                }
            }
            return arr[0];
        }
        return arr[0];
    }
};