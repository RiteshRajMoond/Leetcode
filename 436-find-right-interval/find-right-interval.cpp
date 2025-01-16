class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<vector<int>> starts;
        int n = intervals.size();

        for(int i = 0; i < n; i++) {
            starts.push_back({intervals[i][0], i});
        }

        sort(starts.begin(), starts.end());
        
        vector<int> res;
        for(int i = 0; i < n; i++) {
            int end = intervals[i][1];
            auto it = lower_bound(starts.begin(), starts.end(), vector<int>{end, -1});
            if(it == starts.end()) res.push_back(-1);
            else res.push_back((*it)[1]);
        }

        return res;
    }
};