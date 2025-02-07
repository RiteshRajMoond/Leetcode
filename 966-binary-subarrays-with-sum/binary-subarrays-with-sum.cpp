class Solution {
    int subarrays_with_sum_less_and_equal_to(vector<int>& nums, int goal) {
        int cur_sum = 0, n = nums.size(), i = 0, j = 0;
        int res = 0;
        while(j < n) {
            cur_sum += nums[j];

            while(i <= j && cur_sum > goal) {
                cur_sum -= nums[i++];
            }

            if(cur_sum <= goal) res += (j-i+1);
            j++;
        }
        return res;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return subarrays_with_sum_less_and_equal_to(nums, goal) - subarrays_with_sum_less_and_equal_to(nums, goal-1);
    }
};