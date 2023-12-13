// https://leetcode.com/problems/deepest-leaves-sum/description/

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
    void helper(TreeNode* root, vector<int> &vec, int lvl) {
        if (!root) return;
        if (vec.size() <= lvl)
            vec.push_back(0);
        vec[lvl] += root->val;
        helper(root->left, vec, lvl+1);
        helper(root->right, vec, lvl+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        vector<int> vec;
        helper(root, vec, 0);
        return vec.back();
#if 0
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        while (!q.empty()) {
            int size = q.size();
            sum = 0;
            while (size--) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return sum;
#endif
    }
};