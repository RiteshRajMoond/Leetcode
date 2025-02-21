class Solution {
    vector<vector<vector<int>>> dp;

    int get_profit(vector<int>& prices, int idx, int buy, int trans) {
        if(idx == prices.size()) return 0;
        if(trans == 0) return 0;

        if(dp[idx][buy][trans] != -1) return dp[idx][buy][trans];

        // already bought we are gonna sell
        if(buy) {
            int sell = get_profit(prices, idx+1, 0, trans-1) + prices[idx];
            int not_sell = get_profit(prices, idx+1, 1, trans);
            return dp[idx][buy][trans] = max(sell, not_sell);
        } else {
        // no stock. Need to buy it
            int buys = get_profit(prices, idx+1, 1, trans) - prices[idx];
            int not_buys = get_profit(prices, idx+1, 0, trans);
            return dp[idx][buy][trans] = max(buys, not_buys);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp = vector<vector<vector<int>>> (n, vector<vector<int>> (2, vector<int> (3, -1)));
        return get_profit(prices, 0, 0, 2);
    }
};