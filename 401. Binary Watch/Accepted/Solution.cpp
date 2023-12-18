// https://leetcode.com/problems/binary-watch/description/

class Solution {
public:
    vector<int> hours={1,2,4,8};
    vector<int> min={1,2,4,8,16,32};
    vector<string> res;
    void helper(int turnedOn, int idx, pair<int,int> time) {
        if (turnedOn == 0) {
            if (time.second < 10) {
                res.push_back(to_string(time.first)+":0"+to_string(time.second));
            } else {
                res.push_back(to_string(time.first)+":"+to_string(time.second));
            }
            return;
        }
        int h = hours.size();
        int m = min.size();

        for (int i = idx; i < (m+h); ++i) {
            if (i < h) {
                time.first+=hours[i];
                if (time.first < 12)
                    helper(turnedOn-1, i+1, time);
                time.first-=hours[i];
            } else {
                time.second+=min[i-h];
                if (time.second < 60)
                    helper(turnedOn-1, i+1, time);
                time.second-=min[i-h];
            }
        }
    }
    vector<string> readBinaryWatch(int turnedOn) {
        helper(turnedOn, 0, {0,0});
        return res;
    }
};

/*
0000
000000

1100
111011
*/