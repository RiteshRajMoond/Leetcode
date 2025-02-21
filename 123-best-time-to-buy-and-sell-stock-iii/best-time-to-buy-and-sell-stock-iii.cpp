class Solution {
    vector<vector<int>> dp;

    // even -> buying, odd -> selling
    int get_profit(vector<int>& prices, int idx, int num) {
        if(idx == prices.size()) return 0;
        if(num == 4) return 0;

        if(dp[idx][num] != -1) return dp[idx][num];

        if(num&1) {
            int sell = get_profit(prices, idx+1, num+1) + prices[idx];
            int not_sell = get_profit(prices, idx+1, num);

            return dp[idx][num] = max(sell, not_sell);
        } else {
            int buy = get_profit(prices, idx+1, num+1) - prices[idx];
            int not_buy = get_profit(prices, idx+1, num);

            return dp[idx][num] = max(buy, not_buy);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (5, 0));

        for(int i = n-1; i >= 0; i--) {
            for(int j = 3; j >= 0; j--) {
                if(j&1) {
                    int sell = dp[i+1][j+1] + prices[i];
                    int not_sell = dp[i+1][j];

                    dp[i][j] = max(sell, not_sell);
                } else {
                    int buy = dp[i+1][j+1] - prices[i];
                    int not_buy = dp[i+1][j];

                    dp[i][j] = max(buy, not_buy);
                }
            }
        }

        return dp[0][0];
    }
};