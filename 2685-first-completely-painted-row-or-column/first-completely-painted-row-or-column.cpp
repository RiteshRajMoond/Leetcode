class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int, pair<int, int>> mp;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                mp[mat[i][j]] = {i, j};
            }
        }

        vector<int> row(m, 0);
        vector<int> col(n, 0);

        for(int i = 0; i < m*n; i++) {
            int x = mp[arr[i]].first, y = mp[arr[i]].second;
            row[x]++, col[y]++;

            if(row[x] == n || col[y] == m) return i;
        }

        return -1;

    }
};