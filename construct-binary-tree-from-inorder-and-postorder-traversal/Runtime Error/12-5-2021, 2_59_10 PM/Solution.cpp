// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal

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
    
    TreeNode* buildTreeUtil(vector<int>& post, vector<int>& in, int inStrt, int inEnd)
    {
        static int postIndex = post.size()-1;
        if (inStrt > inEnd)
            return NULL;
        TreeNode* tNode = new TreeNode(post[postIndex--]);
        if (inStrt == inEnd)
            return tNode;
        int inIndex = search(in, inStrt, inEnd, tNode->val);
        tNode->right = buildTreeUtil(post, in, inIndex + 1, inEnd);
        tNode->left = buildTreeUtil(post, in, inStrt, inIndex - 1);
        return tNode;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeUtil(postorder, inorder, 0, inorder.size()-1);
    }
};