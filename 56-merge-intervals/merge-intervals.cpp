class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> merged_intervals;
        sort(intervals.begin(), intervals.end());

        for(auto& interval : intervals) {
            if(merged_intervals.empty() || merged_intervals.back()[1] < interval[0] ) merged_intervals.push_back(interval);
            else merged_intervals.back()[1] = max(interval[1], merged_intervals.back()[1]);
        }

        return merged_intervals;
    }
};