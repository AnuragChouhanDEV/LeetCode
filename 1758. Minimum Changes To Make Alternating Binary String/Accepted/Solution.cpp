// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description/?envType=daily-question&envId=2023-12-24

class Solution {
public:
    int count(string s, char c_pre) {
        int count = 0;
        for (int i = 1; i < s.length(); i++) {
            char current = s[i];
            if (current == c_pre) {
                count++;
                c_pre = c_pre == '0' ? '1' : '0';
            } else {
                c_pre = current;
            }
        }
        return count;
    }
    int minOperations(string s) {
        char c_0 = s[0];
        int count1 = count(s, c_0);
        int count2 = count(s, c_0 == '0' ? '1' : '0') + 1;
        return min(count1, count2);
    }
};
/*
10010100

Example Explanation
Let's break down the logic using a step-by-step table for better clarity.

Example:
Consider the input string s = "0100".

Index	Character	Current Count (Starting with '0')	Current Count (Starting with '1')
0	0	0	1
1	1	1	1
2	0	1	2
3	0	1	3
Count for starting with '0': 1 operations
Count for starting with '1': 3 operation
The minimum count is 1, which is our result.

Initialize counts:

count1 (starting with '0') = 0
count2 (starting with '1') = 1
Loop through the characters of the string (starting from index 1):
a. At index 1:

Character: 1
For starting with '0', no need to flip, so count1 = 0 (total count1 = 0)
For starting with '1', we need to flip, so count2 +=1 (total count2 = 2)
b. At index 2:

Character: 0
For starting with '0', no need to flip, so count1 remains the same (total count1 = 0)
For starting with '1', we need to flip, so count2 += 1 (total count2 = 3)
c. At index 3:

Character: 0
For starting with '0', we need to flip, so count1 += 1 (total count1 = 1)
For starting with '1', no need to flip, so count2 += 1 (total count2 = 3)
Final counts:

count1 (starting with '0') = 1
count2 (starting with '1') = 3
Return the minimum of count1 and count2, which is 2.

I hope this breakdown helps you understand the logic!
*/