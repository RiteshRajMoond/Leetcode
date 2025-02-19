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
    bool is_sym(TreeNode* r1, TreeNode* r2) {
        if(!r1 && !r2) return true;
        if(!r1 || !r2) return false;

        if(r1->val != r2->val) return false;

        return is_sym(r1->left, r2->right) && is_sym(r1->right, r2->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return is_sym(root->left, root->right);
    }
};