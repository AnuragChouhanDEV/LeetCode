// https://leetcode.com/problems/average-of-levels-in-binary-tree/

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
    vector<long long> res;
    vector<int> count;
    void helper(TreeNode* root, int lvl) {
        if (!root) return;
        if (res.size() <= lvl) {
            res.push_back(0);
            count.push_back(0);
        }
        res[lvl] += root->val;
        count[lvl]++;
        helper(root->left, lvl+1);
        helper(root->right, lvl+1);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        helper(root, 0);
        for(int i = 0; i < res.size(); ++i) {
            ans.push_back((double)res[i]/count[i]);
        }
        return ans;
#if 0
        vector<double> res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            double sum = 0;
            for (int i = 0; i < size; ++i) {
                TreeNode *node = q.front();
                sum += node->val;
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(sum/size);
        }
        return res;
#endif
    }
};