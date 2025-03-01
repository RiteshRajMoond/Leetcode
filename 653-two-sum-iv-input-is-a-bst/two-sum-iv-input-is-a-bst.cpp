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
    vector<int> inorder;

    void traversal(TreeNode* root) {
        if(!root) return;

        traversal(root->left);
        inorder.push_back(root->val);
        traversal(root->right);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        traversal(root);

        int i = 0, j = inorder.size()-1;

        while(i < j) {
            int sum = inorder[i] + inorder[j];
            if(sum == k) return true;
            else if(sum > k) j--;
            else i++;
        }
        return false;
    }
};