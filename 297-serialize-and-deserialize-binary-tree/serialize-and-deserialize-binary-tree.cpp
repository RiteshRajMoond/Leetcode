/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string tree = "";

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            auto ft = q.front();
            q.pop();

            if(ft) {
                tree += to_string(ft->val) + "*";
                q.push(ft->left);
                q.push(ft->right);
            } else tree += "$*";
        }

        return tree;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return nullptr;

        stringstream ss(data);
        string val;
        getline(ss, val, '*');

        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            auto ft = q.front();
            q.pop();

            if(getline(ss, val, '*') && val != "$") {
                ft->left = new TreeNode(stoi(val));
                q.push(ft->left);
            }

            if(getline(ss, val, '*') && val != "$") {
                ft->right = new TreeNode(stoi(val));
                q.push(ft->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));