class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> cur (5, 0), next(5, 0);

        for(int i = n-1; i >= 0; i--) {
            for(int j = 3; j >= 0; j--) {
                if(j&1) {
                    int sell = next[j+1] + prices[i];
                    int not_sell = next[j];

                    cur[j] = max(sell, not_sell);
                } else {
                    int buy = next[j+1] - prices[i];
                    int not_buy = next[j];

                    cur[j] = max(buy, not_buy);
                }
            }
            next = cur;
        }

        return next[0];
    }
};