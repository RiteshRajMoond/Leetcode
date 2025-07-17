class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2);
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int sum = nums[i] + nums[j];
                if(sum == target) {
                    res[0] = i;
                    res[1] = j;
                    break;
                } 
            }
        }
        return res;
    }
};