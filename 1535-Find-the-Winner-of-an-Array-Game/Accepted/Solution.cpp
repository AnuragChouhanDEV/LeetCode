// https://leetcode.com/problems/find-the-winner-of-an-array-game/description/?envType=daily-question&envId=2023-11-05

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int cons_wins = 1;
        int ans = arr[0];
        for (int i = 1 ; i < arr.size(); ++i) {
            if (ans < arr[i]) {
                ans = arr[i];
                cons_wins = 1;
            }
            if (cons_wins == k) break;
            cons_wins++;
        }
        return ans;
    }
};

#if 0
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
#endif
