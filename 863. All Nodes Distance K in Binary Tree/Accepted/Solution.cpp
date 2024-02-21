// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void populate_parents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &ma) {
        if (!root) return;
        if (root->left) {
            ma[root->left]=root;
            populate_parents(root->left, ma);
        }
        if (root->right) {
            ma[root->right]=root;
            populate_parents(root->right, ma);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        unordered_map<TreeNode*, TreeNode*> ma;
        unordered_map<TreeNode*, int> visited;
        populate_parents(root, ma);
        ma[root]=NULL;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]++;
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode *node = q.front();
                q.pop();
                if (level > k) break;
                if (level == k) result.push_back(node->val);
                else {
                    if (node->left && visited.count(node->left) == 0) {
                        visited[node->left]++;
                        q.push(node->left);
                    }
                    if (node->right && visited.count(node->right) == 0) {
                        visited[node->right]++;
                        q.push(node->right);
                    }
                    if (ma[node] && visited.count(ma[node]) == 0) {
                        visited[ma[node]]++;
                        q.push(ma[node]);
                    }
                }
            }
            level++;
        }
        return result;
    }
#if 0
    void getkdistanceNodeDown(TreeNode* root, int k, vector<int> &result)
    {
        if (root == NULL || k < 0) return;
        if (k==0){
            result.push_back(root->val);
            return;
        }
        getkdistanceNodeDown(root->left, k-1, result);
        getkdistanceNodeDown(root->right, k-1, result);
    }
    int getkdistanceNode(TreeNode* root, TreeNode* target , int k, vector<int> &result) {
        if (root == NULL) return -1;
        if (root == target){
            getkdistanceNodeDown(root, k, result);
            return 0;
        }
        int dl = getkdistanceNode(root->left, target, k, result);
        if (dl != -1){
            if (dl + 1 == k)
                result.push_back(root->val);
            else
                getkdistanceNodeDown(root->right, k-dl-2, result);
        return 1 + dl;
        }
        int dr = getkdistanceNode(root->right, target, k, result);
        if (dr != -1){
            if (dr + 1 == k)
                result.push_back(root->val);
            else
                getkdistanceNodeDown(root->left, k-dr-2, result);
        return 1 + dr;
        }
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        getkdistanceNode(root, target, k, result);
        return result;
    }
#endif
};