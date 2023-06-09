// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int left = -1;
        int right = -1;
        if(start == end) {
            if(nums[start] == target)
                return {start,end};
        }
        while (start <= end) {
            int mid = (start + end)/2;
            //cout << mid << " xx "<< endl;
            if (nums[mid] == target) {
                
                left = mid;
                right = mid;
                //cout << left << " " << right << endl;
                while (left > start && nums[left-1] == target) {
                    //cout << "dec left" << endl;
                    left--;
                }
                while (right < end && nums[right+1] == target) {
                    //cout << "inc right" << endl;
                    right++;
                }
                break;
            } else if (nums[mid] < target) {
                //cout<< nums[mid] << " here ";
                start = mid + 1;
            } else if (nums[mid] > target) {
                //cout << nums[mid] << " :: ";
                end = mid - 1;
            } else {
                continue;
            }
        }
        if (left != -1 && right != -1)
            return {left,right};
        //cout << left << " " << right << endl;
        return {-1,-1};
    }
};