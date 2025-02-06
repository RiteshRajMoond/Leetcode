class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0, flip = 0;
        int i = 0, j = 0;

        while(j < n) {
            if(nums[j] == 1) {
                j++;
                res = max(res, j-i);
            } else {
                if(flip+1 > k) {
                    if(nums[i] == 0) flip--;
                    i++;
                } else {
                    flip++;
                    j++;
                    res = max(res, j-i);
                }
            }
        }

        return res;
    }
};