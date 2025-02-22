class Solution {
    vector<vector<int>> dp;
    
    // 0 -> Buy, 1 -> Sell
    int get_profit(vector<int>& prices, int idx, int status) {
        if(idx >= prices.size()) return 0;
        
        if(dp[idx][status] != -1) return dp[idx][status];

        if(status&1) {
            int sell = get_profit(prices, idx+2, 0) + prices[idx];
            int not_sell = get_profit(prices, idx+1, 1);

            return dp[idx][status] = max(sell, not_sell);
        } else {
            int buy = get_profit(prices, idx+1, 1) - prices[idx];
            int not_buy = get_profit(prices, idx+1, 0);

            return dp[idx][status] = max(buy, not_buy);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        dp = vector<vector<int>> (n, vector<int> (2, -1));
        return get_profit(prices, 0, 0);
    }
};