/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    unordered_map<int, int> mp; // ele -> idx

    TreeNode* build_tree(vector<int>& preorder, int pre_s, int pre_e, int pos_s,
                         int pos_e) {
        if (pre_s > pre_e || pos_s > pos_e) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[pre_s]);
        if(pre_s == pre_e) return root;

        int left_root_value = preorder[pre_s + 1];
        int left_root_idx = mp[left_root_value];
        int left_size = left_root_idx - pos_s + 1;

        root->left = build_tree(preorder, pre_s + 1, pre_s + left_size, pos_s,
                                left_root_idx);
        root->right = build_tree(preorder, pre_s + left_size + 1, pre_e,
                                 left_root_idx + 1, pos_e - 1);

        return root;
    }

public:
    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
        int n = preorder.size();

        for (int i = 0; i < n; i++) {
            mp[postorder[i]] = i;
        }

        return build_tree(preorder, 0, n - 1, 0, n - 1);
    }
};