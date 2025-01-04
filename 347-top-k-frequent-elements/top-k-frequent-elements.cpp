class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for(int& i : nums) {
            mp[i]++;
        }

        priority_queue<pair<int, int>> pq;

        for(auto& i : mp) {
            pq.push({i.second, i.first});
        }

        vector<int> res;
        while(!pq.empty() && res.size() != k) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
