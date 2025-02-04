class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int cur = nums[0], res = 0, n = nums.size();

        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i-1]) {
                cur += nums[i];
            } else {
                res = max(cur, res);
                cur = nums[i];
            }
        }
        res = max(cur, res);
        return res;
    }
};