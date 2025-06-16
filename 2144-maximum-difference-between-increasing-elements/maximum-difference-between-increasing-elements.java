class Solution {
    public int maximumDifference(int[] nums) {
        int n = nums.length;
        int res = Integer.MIN_VALUE;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int diff = nums[j] - nums[i];
                res = Math.max(res, diff);
            }
        }
        return res <= 0 ? -1 : res;
    }
}