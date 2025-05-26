class Solution {
  public:
    vector<bool> vis, dfs_call;
    
    bool is_cycle(int node, vector<vector<int>> & adj) {
        vis[node] = true;
        dfs_call[node] = true;
        
        for(int& nei : adj[node]) {
            if(!vis[nei]) {
                bool cycle = is_cycle(nei, adj);
                if(cycle) return true;
            } else if(dfs_call[nei]) return true;
        }
        
        dfs_call[node] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vis.resize(V, false);
        dfs_call.resize(V, false);
        
        vector<vector<int>> adj(V);
        
        for(auto& edge : edges) adj[edge[0]].push_back(edge[1]);
        
        for(int i = 0; i < V; i++) {
            if (!vis[i]) {if(is_cycle(i, adj)) return true;}
        }
        return false;
    }
};