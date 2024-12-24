class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n, 0); 
        // 0 -> No Color
        // 1 -> Red
        // 2 -> Yellow

        for (int start = 0; start < n; ++start) {
            if (col[start] != 0) continue;

            queue<pair<int, int>> q; // node, color
            col[start] = 1; 
            q.push({start, 1});

            while (!q.empty()) {
                auto ft = q.front(); q.pop();
                int cur = ft.first;
                int cur_col = ft.second;

                for (int& neighbor : graph[cur]) {
                    if (col[neighbor] == 0) {
                        int ncol = (cur_col == 1) ? 2 : 1; 
                        col[neighbor] = ncol;
                        q.push({neighbor, ncol});
                    } else if (col[neighbor] == cur_col) {
                        return false; 
                    }
                }
            }
        }

        return true;
    }
};
