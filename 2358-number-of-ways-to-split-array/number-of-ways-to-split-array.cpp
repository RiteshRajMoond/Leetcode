class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for(int& i : nums) sum += i;

        int res = 0; long long l_sum = 0;
        for(int i = 0; i < n-1; i++) {
            l_sum += nums[i];
            if(l_sum >= sum - l_sum) res++;
        }
        return res;
    }
};