// https://leetcode.com/problems/two-sum-iv-input-is-a-bst

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
    int inorder(TreeNode *root, int &k, set<int> &s) {
        if (!root)
            return -1;
        inorder(root->left, k, s);
        //cout << k << " " << root->val << endl;
        if (s.find(k - root->val) != s.end())
            return 0;
        
        s.insert(root->val);
        return inorder(root->right, k, s);
     }
    bool findTarget(TreeNode* root, int k) {
        set<int> s;
        if (inorder(root, k, s) == 0)
            return true;
        return false;
    }
};