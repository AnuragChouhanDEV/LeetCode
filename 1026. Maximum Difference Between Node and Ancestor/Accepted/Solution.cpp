// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int,int> helper(TreeNode* root, int &ans) {
        pair<int,int> leftpair;
        pair<int,int> rightpair;
        int val = root->val;
        int mini = root->val;
        int maxi = root->val;

        if (root->left) {
            leftpair = helper(root->left, ans);
            int minleft = leftpair.first;
            int maxleft = leftpair.second;
            ans = max(ans, max(abs(minleft-val), abs(maxleft-val)));
            mini = min(minleft, val);
            maxi = max(maxleft, val);
        }
        if (root->right) {
            rightpair = helper(root->right, ans);
            int minleft = rightpair.first;
            int maxleft = rightpair.second;
            ans = max(ans, max(abs(minleft-val), abs(maxleft-val)));
            mini = min(mini,min(minleft, val));
            maxi = max(maxi,max(maxleft, val));
        }
        return {mini,maxi};
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        helper(root, ans);
        return ans;
    }
};