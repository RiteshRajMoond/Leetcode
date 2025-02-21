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
    unordered_map<int, int> mp; // ele -> idx
    int root_idx;

    TreeNode* build_tree(vector<int>& postorder, int lft, int rgt) {
        if(lft > rgt) return nullptr;

        int root_val = postorder[root_idx--];
        TreeNode* root = new TreeNode(root_val);
        root->right = build_tree(postorder, mp[root_val]+1, rgt);
        root->left = build_tree(postorder, lft, mp[root_val]-1);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        root_idx = n-1;

        for(int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

        return build_tree(postorder, 0, n-1);
    }
};