// https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int vacancy = 1;
        for (int i = 0; i < preorder.size(); ++i) {
            if (preorder[i] == ',')
                continue;
            vacancy--;
            if (vacancy < 0)
                return false;
            if (preorder[i] != '#')
                vacancy +=2;
        }
        return vacancy == 0;
    }
};