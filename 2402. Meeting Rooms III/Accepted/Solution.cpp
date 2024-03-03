// https://leetcode.com/problems/meeting-rooms-iii/description/?envType=daily-question&envId=2024-02-18

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> ans(n,0);
        vector< long long > times(n,0);
        sort(meetings.begin(),meetings.end());

        for(int i=0;i<meetings.size();i++){
            int start = meetings[i][0]; 
            int end = meetings[i][1];
            bool flag = false;
            int minind = -1;
            long long val = 1e18;
            for(int j = 0;j < n; j++) {
                if(times[j] < val) {
                    val = times[j];
                    minind = j;
                }
                if(times[j] <= start){
                    flag = true;
                    ans[j]++;
                    times[j] = end;
                    break;
                }
            }
            if(!flag) {
                ans[minind]++;
                times[minind]+=(1ll*(end-start));
            }
        }
        int maxi = -1, id = -1;
        for(int i =0;i<n;i++){
            if(ans[i] > maxi) maxi = ans[i], id = i;
        }
        return id;
    }
};

/*
{20,1} {10,1} {5,1}


0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
                                             1--1
      2--------------------2
                                         3------3
    4------------------------4 
                  
*/