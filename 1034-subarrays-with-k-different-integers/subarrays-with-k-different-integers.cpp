class Solution {
    int subarrays_with_less_than_or_equal_to_k(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp; // num -> freq
        int res = 0;
        int i = 0, j = 0;
        while(j < n) {
            mp[nums[j]]++;

            while(mp.size() > k) {
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }

            res += (j-i+1);
            j++;
        }

        return res;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarrays_with_less_than_or_equal_to_k(nums, k) - subarrays_with_less_than_or_equal_to_k(nums, k-1);
    }
};