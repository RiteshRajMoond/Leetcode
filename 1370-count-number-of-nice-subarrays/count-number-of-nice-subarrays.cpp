class Solution {
    int num_of_nice_arrays(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        int cnt = 0, res = 0;

        while(j < n) {
            cnt += (nums[j]&1);

            while(i <= j && cnt > k) {
                cnt -= (nums[i]&1);
                i++;
            }

            if(cnt <= k) res += (j-i+1);
            j++;
        }
        return res;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return num_of_nice_arrays(nums, k) - num_of_nice_arrays(nums, k-1);
    }
};