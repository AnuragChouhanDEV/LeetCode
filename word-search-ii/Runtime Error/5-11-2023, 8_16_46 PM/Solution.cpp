// https://leetcode.com/problems/word-search-ii

class Solution {
public:
    void find_word(int R, int C, int idx, vector<vector<bool>>& visited, string &word, unordered_set<string> &res, vector<vector<char>>& board, int x, int y) {
        if (idx == word.size()) {
            res.insert(word);
            return;
        }
        if (x < 0 || y < 0 || x > R || y > C || visited[x][y] )
            return;
        

        if (word[idx] == board[x][y]) {

            visited[x][y] = 1;
            if (x > 0) find_word(R, C, idx+1, visited, word, res, board, x-1, y);
            if (y > 0) find_word(R, C, idx+1, visited, word, res, board, x, y-1);
            if (x < R) find_word(R, C, idx+1, visited, word, res, board, x+1, y);
            if (y < C) find_word(R, C, idx+1, visited, word, res, board, x, y+1);
        }

    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_set<string> res;
        
        int R = board.size();
        int C = board[0].size();
        
        for (auto word:words) {
            vector<vector<bool>> visited(R, vector<bool> (C, 0));

            for (int i = 0; i < R; ++i) {
                for (int j = 0; j < C; ++j) {
                    //cout << "word[0] " <<word[0] << endl;
                    if (word[0] == board[i][j])
                        find_word(R, C, 0, visited, word, res, board, i, j);
                }
            }
        }
        vector<string> result(res.begin(), res.end());
        return result;
    }
};