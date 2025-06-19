import java.util.Arrays;

public class Solution {
    public int partitionArray(int[] nums, int k) {
        int n = nums.length;
        Arrays.sort(nums);

        int numOfSubseqs = 1;
        int mn = nums[0], mx = nums[0];
        for(int i = 1; i < n; i++) {
            mn = Math.min(mn, nums[i]);
            mx = Math.max(mx, nums[i]);
            if(mx - mn > k) {
                numOfSubseqs++;
                mn = mx = nums[i];
            }
        }

        return numOfSubseqs;
    }
}
