class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> mp; // Sum -> freq;
        mp[0] = 1;
        int cnt = 0, cur_sum = 0;
        for (int i = 0; i < n; i++) {
            cur_sum += nums[i];

            if (mp.count(cur_sum - goal)) {
                cnt += mp[cur_sum - goal];
            }

            mp[cur_sum]++;
        }

        return cnt;
    }
};