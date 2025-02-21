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

    TreeNode* build_tree(vector<int>& preorder, int lft, int rgt) {
        if(lft > rgt) return nullptr;
        int root_val = preorder[root_idx++];

        TreeNode* root = new TreeNode(root_val);

        root->left = build_tree(preorder, lft, mp[root_val]-1);
        root->right = build_tree(preorder, mp[root_val]+1, rgt);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        for(int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

        TreeNode* root = build_tree(preorder, 0, n-1);
        return root;
    }
};