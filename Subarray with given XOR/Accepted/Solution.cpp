// https://www.interviewbit.com/problems/subarray-with-given-xor/

int Solution::solve(vector<int> &A, int B) {
    unordered_map<int, int> xorFreq;
    int xorSum = 0;
    int count = 0;
    
    for (int num : A) {
        xorSum ^= num;
        
        if (xorSum == B)
            count++;
        
        if (xorFreq.find(xorSum ^ B) != xorFreq.end())
            count += xorFreq[xorSum ^ B];
        
        xorFreq[xorSum]++;
    }
    
    return count;
}
/*
A = [4, 2, 2, 6, 4]
B = 6
 
100 -> 2
110 -> 1   count = 4
010 -> 1

*/