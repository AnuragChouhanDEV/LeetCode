// https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/description/

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
       int ans=0, l=-1, r=-1;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]>right) l=i;
            if (nums[i]>=left) r=i;
            ans+=r-l;
        }
        return ans;
    }
#if 0
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        // least index
        vector<int> maxLeft(n,-1);
        // max index
        vector<int> maxRight(n,n);
        vector<int> v;

        for(int i=0; i<n; i++){
            while(v.size() && nums[v.back()] <= nums[i])
                v.pop_back();
            if(v.size())
                maxLeft[i] = v.back();
            v.push_back(i);
        }
        v.clear();
        for(int i=n-1; i>=0; i--){
            while(v.size() && nums[v.back()] < nums[i])
                v.pop_back();
            if(v.size())
                maxRight[i] = v.back();
            v.push_back(i);
        }

        int res = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] >= left && nums[i] <= right){
                res += ((i - maxLeft[i]) * (maxRight[i]-i) );
            }
        }

        return res;
    }
#endif
};