// https://leetcode.com/problems/n-queens-ii/description/

class Solution {
public:
    int solve(vector<bool>& col, vector<bool>& diag, vector<bool>& anti_diag, int row) {
	    int n = col.size();
        int count = 0;
        if(row == n) return 1;
	    for(int column = 0; column < n; column++)           
		    if(!col[column] && !diag[row + column] && !anti_diag[row - column + n - 1]) { 
    			col[column] = diag[row + column] = anti_diag[row - column + n - 1] = true;
	    		count += solve(col, diag, anti_diag, row + 1); 
		    	col[column] = diag[row + column] = anti_diag[row - column + n - 1] = false; 
		    }                                
	    return count;
    }
    int totalNQueens(int n) {
        vector<bool> col(n); 
        vector<bool> diag(2*n-1);
        vector<bool> anti_diag(2*n-1);
	    return solve(col, diag, anti_diag, 0);
    }
};

/*
    00  01  02  03
    10  11  12  13
    20  21  22  23
    30  31  32  33

 \   |   /
 -       -
 /   |   \
*/