class DisjointSet {
    public:
    vector<int> parent, rank, size;
        // constructor
        DisjointSet(int n) {
            parent.resize(n+1);
            rank.resize(n+1, 1);
            size.resize(n+1, 1);
            for(int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        // Ultimate parent: The root of the tree is the ultimate parent of all the nodes
        int findUPar(int node) {
            if(parent[node] == node) return node;
            // Path Compression
            return parent[node] = findUPar(parent[node]);
        }

        // Union By Rank: The tree with smaller height is attached to the tree with larger height
        void unionByRank(int u, int v) {
            int par_u = findUPar(u);
            int par_v = findUPar(v);

            // Both nodes are already in the same set
            if(par_u == par_v) return;

            if(rank[par_u] < rank[par_v]) {
                // rank of par_u is leser therefore we attach par_u to par_v
                parent[par_u] = par_v;
                // As smaller rank is attached to larger rank, the rank of par_v remains same
            } else if(rank[par_u] > rank[par_v]) {
                // rank of par_v is leser therefore we attach par_v to par_u
                parent[par_v] = par_u;
            } else {
                // Both have same rank therefore we cnan attach anyone to other
                // Also as both have same rank, therefore the rank of parent will increase by 1
                parent[par_v] = par_u;
                rank[par_u]++; 
            }
        }

        void unionBySize(int u, int v) {
            int par_u = findUPar(u);
            int par_v = findUPar(v);

            // Both nodes are already in the same set
            if(par_u == par_v) return;

            // Here we attach the tree with smaller size to the tree with larger size
            if(size[par_u] < size[par_v]) {
                // size of par_u is leser therefore we attach par_u to par_v
                parent[par_u] = par_v;
                size[par_v] += size[par_u];
            } else {
                // size of par_v is leser therefore we attach par_v to par_u
                parent[par_v] = par_u;
                size[par_u] += size[par_v];
            }
        }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        // Creating Disjoint Set
        int casual = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) continue;
                casual++;
                for(int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if(ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 1) {
                        int node = i*n+j;
                        int adj_node = ni*n+nj;
                        ds.unionBySize(node, adj_node);
                    }
                }
            }
        }
        if(casual == n*n) return casual;

        // Trying all combinations
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) continue;
                set<int> st;
                for(int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if(ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 1)  {
                        int adj_node = ni*n+nj;
                        st.insert(ds.findUPar(adj_node));
                    }
                    int size = 0;
                    for(auto& cp : st) {
                        size += ds.size[cp];
                    }
                    res = max(res, size+1);
                }
            }
        }
        return res;
    }
};