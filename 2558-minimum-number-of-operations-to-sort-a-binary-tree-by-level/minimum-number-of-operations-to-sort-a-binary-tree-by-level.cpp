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
    int minimumOperations(TreeNode* root) {
        int res = 0;

        auto num_swaps = [&](vector<int>& a) -> void {
            unordered_map<int, int> mp; // ele ->idx
            for(int i = 0; i < a.size(); i++) mp[a[i]] = i;

            vector<int> temp = a;
            sort(temp.begin(), temp.end());

            for(int i = 0; i < a.size(); i++) {
                if(a[i] != temp[i]) {
                    int idx = mp[temp[i]];
                    swap(a[i], a[idx]);
                    mp[a[idx]] = idx;
                    mp[a[i]] = i;
                    res++;
                }
            }
        };

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            vector<int> lvl;
            for(int i = 0; i < n; i++) {
                auto ft = q.front(); q.pop();
                if(ft->left) lvl.push_back(ft->left->val), q.push(ft->left);
                if(ft->right) lvl.push_back(ft->right->val), q.push(ft->right);
            }

            num_swaps(lvl);
        }

        return res;
    }
};