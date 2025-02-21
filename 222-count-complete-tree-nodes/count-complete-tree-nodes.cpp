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
    int countNodes(TreeNode* root) {
        if(!root) return 0;

        TreeNode* left = root, *right = root;
        int lft_ht = 0, rgt_ht = 0;

        while(left) {
            lft_ht++;
            left = left->left;
        }
        while(right) {
            rgt_ht++;
            right = right->right;
        }

        if(lft_ht == rgt_ht) return (1 << lft_ht) -1;
        else return 1 + countNodes(root->left) + countNodes(root->right);
    }
};