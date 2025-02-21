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
class FindElements {
    unordered_set<int> st;

    void initialise_tree(TreeNode* root, int x) { 
        if(!root) return;

        root->val = x;
        st.insert(x);
        if(root->left) initialise_tree(root->left, 2*x+1);
        if(root->right) initialise_tree(root->right, 2*x+2);
    }
public:
    FindElements(TreeNode* root) {
        initialise_tree(root, 0);
    }
    
    bool find(int target) {
        return st.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */