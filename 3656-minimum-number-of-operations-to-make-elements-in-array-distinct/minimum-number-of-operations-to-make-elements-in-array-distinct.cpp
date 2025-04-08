class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        bool flag = false;
        int i = n-1;
        for(i; i >= 0; i--) {
            mp[nums[i]]++;
            if(mp[nums[i]] == 2) {
                flag = true;
                break;
            }
        }

        if(!flag) return 0;
        return (int) ceil((i+1)/3.0);
    }
};