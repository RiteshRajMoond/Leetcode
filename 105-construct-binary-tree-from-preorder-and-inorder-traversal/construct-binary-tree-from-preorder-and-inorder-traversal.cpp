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
    unordered_map<int, int> mp;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;
        int rootIdx = 0;
        return built_tree(preorder, 0, inorder.size()-1, rootIdx);
    }
private:
    TreeNode* built_tree(vector<int>& preorder, int left, int right, int& rootIdx) {
        if(left > right) return nullptr;

        int root_value = preorder[rootIdx++];
        TreeNode* root = new TreeNode(root_value);
        root->left = built_tree(preorder, left, mp[root_value]-1, rootIdx);
        root->right = built_tree(preorder, mp[root_value]+1, right, rootIdx);
        return root;
    }
};