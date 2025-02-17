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
    multiset<tuple<int, int, int>> st; // col, row, value
    int min_c, max_c;

    void iter(TreeNode* root, int c, int r) {
        if(!root) return;

        st.insert({c, r, root->val});
        min_c = min(min_c, c);
        max_c = max(max_c, c);
        if(root->left) iter(root->left, c-1, r+1);
        if(root->right) iter(root->right, c+1, r+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        min_c = INT_MAX;
        max_c = INT_MIN;
        iter(root, 0, 0);

        vector<vector<int>> res(max_c - min_c + 1);
        for(auto& [col, row, val] : st) {
            res[col - min_c].push_back(val);
        }
        return res;
    }
};