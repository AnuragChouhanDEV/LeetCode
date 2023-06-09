// https://leetcode.com/problems/word-search-ii

class Solution {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    bool solve(vector<vector<char>>& board, int i, int j, int n, int m, string word, int idx) {
        if (idx >= word.size())
            return true;
        for (int k = 0; k < 4; ++k) {
            int x = i+dx[k];
            int y = j+dy[k];
            if (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == word[idx]) {
                board[x][y] = '_';
                if (board, x, y, n, m, word, idx+1) {
                    return true;
                }
                board[i][j] = word[idx];
            }
        }
        return false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        for(auto word:words) {
            bool f = true;
            for (int i = 0; i < board.size() && f== true; ++i) {
                for (int j = 0; j < board[0].size() && f== true; ++j) {
                    if (board[i][j] == word[0]) {
                        board[i][j] = '_';
                        if (solve(board,i,j,board.size(), board[0].size(), word, 1)) {
                            res.push_back(word);
                            f=false;
                        }
                        board[i][j] = word[0];
                    }
                }
            }
        }
        return res;
    }
};