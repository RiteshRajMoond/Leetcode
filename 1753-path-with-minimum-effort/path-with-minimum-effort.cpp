class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue< tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > pq;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dis(n, vector<int> (m, INT_MAX));

        pq.push({0, 0, 0}); // dis, r, c
        dis[0][0] = 0;

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        while(!pq.empty()) {
            auto tp = pq.top();
            pq.pop();

            int d = get<0> (tp);
            int x = get<1> (tp);
            int y = get<2> (tp);

            if(x == n-1 && y == m-1) return d;

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    int nd = max(d, abs(heights[x][y] - heights[nx][ny]));
                    if(nd < dis[nx][ny]) {
                        dis[nx][ny] = nd;
                        pq.push({nd, nx, ny});
                    }
                }
            }
        }

        return -1;
    }
};