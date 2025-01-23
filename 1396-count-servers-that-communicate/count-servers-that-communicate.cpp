class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }

    int findUPar(int num) {
        if(parent[num] == num) return num;
        return parent[num] = findUPar(parent[num]);
    }

    // attach smaller to larger
    void unionBySize(int u, int v) {
        int par_u = findUPar(u);
        int par_v = findUPar(v);

        if(par_u == par_v) return;

        if(size[par_u] > size[par_v]) {
            parent[par_v] = par_u;
            size[par_u] += size[par_v];
        } else {
            parent[par_u] = par_v;
            size[par_v] += size[par_u];
        }
    }
};

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        DisjointSet ds(m*n);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    ds.unionBySize(i, m+j);
                }
            }
        }

        unordered_map<int, int> mp; // parent-nodes i.e How many nodes have this node as a parent
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) {
                    int parent = ds.findUPar(i);
                    mp[parent]++;
                }
            }
        }

        int cnt = 0;
        for(auto& [parent, size]: mp) {
            if(size > 1) cnt += size;
        }
        return cnt;
    }
};