// https://leetcode.com/problems/binary-tree-level-order-traversal-ii

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> stack;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int count = q.size();
            vector<int> tmp;
            for (int i = 0; i < count; ++i) {
                TreeNode *Node = q.front();
                q.pop();
                tmp.push_back(Node->val);
                if (Node->left)
                    q.push(Node->left);
                if (Node->right)
                    q.push(Node->right);
            }
            stack.push_back(tmp);
        }
        for (int i = 0, j = stack.size()-1; i < j; ++i, --j) {
            swap(stack[i],stack[j]);
        }
        return stack;
    }
};