class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum&1) return false;
        int target = sum/2;
        int n = nums.size();

        vector<vector<bool>> dp (n, vector<bool> (target+1, false));

        for(int i = 0; i < n; i++) {
            dp[i][0] = true;
            if(target >= nums[i]) dp[i][nums[i]] = true;
        }

        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= target; j++) {
                bool nt = dp[i-1][j];
                bool t = false;
                if(j >= nums[i]) t = dp[i-1][j - nums[i]];

                dp[i][j] = t || nt;
            }
        }

        return dp[n-1][target];
    }
};