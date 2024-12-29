class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Initialize the distance matrix
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        
        // Distance from each city to itself is 0
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }
        
        // Fill initial distances from edges
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }
        
        // Floyd-Warshall Algorithm
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        // Count reachable cities for each city within the distance threshold
        int minReachable = n;  // To store the minimum number of reachable cities
        int city = -1;         // To store the city with the minimum reachable cities
        
        for (int i = 0; i < n; ++i) {
            int reachable = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    ++reachable;
                }
            }
            if (reachable < minReachable || (reachable == minReachable && i > city)) {
                minReachable = reachable;
                city = i;
            }
        }
        
        return city;
    }
};
