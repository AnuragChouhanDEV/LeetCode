// https://leetcode.com/problems/furthest-building-you-can-reach/description/

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // stores the count of bricks utilized
        priority_queue<int> pq;
        int idx = 1;
        int diff = 0;
        for(; idx < heights.size(); idx++){
            diff = heights[idx] - heights[idx-1];
            // if height[idx] <= height[idx-1]
            if(diff <= 0)
                continue;
            
            // if height[idx] > height[idx-1]
            // if we have enough bricks in stock
            if(bricks >= diff) {
                bricks -= diff;
                pq.push(diff);
            }

            // if we have ladders in stock
            else if(ladders) {
                // if bricks count top is more than the heights diff
                // then use ladder instead of bricks
                if(!pq.empty() && pq.top() > diff) {
                    // get back the bricks from max heap
                    bricks += pq.top();
                    // remove entry from max heap
                    pq.pop();
                    // remove current diff from bricks
                    bricks -= diff;
                    // push current diff
                    pq.push(diff);
                }
                ladders--;
            }
            else 
                break;
        }
        return idx - 1;
    }
#if 0 // recursion + memoization MLE error
    int helper(vector<int>& heights, int bricks, int ladders, int idx, vector<vector<vector<int>>> dp) {
        if (idx >= heights.size()) 
            return 0;
        if (dp[bricks][ladders][idx] != -1)
            return dp[bricks][ladders][idx];
        if (heights[idx] - heights[idx-1] <= 0)
            return dp[bricks][ladders][idx] = 1 + helper(heights, bricks, ladders, idx+1, dp);
        int use_brick = 0;
        int use_ladder = 0;
        if (bricks >= heights[idx] - heights[idx-1])
            use_brick = 1 + helper(heights, bricks - (heights[idx] - heights[idx-1]), ladders, idx+1, dp);
        if (ladders)
            use_ladder = 1 + helper(heights, bricks, ladders-1, idx+1, dp);
        return dp[bricks][ladders][idx] = max(use_brick, use_ladder);
    }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        vector<vector<vector<int>>> dp(bricks + 1, vector<vector<int>>(ladders + 1, vector<int>(heights.size()+1, -1)));
        return helper(heights, bricks, ladders, 1, dp);
    }
#endif
};