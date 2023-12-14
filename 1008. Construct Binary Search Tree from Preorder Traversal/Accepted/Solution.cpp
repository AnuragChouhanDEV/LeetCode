// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/

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
    unordered_map<int,int> ma;
    TreeNode* helper(vector<int>& preorder, int pst, int pen, vector<int>& inorder, int ist, int ien) {
        if (pst > pen || ist >ien) return NULL;
        TreeNode* node = new TreeNode(preorder[pst]);
        int pos = ma[preorder[pst]];
        int lft = pos-ist;
        node->left = helper(preorder, pst+1, pst+lft, inorder, ist, pos-1);
        node->right = helper(preorder, pst+lft+1, pen, inorder, pos+1, ien);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        for (int i = 0; i < inorder.size(); ++i) {
            ma[inorder[i]]=i;
        }
        TreeNode* root = helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
        return root;
    }
};

/*
[8,5,1,7,10,12]

 1 5 7 8 10 12
*/