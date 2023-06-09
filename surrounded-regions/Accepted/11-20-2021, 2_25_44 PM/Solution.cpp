// https://leetcode.com/problems/surrounded-regions

class Solution {
public:
    void fill_util(vector<vector<char>>& board, int i, int j, char ch1, char ch2) {
        int M = board.size();
        int N = board[0].size();
        //cout << i << " " << j << endl;
        if (i >= M || i < 0 || j >= N || j < 0)
            return;
        if (board[i][j] != ch1)
            return;
        board[i][j] = ch2;
        //cout << "came here " << endl;
        fill_util(board, i+1, j, '-', 'O');
        fill_util(board, i-1, j, '-', 'O');
        fill_util(board, i, j+1, '-', 'O');
        fill_util(board, i, j-1, '-', 'O');
    }
    void solve(vector<vector<char>>& board) {
        int M = board.size();
        int N = board[0].size();
        for (int i=0; i<M; i++)
            for (int j=0; j<N; j++)
                if (board[i][j] == 'O')
                    board[i][j] = '-';
        
        for (int i=0; i<M; i++)   // Left side
            if (board[i][0] == '-')
                fill_util(board, i, 0, '-', 'O');
        for (int i=0; i<M; i++)  //  Right side
            if (board[i][N-1] == '-')
                fill_util(board, i, N-1, '-', 'O');
        for (int i=0; i<N; i++)   // Top side
            if (board[0][i] == '-')
                fill_util(board, 0, i, '-', 'O');
        for (int i=0; i<N; i++)  // Bottom side
            if (board[M-1][i] == '-')
                fill_util(board, M-1, i, '-', 'O');
#if 0 
        for (int i=0; i<M; i++)
        {
            for (int j=0; j<N; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
#endif
        for (int i=0; i<M; i++)
            for (int j=0; j<N; j++)
                if (board[i][j] == '-')
                    board[i][j] = 'X';
    }
};