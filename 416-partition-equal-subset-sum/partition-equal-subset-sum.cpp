class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum&1) return false;
        int target = sum/2;
        int n = nums.size();

        vector<bool> prev(target+1, false);
        vector<bool> cur(target+1, false);

        prev[0] = true;

        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= target; j++) {
                bool nt = prev[j];
                bool t = false;
                if(j >= nums[i]) t = prev[j - nums[i]];

                cur[j] = t || nt;
            }
            prev = cur;
        }

        return prev[target];
    }
};