// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/?envType=daily-question&envId=2024-01-24

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
    int res = 0;
    void helper (TreeNode* root, bitset<10> parity) {
        if (!root) return;
        int x=root->val;
        parity[x] = ~parity[x];
        cout << x << " " << parity.count() << endl;
        if (!root->left && !root->right){
            if(parity.count() <= 1) 
                res++;
            return;
        }
        helper(root->left, parity);
        helper(root->right, parity);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        bitset<10> parity=0;
        helper(root, parity);
        return res;
    }
};