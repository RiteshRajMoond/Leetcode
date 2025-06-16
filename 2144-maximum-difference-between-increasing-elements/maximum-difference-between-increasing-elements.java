import java.util.ArrayList;

public class Solution {
    public int maximumDifference(int[] nums) {
        int n = nums.length;
        
        ArrayList<Integer> minLeft = new ArrayList<>();
        ArrayList<Integer> maxRight = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            minLeft.add(0);
            maxRight.add(0);
        }

        minLeft.set(0, nums[0]);
        for(int i = 1; i < n; i++) {
            minLeft.set(i, Math.min(minLeft.get(i-1), nums[i]));
        }

        maxRight.set(n-1, nums[n-1]);
        for(int i = n-2; i >= 0; i--) {
            maxRight.set(i, Math.max(maxRight.get(i+1), nums[i]));
        }

        int maxDiff = 0;
        for(int i = 0; i < n; i++) {
            maxDiff = Math.max(maxDiff, maxRight.get(i) - minLeft.get(i));
        }

        return maxDiff > 0 ? maxDiff : -1;
    }
}
