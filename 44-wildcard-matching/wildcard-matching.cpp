class Solution {
public:
    vector<vector<int>> dp;
    bool isMatch(string& s, string& p) {
        int n = s.size(), m = p.size();
        dp = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));
        return helper(s, p, n, m);
    }

private:
    bool helper(const string& s, const string& p, unsigned int i, unsigned int j) {
        // Base case: both strings finished
        if (i == 0 && j == 0) return true;

        // Base case: string finished, pattern remains
        if (i == 0) {
            for (int k = 0; k < j; k++) {
                if (p[k] != '*') return false;
            }
            return true;
        }

        // Base case: pattern finished, string remains
        if (j == 0) return false;

        // Memoization check
        if (dp[i][j] != -1) return dp[i][j];

        // Recursive cases
        if (s[i - 1] == p[j - 1] || p[j - 1] == '?') 
            return dp[i][j] = helper(s, p, i - 1, j - 1);

        if (p[j - 1] == '*') 
            return dp[i][j] = helper(s, p, i - 1, j) || helper(s, p, i, j - 1);

        return dp[i][j] = false;
    }
};
