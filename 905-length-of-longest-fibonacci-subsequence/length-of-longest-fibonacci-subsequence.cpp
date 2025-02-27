class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) mp[arr[i]] = i;
        vector<vector<int>> dp(n, vector<int> (n, 0));
        
        int max_len = 0;

        for(int j = 1; j < n; j++) {
            for(int i = 0; i < j; i++) {
                int target = arr[j] - arr[i];
                if(target < arr[i] && mp.count(target)) {
                    int k = mp[target];
                    dp[i][j] = 1 + dp[k][i];    
                    max_len = max(max_len, dp[i][j]+2);
                }
            }
        }

        return max_len >= 3 ? max_len : 0;
    }
};