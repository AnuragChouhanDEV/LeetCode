// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/description/?envType=daily-question&envId=2023-11-02

class Solution {
public:
    // sum, number
    pair<int,int> helper(TreeNode* root, int &count) {
        if (!root)
            return {0,0};
        pair<int,int> left = helper(root->left, count);
        pair<int,int> right = helper(root->right, count);

        int sum = root->val + left.first + right.first;
        int number = 1 + left.second + right.second;
        int avg = sum/number;

        if (avg == root->val) count++;

        return {sum,number};
    }
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        helper(root, count);
        return count;
    }
};