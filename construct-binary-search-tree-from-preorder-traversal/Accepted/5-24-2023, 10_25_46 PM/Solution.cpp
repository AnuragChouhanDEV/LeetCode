// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal

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
    TreeNode* bfp(vector<int>& preorder, int prestart, int preend, vector<int>& inorder, int instart, int inend, unordered_map<int,int> &ma) {
        if (prestart > preend || instart > inend) return NULL;
        TreeNode *root = new TreeNode(preorder[prestart]);
        int newinend = ma[root->val];
        int leftcount = newinend-instart;
        root->left = bfp(preorder, prestart+1, prestart+leftcount, inorder, instart, newinend-1, ma);
        root->right = bfp(preorder, prestart+leftcount+1, preend, inorder, newinend+1, inend, ma);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder(preorder.begin(), preorder.end());
        sort(inorder.begin(), inorder.end());
        unordered_map<int,int> ma;
        for(int i = 0; i < inorder.size();++i) ma[inorder[i]]=i;
        TreeNode* root = bfp(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, ma);
        return root;
    }
};