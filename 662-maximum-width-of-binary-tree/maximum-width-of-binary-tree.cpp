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
    int widthOfBinaryTree(TreeNode* root) {
        queue< pair<TreeNode*, long long> > q;
        int width = 0;
        q.push({root, 1});

        while(!q.empty()) {
            int n = q.size();
            int mx = 0, mn = 0;
            long long mn_idx = q.front().second;
            for(int i = 0; i < n; i++) {
                auto [node, idx] = q.front();
                q.pop();

                idx -= mn_idx;

                if(i == 0) mn = idx;
                if(i == n-1) mx = idx;

                if(node->left) {
                    q.push({node->left, 2*idx});
                }
                if(node->right) {
                    q.push({node->right, 2*idx+1});
                }
            }
            width = max(width, mx-mn+1);
        }
        return width;
    }
};