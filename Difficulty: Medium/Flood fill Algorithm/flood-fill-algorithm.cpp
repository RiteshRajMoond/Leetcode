class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        int n = image.size(), m = image[0].size();
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        int og_color = image[sr][sc];
        
        queue<pair<int, int>> q;
        q.push({sr, sc});
        
        while(!q.empty()) {
            auto ft = q.front();
            q.pop();
            int x = ft.first;
            int y = ft.second;
            
            if(vis[x][y]) continue;
            vis[x][y] = true;
            
            image[x][y] = newColor;
            
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] 
                    && image[nx][ny] == og_color) {
                    q.push({nx, ny});
                }
            }
            
        }
        
        return image;
        
    }
};