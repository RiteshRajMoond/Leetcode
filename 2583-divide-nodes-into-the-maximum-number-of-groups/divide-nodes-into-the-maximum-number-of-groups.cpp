class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]); 
    }

    void merge(int u, int v) {
        int par_u = find(u);
        int par_v = find(v);
        if (par_u == par_v) return;

        if (size[par_u] >= size[par_v]) {
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
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n + 1);
        DisjointSet dsu(n + 1);

        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            dsu.merge(edge[0], edge[1]); 
        }

        vector<int> color(n + 1, -1);
        function<bool(int)> is_bipartite = [&](int start) {
            queue<int> q;
            q.push(start);
            color[start] = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int neighbor : graph[node]) {
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    } else if (color[neighbor] == color[node]) {
                        return false; 
                    }
                }
            }
            return true;
        };

        unordered_set<int> unique_components;
        for (int i = 1; i <= n; i++) {
            int rep = dsu.find(i);
            if (unique_components.find(rep) == unique_components.end()) {
                unique_components.insert(rep);
                if (!is_bipartite(i)) return -1;
            }
        }

        auto bfs_depth = [&](int start) {
            queue<int> q;
            vector<int> dist(n + 1, -1);
            q.push(start);
            dist[start] = 1;
            int max_depth = 1;

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int neighbor : graph[node]) {
                    if (dist[neighbor] == -1) {
                        dist[neighbor] = dist[node] + 1;
                        max_depth = max(max_depth, dist[neighbor]);
                        q.push(neighbor);
                    }
                }
            }
            return max_depth;
        };

        int total_groups = 0;
        for (int rep : unique_components) {
            int max_groups = 0;
            for (int i = 1; i <= n; i++) {
                if (dsu.find(i) == rep) {
                    max_groups = max(max_groups, bfs_depth(i));
                }
            }
            total_groups += max_groups;
        }

        return total_groups;
    }
};
