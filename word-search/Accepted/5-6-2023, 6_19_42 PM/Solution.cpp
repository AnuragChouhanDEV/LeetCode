// https://leetcode.com/problems/word-search

class Solution {
public:
    bool helper(vector<vector<bool>> &visited, string word, int R, int C, int i, int j, int idx, vector<vector<char>>& board) {
        if (idx == word.size()-1)
            return true;
        visited[i][j] = true;
        if (i > 0 && !visited[i-1][j] && board[i-1][j] == word[idx+1] && helper(visited, word, R, C, i-1, j, idx+1, board))
            return true; 
        if (i < R-1 && !visited[i+1][j] && board[i+1][j] == word[idx+1] && helper(visited, word, R, C, i+1, j, idx+1, board))
            return true;
        if (j > 0 && !visited[i][j-1] && board[i][j-1] == word[idx+1] && helper(visited, word, R, C, i, j-1, idx+1, board))
            return true;
        if (j < C-1 && !visited[i][j+1] && board[i][j+1] == word[idx+1] && helper(visited, word, R, C, i, j+1, idx+1, board))
            return true;
        visited[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int R = board.size();
        int C = board[0].size();
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (board[i][j] == word[0])
                    if (helper(visited, word, R, C, i, j, 0, board))
                        return true;
            }
        }
        return false;
    }
};