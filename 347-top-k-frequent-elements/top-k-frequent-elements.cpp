class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int& i : nums) mp[i]++;

        vector<vector<int>> list(nums.size()+1);
        for(auto& [key, value]: mp) {
            list[value].push_back(key);
        }

        vector<int> res;
        for(int i = nums.size(); i >= 0 && res.size() != k; i--) {
            if(!list[i].empty()) {
                for(int j = 0; j < list[i].size() && res.size() != k; j++) {
                    res.push_back(list[i][j]);
                }
            }
        }
        return res;
    }
};