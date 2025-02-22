class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> cur(2*k+1, 0), next(2*k+1, 0);

        for(int i = n-1; i >= 0; i--) {
            for(int j = 2*k-1; j >= 0; j--) {
                if(j&1) {
                    cur[j] = max(next[j+1] + prices[i], next[j]);
                } else {
                    cur[j] = max(next[j+1] - prices[i], next[j]);
                }
            }
            next = cur;
        }

        return cur[0];
    }
};