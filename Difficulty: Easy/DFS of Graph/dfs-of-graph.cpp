class Solution {
  public:
    vector<int> path;
    vector<int> vis;
    
    void f(vector<vector<int>>& adj, int node) {
        if(vis[node]) return;
        
        vis[node] = true;
        path.push_back(node);
        
        for(int adj_node : adj[node]) {
            f(adj, adj_node);
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vis.resize(n, false);
        f(adj, 0);
        return path;
    }
};