// https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int vacancy = 1;
        vector <string> tokens;
        stringstream check1(preorder);
        string intermediate;
        while(getline(check1, intermediate, ','))
        {
            tokens.push_back(intermediate);
        }
        for (int i = 0; i < tokens.size(); ++i) {
            vacancy--;
            //cout << tokens[i] << endl;
            if (vacancy < 0)
                return false;
            if (tokens[i] != "#")
                vacancy +=2;
        }
        return vacancy == 0;
    }
};