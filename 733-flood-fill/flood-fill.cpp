class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int dx[] = {0, 1, 0, -1}; // u r d l
        int dy[] = {1, 0, -1, 0};

        int og = image[sr][sc];

        if(og == color) return image;

        queue<pair<int, int>> q; // r, c, color
        q.push({sr, sc});

        while(!q.empty()) {
            auto ft = q.front();
            q.pop();

            int x = ft.first;
            int y = ft.second;
            image[x][y] = color;
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < n && nx >= 0 && ny < m && ny >= 0 && image[nx][ny] == og){
                    q.push({nx, ny});
                    image[nx][ny] = color;
                }
            }
        }

        return image;
    }
};