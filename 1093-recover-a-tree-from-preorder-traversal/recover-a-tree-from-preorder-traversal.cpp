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
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> st; // maintains a path from root to node
        int n = traversal.size();
        int i = 0;

        while(i < n) {
            // calc level
            int lvl = 0;
            while(i < n && traversal[i] == '-') {
                lvl++;
                i++;
            }

            // calc value
            int value = 0;
            while(i < n && isdigit(traversal[i])) {
                value = value * 10 + traversal[i] - '0';
                i++;
            }

            // create node
            TreeNode* node = new TreeNode(value);

            // go to the correct depth
            while(st.size() > lvl) st.pop();

            if(!st.empty()) {
                if(!st.top()->left) {
                    st.top()->left = node;
                } else 
                    st.top()->right = node;
            }

            st.push(node);
        }

        // fetching root;
        while(st.size() != 1) st.pop();

        return st.top();
    }
};