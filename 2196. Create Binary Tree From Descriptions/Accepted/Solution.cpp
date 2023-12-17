// https://leetcode.com/problems/create-binary-tree-from-descriptions/description/

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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>ma;
        unordered_map<int,int>mp;
       
        for(int i=0;i < descriptions.size(); i++){
            int p = descriptions[i][0];
            int c = descriptions[i][1];
            int left = descriptions[i][2];
            TreeNode* parent = NULL;
            TreeNode* child = NULL;
            // check for parent nad create parent node
            if(ma.find(p) == ma.end()) { parent = new TreeNode(p); ma[p]=parent;                      
            } else { parent = ma[p]; }
            // check for child and create child node, increase parent for child
            if(ma.find(c) == ma.end()) { child = new TreeNode(c); ma[c]=child; mp[c]++;
            } else { child = ma[c]; mp[c]++;
            }
            // assign child to parent
            if (left) { parent->left = child;
            } else { parent->right = child; }
        }
        // check all the parents and see if there is any parent for it or not
        for(int i=0;i<descriptions.size();i++){
            if(mp[descriptions[i][0]]==0){
                return ma[descriptions[i][0]];
            }
        }
        return NULL;
    }
};