// https://leetcode.com/problems/rotate-image

class Solution {
    void swap(int &a, int &b) {
        int t = a;
        a = b;
        b = t;
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        
        for (int i =0;i < N;++i) {
            for (int j =i;j < N;++j) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for (int i =0;i < N;++i) {
            for (int j =0;j < N/2;++j) {
                swap(matrix[i][j],matrix[i][N-1-j]);
            }
        }
        return;
    }
};