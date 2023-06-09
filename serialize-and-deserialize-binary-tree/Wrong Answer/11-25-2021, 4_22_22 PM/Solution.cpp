// https://leetcode.com/problems/serialize-and-deserialize-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        if (!root)
            return s;
        queue<TreeNode *> q;
        q.push(root);
        int i = 0;
        while (!q.empty()) {
            TreeNode *node = q.front();
            if (node) {
                //cout << node->val << endl;
                s.push_back(node->val);
            } else {
                //cout << "NULL " << endl;
                s.push_back('x');
            }
            q.pop();
            //if (node->left == NULL && node->right == NULL)
            //    continue;
            if (node) {
                if(node->left)
                    q.push(node->left);
                else
                    q.push(NULL);
                if(node->right)
                    q.push(node->right);
              else
                    q.push(NULL);
            }
        }
        //cout << s << endl;
        return s;
    }
    TreeNode* InsertNode(TreeNode* root, char data)
    {
        queue<TreeNode*> q;
        q.push(root);
         while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
             if (temp->left != NULL)
                q.push(temp->left);
            else {
                if (data == 'x')
                    temp->left = new TreeNode(1001);
                else
                    temp->left = new TreeNode(data);
                return root;
            }
             if (temp->right != NULL)
                q.push(temp->right);
            else {
                if (data == 'x')
                    temp->right = new TreeNode(1001);
                else
                    temp->right = new TreeNode(data);
                return root;
            }
        }
        return root;
    }
    void inorder(TreeNode *root) {
        if (!root)
            return;
        inorder(root->left);
        if (root->left) {
            if (root->left->val == 1001) {
                delete root->left;
                root->left = NULL;
            }   
        }
        if (root->right) {
            if (root->right->val == 1001) {
                delete root->right;
                root->right = NULL;
            }   
        }
        inorder(root->right);
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0)
            return NULL;
        TreeNode* root = new TreeNode(data[0]);
        //cout << data<<endl;
        for (int i = 1; i < data.size(); ++i) {
            //cout << data[i] << " ";
            root = InsertNode(root, data[i]);          
        }
        inorder(root);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));