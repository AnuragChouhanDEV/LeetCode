// https://leetcode.com/problems/sliding-window-maximum/description/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        list<int> q;           // Deque to store indices of elements in the current window
        vector<int> ans;        // Vector to store the maximum values for each sliding window

        int left = 0;
        int right = 0;

        while (right < nums.size()) {
            // Pop smaller values from the back of the deque
            while (!q.empty() && nums[q.back()] < nums[right]) {
                q.pop_back();
            }
            q.push_back(right);

            // Remove the leftmost value if it's outside the current window
            if (left > q.front()) {
                q.pop_front();
            }

            // If the window size is reached, append the maximum value to the result
            if (right + 1 >= k) {
                ans.push_back(nums[q.front()]);
                left++;
            }
            right++;
        }

        return ans;

        
    }
};