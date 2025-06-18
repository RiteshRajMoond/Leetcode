// 2966. Divide Array Into Arrays With Max Difference

import java.util.Arrays;

public class Solution {
    public int[][] divideArray(int[] nums, int k) {
        int n = nums.length;
        
        Arrays.sort(nums);
        int[][] res = new int[n/3][3];

        for(int i = 0; i < n/3; i++) {
            int mn = Integer.MAX_VALUE, mx = Integer.MIN_VALUE;
            for(int j = 0; j < 3; j++) {
                mn = Math.min(mn, nums[i*3+j]);
                mx = Math.max(mx, nums[i*3+j]);
                if(mx-mn > k) return new int[][]{};
                res[i][j] = nums[i*3+j];
            }
        }
        return res;
    }
}
