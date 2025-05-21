/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        // We can do a level order traveral for this and store 
        // the first element
        vector<int> res;
        
        if(!root) return res;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            Node* temp = q.front();
            int sz = q.size();
            
            for(int i = 0; i < sz; i++) {
                Node* ft = q.front();
                q.pop();
                if(ft->left) q.push(ft->left);
                if(ft->right) q.push(ft->right);
            }
            
            res.push_back(temp->data);
        }
        
        return res;
    }
};