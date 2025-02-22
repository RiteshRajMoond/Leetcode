class Solution {
    vector<vector<int>> dp;
    int get_profit(vector<int>& prices, int idx, int k) {
        if(idx == prices.size()) return 0;
        if(k == 0) return 0;

        if(dp[idx][k] != -1) return dp[idx][k];

        // even -> buy, odd -> sell
        if(k&1) {
            int sell = get_profit(prices, idx+1, k-1) + prices[idx];
            int not_sell = get_profit(prices, idx+1, k);

            return dp[idx][k] = max(sell, not_sell);
        } else {
            int buy = get_profit(prices, idx+1, k-1) - prices[idx];
            int not_buy = get_profit(prices, idx+1, k);

            return dp[idx][k] = max(buy, not_buy);
        }
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        dp = vector<vector<int>> (n, vector<int> (2*k+1, -1));

        return get_profit(prices, 0, 2*k);
    }
};