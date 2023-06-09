// https://leetcode.com/problems/counting-elements

class Solution {
public:
    int countElements(vector<int>& arr) {
        std::unordered_set<int> st(std::begin(arr), std::end(arr));
        
        //for (int val : arr) {
          //  st.add(val);
        //}
        
        int count = 0;
        
        for (int i = 0; i < arr.size(); ++i) {
            if(st.find(arr[i] + 1) == st.end()) {
                
            } else {
                count++;
            }
        }
        
        return count;
    }
};