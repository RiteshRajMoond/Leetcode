class Solution {
public:
    const int mod = 1e9+7;
    vector<vector<int>> dp;
    vector<vector<int>> counts;
    int numWays(vector<string>& words, string target) {
        // 1st -> Index on target  // 2nd -> K
        pre(words);
        dp = vector<vector<int>> (target.size(), vector<int> (words[0].size(), -1));
        return f(words, target, 0, 0);
    }
private:
    int f(vector<string>& words, string& target, int i, int j) {
        // base case
        if(i == target.size()) return 1;
        if(j >= words[0].size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int nt = f(words, target, i, j+1)%mod;

        int t = 0;
        int count = counts[target[i]-'a'][j];
        if (count > 0) {
            t = (1LL * count * f(words, target, i + 1, j + 1))%mod;
        }

        return dp[i][j] = (nt+t)%mod;
    }

    void pre(vector<string>& words) {
        int m = words.size();
        int n = words[0].size();

        counts = vector<vector<int>> (26, vector<int> (n, 0));

        for(int j = 0; j < n; j++) {
            for(int i = 0; i < m; i++) {
                counts[words[i][j] - 'a'][j]++;
            }
        }
    }
};