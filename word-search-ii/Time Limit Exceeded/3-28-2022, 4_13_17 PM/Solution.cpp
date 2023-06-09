// https://leetcode.com/problems/word-search-ii

class Solution {
public:
    int visited[200][200];
    bool check_complete_word(vector<vector<char>>& board, int i, int j, int row, int col, string word, int idx, int word_sz) {
        if (i >= row || j >= col || i < 0 || j < 0 || board[i][j] != word[idx] || visited[i][j]==true)
            return false;
        if (idx >= word_sz-1)
            return true;
        visited[i][j] = true;
        bool sol = (check_complete_word(board, i+1, j, row, col, word, idx+1, word.size()) ||
            check_complete_word(board, i, j+1, row, col, word, idx+1, word.size()) ||
            check_complete_word(board, i-1, j, row, col, word, idx+1, word.size()) ||
            check_complete_word(board, i, j-1, row, col, word, idx+1, word.size()));
        visited[i][j] = false;
        return sol;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == word[0])
                    if (check_complete_word(board, i, j, row, col, word, 0, word.size()))
                        return true;
                
            }
        }
        return false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        for(auto word:words)
            if (exist(board, word))
                res.push_back(word);
        return res;
    }
};