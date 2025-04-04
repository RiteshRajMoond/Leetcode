class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> res;
        int n = intervals.size();
        vector<int> temp = intervals[0];
        for(int i = 1; i < n; i++) {
            if(intervals[i][0] > temp[1]) {
                res.push_back(temp);
                temp = intervals[i];
            }
            else {
                temp[0] = min(temp[0], intervals[i][0]);
                temp[1] = max(temp[1], intervals[i][1]);
            }
        }
        res.push_back(temp);

        return res;
    }
};