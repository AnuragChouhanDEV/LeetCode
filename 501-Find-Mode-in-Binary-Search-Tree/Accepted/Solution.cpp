// https://leetcode.com/problems/find-mode-in-binary-search-tree/description/?envType=daily-question&envId=2023-11-01

class Solution {
    // with no exta space
public:
    void helper(TreeNode* root, vector<int> &res, int &currfreq, int &maxfreq, int &currele) {
        if (!root)
            return;
        helper(root->left, res, currfreq, maxfreq, currele);
        if (root->val == currele) {
            currfreq++;
        } else {
            currele = root->val;
            currfreq = 1;
        }

        if (currfreq > maxfreq) {
            res = {};
            maxfreq = currfreq;
        }
        if (currfreq == maxfreq)
            res.push_back(root->val);

        helper(root->right, res, currfreq, maxfreq, currele);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int currfreq = 0;
        int maxfreq = 0;
        int currele = 0;
        helper(root, res, currfreq, maxfreq, currele);
        return res;
    }
#if 0 // with extra space
    void helper(TreeNode* root, unordered_map<int,int> &ma) {
        if (root == NULL) return;

        helper(root->left, ma);
        ma[root->val]++;
        helper(root->right, ma);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> ma;
        vector<int> res;
        helper(root, ma);
        int maxfreq = 0;
        for (auto &it:ma) {
            //cout << it.first <<endl;
            if (it.second > maxfreq) {
                maxfreq = it.second;
                res.clear();
                res.push_back(it.first);
            } else if (it.second == maxfreq)
                res.push_back(it.first);
        }
        return res;
    }
#endif
};