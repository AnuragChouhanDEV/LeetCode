// https://leetcode.com/problems/delete-node-in-a-bst

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
    TreeNode *min_value_node(TreeNode *root) {
        if (!root)
            return NULL;
        while (root->left)
            root = root->left;
        //cout << "min value node is " << root->val<<endl;
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return root;
        if (root->val == key) {
            //cout << "node found" << endl;
            if (!root->left && !root->right)
                return NULL;
            else if (!root->left) {
                TreeNode *tmp = root->right;
                delete root;
                return tmp;
            } else if (!root->right) {
                TreeNode *tmp = root->left;
                delete root;
                return tmp;
            }
            TreeNode *tmp = min_value_node(root->right);
            root->val = tmp->val;
            root->right = deleteNode(root->right, root->val);
            return root;
        } else if (root->val < key) {
            //cout << "node in right" << endl;
            root->right = deleteNode(root->right, key);
        } else {
            //cout << "node in left" << endl;
            root->left = deleteNode(root->left, key);
        }
        return root;
    }
};