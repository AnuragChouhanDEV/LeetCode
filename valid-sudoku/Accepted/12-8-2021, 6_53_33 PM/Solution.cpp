// https://leetcode.com/problems/valid-sudoku

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int len = board.size();
        unordered_set<string> s;
        for (int i = 0; i < len;++i) {
            for (int j = 0; j < len;++j) {
                if (board[i][j] == '.')
                    continue;
                string ch(1,board[i][j]);
                string row = "row" + to_string(i) + ch;
                string col = "col" + to_string(j) + ch;
                string box = "box" + to_string(i/3) + to_string(j/3) + ch;
                //cout << row << endl;
                if (s.find(row) != s.end() || s.find(col) != s.end() || s.find(box) != s.end()) {
                    return false;
                } else {
                    s.insert(row);
                    s.insert(col);
                    s.insert(box);
                }
            }
        }
        return true;
    }
};