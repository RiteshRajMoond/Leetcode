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
    TreeNode* prev;
    TreeNode* first;
    TreeNode* second;
    TreeNode* next;

    void inorder(TreeNode* root) {
        if(!root) return;

        inorder(root->left);

        if(prev != nullptr && prev->val > root->val) {
            if(!first) {
                first = prev;
                next = root;
            } else {
                second = root;
            }
        }

        prev = root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        prev = first = second = next = nullptr;
        inorder(root);
        if(second) swap(first->val, second->val);
        else swap(first->val, next->val);
    }
};