class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& preq) {
        vector<vector<int>> adj(n);

        for(auto& i : preq) {
            adj[i[1]].push_back(i[0]);
        }

        // Using Kahn Algorithm
        vector<int> indeg(n);

        for(auto& i : adj) {
            for(int& j : i) indeg[j]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indeg[i] == 0) q.push(i);
        }

        int cnt = 0;
        while(!q.empty()) {
            int ft = q.front();
            q.pop();
            cnt++;

            for(int& i: adj[ft]) {
                indeg[i]--;
                if(indeg[i] == 0) q.push(i);
            }
        }

        return cnt == n;
    }
};