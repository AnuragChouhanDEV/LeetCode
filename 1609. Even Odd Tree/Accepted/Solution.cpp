// https://leetcode.com/problems/even-odd-tree/description/?envType=daily-question&envId=2024-02-29

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
    bool isEvenOddTree(TreeNode* root) {        
        if(root==NULL){
            return true;
        }
        queue<TreeNode*>q;
        bool flag=true;
        q.push(root);
        while(!q.empty()){
            int size = q.size() ;
            int prev = flag ? 0 : 1000001;
            while (size--) {
                TreeNode* frontNode = q.front();
                q.pop();  
                if(flag){
                    if(frontNode->val %2==0 || frontNode->val <=  prev){
                        return false;
                    }
                }
                else{
                    if(frontNode->val %2!=0  || frontNode->val  >= prev){
                        return false;
                    }
                }

                if(frontNode->left){
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    q.push(frontNode->right);
                }
                prev= frontNode->val;
            }
            flag=!flag;
        }
        return true;
    }
};