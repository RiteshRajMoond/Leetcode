class Solution {
    int subs(vector<int>& nums, int idx, int cur) {
        if(idx == nums.size()) return cur;

        int inc = subs(nums, idx+1, cur ^ nums[idx]);
        int exc = subs(nums, idx+1, cur);
        return inc + exc;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        return subs(nums, 0, 0);
    }
};