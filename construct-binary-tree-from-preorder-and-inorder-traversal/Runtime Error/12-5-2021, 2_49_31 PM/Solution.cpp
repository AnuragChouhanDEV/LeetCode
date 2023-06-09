// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal

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
    int search(vector<int>& in, int strt, int end, char value)
    {
        int i;
        for (i = strt; i <= end; i++)
        {
            if (in[i] == value)
                return i;
        }
        return -1;
    }
    
    TreeNode* buildTreeUtil(vector<int>& pre, vector<int>& in, int inStrt, int inEnd)
    {
        static int preIndex = 0;
        if (inStrt > inEnd)
            return NULL;
        TreeNode* tNode = new TreeNode(pre[preIndex++]);
        if (inStrt == inEnd)
            return tNode;
        int inIndex = search(in, inStrt, inEnd, tNode->val);
        tNode->left = buildTreeUtil(pre, in, inStrt, inIndex - 1);
        tNode->right = buildTreeUtil(pre, in, inIndex + 1, inEnd);
        return tNode;
    }

    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeUtil(preorder, inorder, 0, inorder.size()-1);
    }
};