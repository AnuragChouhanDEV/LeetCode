// https://leetcode.com/problems/daily-temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> res(size, 0);
        stack<int> st;
        for (int i = size-1; i >= 0; --i) {
            while(!st.empty() && temperatures[st.top()] <= temperatures[i])
                st.pop();
            if (!st.empty())
                res[i] = st.top()-i;
            st.push(i);
        }
        return res;
    }
};


76 75 74 73

