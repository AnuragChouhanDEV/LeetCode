// https://leetcode.com/problems/unique-binary-search-trees-ii/description/?envType=daily-question&envId=2023-12-03

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
    struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Simple hash function combining the hashes of the two elements
        return h1 ^ h2;
        }
    };
    //map<pair<int,int>, vector<TreeNode*>> ma;
    std::unordered_map<std::pair<int, int>, std::vector<TreeNode*>, pair_hash> ma;
    vector<TreeNode*>  helper(int start, int end) {
        if (start > end) return ma[{start,end}]={NULL};
        if (start == end) {
            TreeNode* root = new TreeNode(start);
            return ma[{start,end}]={root};
        }
        if (ma.find({start,end}) != ma.end()) {
            return ma[{start,end}];
        }
        vector<TreeNode*> res;
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> left = helper(start, i-1);
            vector<TreeNode*> right = helper(i+1, end);
            for (TreeNode* l: left) {
                for (TreeNode* r:right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        return ma[{start,end}]=res;    
    }
    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }
};