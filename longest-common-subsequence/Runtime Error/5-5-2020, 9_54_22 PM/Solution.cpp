// https://leetcode.com/problems/longest-common-subsequence

class Solution {
    int max(int a, int b) 
    { 
	    return (a > b)? a : b; 
    } 
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        int i,j;
        stack<char> s;
        
        int L[m+1][n+1];
        
        for (i = 0; i <= m; i++) 
	    { 
		    for (j = 0; j <= n; j++) 
    		{ 
	    	    if (i == 0 || j == 0) 
		    	    L[i][j] = 0; 
                else if (text1[i - 1] == text2[j - 1]) 
        			L[i][j] = L[i - 1][j - 1] + 1; 
	        	else
		        	L[i][j] = max(L[i - 1][j], L[i][j - 1]); 
		    } 
	    }
        for (i = m; i > 0;) 
	    { 
		    for (j = n; j > 0;) 
    		{
                if (L[i-1][j-1] == L[i-1][j] && L[i-1][j-1] == L[i][j-1] && L[i][j] > L[i-1][j-1]) {
                    s.push(i);
                    //printf("%d \n", s.top());
                    //printf("%c ", text1[i-1]);
                    --i;
                    --j;
                } else if (L[i-1][j-1] == L[i-1][j] && L[i-1][j-1] == L[i][j-1] && L[i][j] == L[i-1][j-1]) {
                    --i;
                    --j;
                } else if (L[i-1][j-1] != L[i-1][j] && L[i][j] == L[i-1][j]) {
                    --i;
                } else if (L[i-1][j-1] != L[i][j-1] && L[i][j] == L[i][j-1]) {
                    --j;
                }
            }
            //printf("\n");
        }
        while(!s.empty()) {
            printf("%c", text1[s.top()-1]);
            s.pop();
        }
        return L[m][n];
    }
};