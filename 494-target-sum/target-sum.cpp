class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if((sum+target)&1) return 0;
        int tar = (sum+target) >> 1;
        if(tar < 0) return 0;

        vector<int> prev (tar+1, 0), cur(tar+1, 0);

        if(nums[0] == 0) prev[0] = 2;
        else {
            prev[0] = 1;
            if(tar >= nums[0]) prev[nums[0]] = 1;
        }

        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= tar; j++) {
                int nt = prev[j];
                int t = 0;
                if(nums[i] <= j) 
                    t = prev[j-nums[i]];
                
                cur[j] = t+nt;
            }
            prev = cur;
        }

        return prev[tar];
    }
};