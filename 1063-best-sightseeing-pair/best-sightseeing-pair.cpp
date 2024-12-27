class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // val[i] + val[j] + i - j
        // (val[i] + i) + (val[j] - j);

        int mx = values[0]; // val[i] + i;
        int res = -1e9;

        for(int j = 1; j < values.size(); j++) {
            res = max(res, mx + values[j] - j);
            mx = max(mx, values[j] + j);
        }

        return res;
    }
};