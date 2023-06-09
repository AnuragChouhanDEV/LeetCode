// https://leetcode.com/problems/sudoku-solver

class Solution {
public:
    vector<int> find_border(int id) {
        vector<int> res(2,0);
        if (id < 3) {
            res[0] = 0;
            res[1] = 2;
        } else if (id < 6) {
            res[0] = 3;
            res[1] = 5;
        } else {
            res[0] = 6;
            res[1] = 8;
        }
        return res;
    }
    bool is_valid(vector<vector<char>>& board, int row, int col, char ch) {
        for (int i = 0; i < 9; ++i) {
            if (board[i][col] == ch)
                return false;
            if (board[row][i] == ch)
                return false;
        }
        //cout << "here 4" << endl;
        vector<int> row_border = find_border(row);
        vector<int> col_border = find_border(col);
        //cout << "here 5" << row_border[0] << " " << row_border[1] << endl;
        for (int i = row_border[0]; i <= row_border[1]; ++i) {
            for (int j = col_border[0]; j <= col_border[1]; ++j) {
                if (board[i][j] == ch)
                    return false;
            }
        }
        return true;
    }
    bool dfs(vector<vector<char>>& board, int row, int col) {
        if (col == 9) {
            col = 0;
            row += 1;
        }
        if (row == 9)
            return true;
        if (board[row][col] != '.')
            return dfs(board, row, col+1);
        
        for (char i = '1'; i <= '9'; ++i) {
            if (!is_valid(board, row, col, i))
                continue;
            //cout << "here 2" << endl;
            board[row][col] = i;
            if (dfs(board, row, col+1))
                return true;
            //cout << "here 3" << endl;
            board[row][col] = '.';
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board, 0,0);       
    }
};