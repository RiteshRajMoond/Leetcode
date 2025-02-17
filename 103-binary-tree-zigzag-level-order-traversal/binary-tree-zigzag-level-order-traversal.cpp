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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigzag;
        if(!root) return zigzag;

        queue<TreeNode*> q;
        q.push(root);
        bool ltr = true;

        while(!q.empty()) {
            int n = q.size();

            vector<int> cur;
            for(int i = 0; i < n; i++) {
                auto ft = q.front();
                q.pop();

                if(ft->left) q.push(ft->left);
                if(ft->right) q.push(ft->right);

                cur.push_back(ft->val);
            }
            
            if(!ltr) reverse(cur.begin(), cur.end());
            ltr = !ltr;
            zigzag.push_back(cur);
        }
        return zigzag;
    }
};