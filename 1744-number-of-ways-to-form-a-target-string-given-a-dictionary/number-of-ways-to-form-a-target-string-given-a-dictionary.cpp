class Solution {
public:
    const int mod = 1e9 + 7;
    vector<vector<int>> counts;

    int numWays(vector<string>& words, string target) {
        int m = target.size();  
        int n = words[0].size(); 
        preprocess(words);

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int j = 0; j <= n; j++) {
            dp[0][j] = 1;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // nt
                dp[i][j] = dp[i][j - 1];

                // t
                int count = counts[target[i - 1] - 'a'][j - 1];
                if (count > 0) {
                    dp[i][j] = (dp[i][j] + 1LL * count * dp[i - 1][j - 1]) % mod;
                }
            }
        }
        return dp[m][n];
    }

private:
    void preprocess(vector<string>& words) {
        int m = words.size();
        int n = words[0].size();

        counts = vector<vector<int>>(26, vector<int>(n, 0));
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                counts[words[i][j] - 'a'][j]++;
            }
        }
    }
};
