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
    TreeNode* p;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        queue<TreeNode*> q;
        q.push(root);
        string s = "";
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *tmp = q.front();
                q.pop();
                if (tmp->val == 1002) {
                    s += "N,";
                    continue;
                }
                s += to_string(tmp->val)+',';
                if (tmp->left) {
                    q.push(tmp->left);
                } else {q.push(new TreeNode(1002));}
                if (tmp->right) {
                    q.push(tmp->right);
                } else {q.push(new TreeNode(1002));}
            }
        }
        cout << s << endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *tmp = q.front();
            q.pop();

            getline(s,str,',');
            if (str == "N") tmp->left = NULL;
            else {
                tmp->left = new TreeNode(stoi(str));
                q.push(tmp->left);
            }

            getline(s,str,',');
            if (str == "N") tmp->right = NULL;
            else {
                tmp->right = new TreeNode(stoi(str));
                q.push(tmp->right);
            }

        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));