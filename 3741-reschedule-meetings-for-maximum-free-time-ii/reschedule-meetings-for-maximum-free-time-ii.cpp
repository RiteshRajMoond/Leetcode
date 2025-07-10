class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        if(n == 0) return eventTime;

        vector<int> gaps(n+1, 0);
        gaps[0] = startTime[0];
        for(int i = 1; i < n; i++) {
            gaps[i] = startTime[i] - endTime[i-1];
        }
        gaps[n] = eventTime - endTime[n-1];

        vector<int> lr(n+1, 0);
        for(int i = n-1; i >= 0; i--) {
            lr[i] = max(lr[i+1], gaps[i+1]);
        }

        int res = 0, ml = 0;
        for(int i = 1; i <= n; i++) {
            int len = endTime[i-1] - startTime[i-1];
            bool shiftL = ml >= len;
            bool shiftR = lr[i] >= len;

            if(shiftR || shiftL) {
                res = max(res, gaps[i-1] + gaps[i] + len);
            }
            res = max(res, gaps[i-1] + gaps[i]);
            ml = max(ml, gaps[i-1]);
        }

        return res;
    }
};