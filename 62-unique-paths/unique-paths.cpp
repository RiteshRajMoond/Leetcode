
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);  // Initialize a 1D array with 1s

        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                dp[j] = dp[j] + dp[j + 1];
            }
        }
        return dp[0];
    }
};