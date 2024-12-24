class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& preq) {
        vector<vector<int>> adj(n);
        for(auto& i : preq) {
            adj[i[1]].push_back(i[0]);
        }

        vector<int> indeg(n, 0);
        for(auto& i : adj) {
            for(int&j : i) indeg[j]++;
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

        return (res.size() == n) ? res : vector<int>();
    }
};