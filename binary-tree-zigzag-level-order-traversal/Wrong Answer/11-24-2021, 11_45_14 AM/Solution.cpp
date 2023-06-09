// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) 
            return {};
        vector<vector<int>> result;
        queue<TreeNode*> Q;
        Q.push(root);
        int lvl = 0;
        while(!Q.empty()){
            int count = Q.size();
            vector<int> level_nodes;
            for(int i = 0; i < count; ++i){
                TreeNode *node = Q.front();
                Q.pop();
                if (lvl%2 == 1) {
                    if(node->left) Q.push(node->left);
                    if(node->right) Q.push(node->right);
                } else {
                    if(node->right) Q.push(node->right);
                    if(node->left) Q.push(node->left);
                }
                level_nodes.push_back(node->val);
                lvl++;
            }
            result.push_back(level_nodes);
        }
        return result;
    }
};