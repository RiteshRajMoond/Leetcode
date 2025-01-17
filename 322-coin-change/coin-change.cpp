class Solution {
public:
    vector<vector<int>> dp;
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp = vector<vector<int>> (n, vector<int> (amount+1, -1));
        int ans = f(coins, amount, 0);
        if(ans >= 1e9) return -1;
        return ans;
    }
private:
    int f(vector<int>& coins, int amt, int idx) {
        if(idx == coins.size()) return 1e9;
        if(amt == 0) return 0;
        if(amt < 0) return 1e9;

        if(dp[idx][amt] != -1) return dp[idx][amt];

        int inc = f(coins, amt-coins[idx], idx) + 1;
        int exc = f(coins, amt, idx+1);

        return dp[idx][amt] = min(inc, exc);
    }
};