class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q_size = queries.size();
        vector<int> diff(n+1, 0);

        for(int i = 0; i < q_size; i++) {
            int l = queries[i][0], r = queries[i][1];
            diff[l] += 1;
            diff[r+1] -= 1;
        }

        int chng = 0;
        for(int i = 0; i < n; i++) {
            chng += diff[i];
            if(nums[i] > chng) return false;
        }
        return true;
    }
};