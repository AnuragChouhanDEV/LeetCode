// https://leetcode.com/problems/count-subarrays-with-score-less-than-k

class Solution {
public:
    long long count;
    void count_rec(vector<int>& nums, long long k, int idx, long long sum, int size) {
        if (idx == nums.size())
            return;
        if (count >= k)
            return;
        
        int curr_el = nums[idx];
        long long product = curr_el * size;
        //if (curr_el < k || product < k)
            count += curr_el != product ? curr_el < k:0;
            count += product < k;
        
        //count_rec(nums, k, idx+1, sum, size+1);
        if (product < k) {
            //if (curr_el != product) {
                cout << product << " " << curr_el << endl;
                count_rec(nums, k, idx+1, sum+curr_el, size+1);
            //}
        } else {
            cout << product << "        " << curr_el << endl;
            count_rec(nums, k, idx+1, 0, 1);
        }
        // consider idx element
            //inc count
        // else fresh start with sum = 0
        
    }
    long long countSubarrays(vector<int>& nums, long long k) {
        count = 0;
        count_rec(nums, k, 0, 0, 1);
        return count;
    }
};