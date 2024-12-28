class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        // dist, row, col
        priority_queue< tuple<int, int, int>, vector<tuple<int, int, int>>, greater <tuple<int, int, int>> > pq;
        vector<vector<int>> mn(n, vector<int> (m, INT_MAX));

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        pq.push({0, 0, 0});
        mn[0][0] = 0;

        while(!pq.empty()){
            auto ft = pq.top(); pq.pop();
            int x = get<1> (ft);
            int y = get<2> (ft);
            int d = get<0> (ft);

            if(x == n-1 && y == m-1) return d;

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    int nd = max(d, abs(heights[x][y] - heights[nx][ny]));
                    if(mn[nx][ny] > nd) {
                        mn[nx][ny] = nd;
                        pq.push({nd, nx, ny});
                    }
                }

            }
        }

        return -1;
    }
};