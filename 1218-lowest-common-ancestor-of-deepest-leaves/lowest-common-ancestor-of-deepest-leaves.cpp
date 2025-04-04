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
    TreeNode* dfs(TreeNode* root, TreeNode* a, TreeNode* b) {
        if (!root || root == a || root == b) return root;

        TreeNode* left = dfs(root->left, a, b);
        TreeNode* right = dfs(root->right, a, b);

        if (left && right) return root;
        return left ? left : right;
    }

public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<TreeNode*> deepest;
        int maxLevel = -1;

        auto bfs = [&](TreeNode* root) -> void {
            queue<pair<TreeNode*, int>> q;
            q.push({root, 0});

            while (!q.empty()) {
                auto [node, level] = q.front();
                q.pop();

                if (level > maxLevel) {
                    maxLevel = level;
                    deepest.clear();
                }
                if (level == maxLevel) {
                    deepest.push_back(node);
                }

                if (node->left) q.push({node->left, level + 1});
                if (node->right) q.push({node->right, level + 1});
            }
        };

        bfs(root);

        TreeNode* lca = deepest[0];
        for (int i = 1; i < deepest.size(); ++i) {
            lca = dfs(root, lca, deepest[i]);
        }

        return lca;
    }
};
