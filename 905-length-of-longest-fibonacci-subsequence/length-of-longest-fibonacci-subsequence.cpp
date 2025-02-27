class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp; 
        vector<vector<int>> dp(n, vector<int>(n, 0)); // DP table

        for(int i = 0; i < n; i++) {
            mp[arr[i]] = i;
        }

        int max_length = 0;

        // Loop through all pairs (i, j)
        for(int j = 1; j < n; j++) {
            for(int i = 0; i < j; i++) {
                int target = arr[j] - arr[i];

                // Only proceed if target < arr[i] to maintain strictly increasing order
                if(target < arr[i] && mp.count(target)) {
                    int k = mp[target]; // Get index of target
                    
                    // Transition Formula
                    dp[i][j] = dp[k][i] + 1;

                    // Every valid sequence has at least 3 elements
                    max_length = max(max_length, dp[i][j] + 2);
                }
            }
        }

        return max_length >= 3 ? max_length : 0;
    }
};
