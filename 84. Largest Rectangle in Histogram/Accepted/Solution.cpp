// https://leetcode.com/problems/largest-rectangle-in-histogram/description/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;        
        int n = heights.size();
        int maxa = 0;
        int left_small[n] ;
        int right_small[n] ;
        
        for(int i = 0 ; i < n ; i++)
        {  
            if(st.empty()) {
                st.push(i);
                left_small[i] = 0;
            } 
            if( (!st.empty()) && (heights[st.top()] <= heights[i])) {
                left_small[i] = st.top() + 1;
                st.push(i);   
            }
            while((!st.empty()) && (heights[st.top()] >= heights[i])) {
                st.pop();
                if( (!st.empty()) && (heights[st.top()] <= heights[i]))
                    left_small[i] = st.top() + 1; 
            }
            if(st.empty())
                left_small[i] = 0;
            st.push(i);
        }
        // empty st
        while(!st.empty()) st.pop();        
        // right_small
        for(int i = n-1 ; i >= 0 ; i--)
        {   
            while((!st.empty()) && (heights[st.top()] >= heights[i])) 
                st.pop();
            if(st.empty())
                right_small[i] = n-1;
            else 
                right_small[i] = (st.top() - 1);   
            st.push(i);
        }
        
        for(int x = 0 ; x < n ; x++)
            maxa =  max(maxa,(heights[x] * ( right_small[x] - left_small[x] + 1 )));
        
        return maxa;
    }
};