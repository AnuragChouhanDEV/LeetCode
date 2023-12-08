// https://leetcode.com/problems/construct-string-from-binary-tree/description/?envType=daily-question&envId=2023-12-08

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
    string tree2str(TreeNode* root) {
        if (!root) return "";
        string res = to_string(root->val);
        
        string left = tree2str(root->left);
        string right = tree2str(root->right);

        if (!root->left && !root->right) {
          return res;
        }
        if (!root->left) {
          return res + "()" + "(" + right + ")";
        }
        if (!root->right) {
          return res  + "(" + left + ")";
        }
        
        return res + "(" + left + ")" + "(" + right + ")";
    }
};