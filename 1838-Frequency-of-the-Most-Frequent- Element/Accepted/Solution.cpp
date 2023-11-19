// https://leetcode.com/problems/frequency-of-the-most-frequent-element/description/?envType=daily-question&envId=2023-11-18

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size()-1; ++i) {
            if (nums[i] > nums[i+1]) {
                sort(nums.begin(), nums.end());
                break;
            }
        }

        int maxfreq = 1;
        int l = 0;
        long long int total = 0; 

        for (int i = 0; i < nums.size(); ++i) {
            total += nums[i];

            if (l+1 <= i && ((long long int)(nums[i] * (long long int)(i - l +1)) > total + k)) {
                total -= nums[l];
                l++;
            } 
            maxfreq = max(maxfreq, i-l+1);
        }

        return maxfreq;
    }
};

/*
1 2 4


*/