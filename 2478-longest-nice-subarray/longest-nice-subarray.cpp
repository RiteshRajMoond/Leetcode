class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l = 0, r = 0, max_size = 1;
        int n = nums.size();
        int bitmask = 0;

        while(r < n) {
            while((bitmask & nums[r]) != 0) {
                bitmask ^= nums[l];
                l++;
            }

            bitmask |= nums[r];
            r++;
            max_size = max(max_size, r-l);
        }
        max_size = max(max_size, r-l);
        return max_size;
    }
};