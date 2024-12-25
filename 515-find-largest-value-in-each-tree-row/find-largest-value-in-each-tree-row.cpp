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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};

        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();\
            int mx = INT_MIN;

            for(int i = 0; i < n; i++) {
                auto ft = q.front();
                q.pop();
                mx = max(mx, ft->val);
                if(ft->left) q.push(ft->left);
                if(ft->right) q.push(ft->right);
            }

            res.push_back(mx);
        }
        return res;
    }
};