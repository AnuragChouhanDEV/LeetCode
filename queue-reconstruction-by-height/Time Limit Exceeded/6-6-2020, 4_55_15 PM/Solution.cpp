// https://leetcode.com/problems/queue-reconstruction-by-height

class Solution {
    void swap (int &a, int &b) {
        int t = a;
        a = b;
        b = t;
    }
    static bool sortcol( const vector<int>& v1, 
               const vector<int>& v2 ) { 
        return v1[1] < v2[1]; 
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int len = people.size();
        sort(people.begin(), people.end(), sortcol);
        for (int i = 1; i < len; ++i) {
            int count = 1;
            while (people[i][1] == people[i-1][1]) {
                count++;
                ++i;
            }
            //cout << count << endl;
            sort(people.begin() + i - count, people.begin() + i);
        }
        for (int i = len - 1; i > 0; --i) {
            if (people[i][1] == 0)
                continue;
            int count_1 = people[i][1];
            int count_2 = 0;
            int j = i;

            while (j > 0) {
                if (people[i][0] <= people[j-1][0])
                    count_2++;
                j--;
            }
            if (count_2 - count_1 > 0) {
                swap(people[i][0], people[i-(count_2 - count_1)][0]);
                swap(people[i][1], people[i-(count_2 - count_1)][1]);
                count_2--;
                i++;
            }     
        }
        
        return people;
    }
};