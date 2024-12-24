class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);

        vector<int> indeg(n, 0);
        for(int i = 0; i < n; i++) {
            for(int& j : graph[i]) {
                adj[j].push_back(i);
                indeg[i]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indeg[i] == 0) q.push(i);
        }

        vector<int> res;
        while(!q.empty()) {
            int ft = q.front();
            q.pop();
            res.push_back(ft);

            for(int& i : adj[ft]) {
                indeg[i]--;
                if(indeg[i] == 0) q.push(i);
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};