class Solution {
public:
    vector<vector<int>> dp;
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if((sum+target)&1) return 0;
        int tar = (sum+target) >> 1;
        if(tar < 0) return 0;

        dp = vector<vector<int>> (n, vector<int> (tar+1, -1));

        return f(nums, n-1, tar);
    }
private:
    int f(vector<int>& nums, int idx, int tar) {
        // base case
        if(idx == 0) {
            if(tar == 0 && nums[0] == 0) return 2;
            else if(tar == 0 || nums[0] == tar) return 1;
            return 0;
        }

        if(dp[idx][tar] != -1) return dp[idx][tar];

        int nt = f(nums, idx-1, tar);
        int t = 0;
        if(nums[idx] <= tar) 
            t = f(nums, idx-1, tar - nums[idx]);

        return dp[idx][tar] = t + nt;
    }
};