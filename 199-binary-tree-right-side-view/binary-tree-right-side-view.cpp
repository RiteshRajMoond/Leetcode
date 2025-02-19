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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> right_side;
        if(!root) return right_side;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            TreeNode* last;
            for(int i = 0; i < n; i++) {
                auto ft = q.front(); q.pop();
                last = ft;
                if(ft->left) q.push(ft->left);
                if(ft->right) q.push(ft->right);
            }
            right_side.push_back(last->val);
        }
        return right_side;
    }
};