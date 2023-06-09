// https://leetcode.com/problems/n-queens

class Solution {
public:
    bool is_safe(int row, int col, vector<string> &board, int n) {
        int tr = row;
        int tc = col;
        while (tr >= 0 && tc >= 0) {
            if (board[tr][tc] == 'Q')
                return false;
            tr--;tc--;
        }
        tr = row;
        tc = col;
        while (tr >= 0 && tc >= 0) {
            if (board[tr][tc] == 'Q')
                return false;
            tc--;
        }
        tr = row;
        tc = col;
        while (tr < n && tc >= 0) {
            if (board[tr][tc] == 'Q')
                return false;
            tc--;
            tr++;
        }
        return true;
    }
    void helper(int col, vector<vector<string>> &res, vector<string> &board, int n) {
        if (col == n) {
            res.push_back(board);
            return;
        }
        for (int row = 0; row < n; ++row) {
            if (is_safe(row, col, board, n)) {
                board[row][col] = 'Q';
                helper(col+1, res, board, n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n);
        string s(n,'.');
        for (int i = 0; i < n; ++i) {
            board[i]=s;
        }
        helper(0, res, board, n);
        return res;
    }
};