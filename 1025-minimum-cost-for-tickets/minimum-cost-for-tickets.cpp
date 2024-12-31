class Solution {
public:
    vector<int> dp;
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(days.size(), -1);
        return f(days, costs, 0);
    }
private:
    int f(vector<int>& days, vector<int>& costs, int idx) {
        if(idx >= days.size()) return 0;

        if(dp[idx] != -1) return dp[idx];
        
        int one = costs[0] + f(days, costs, getIndex(days, idx, 1));
        int two = costs[1] + f(days, costs, getIndex(days, idx, 7));
        int three = costs[2] + f(days, costs, getIndex(days, idx, 30));

        return dp[idx] = min({one, two, three});
    }

    int getIndex(vector<int>& days, int curIdx, int passDays) {
        int day = days[curIdx] +  passDays;
        while(curIdx < days.size() && days[curIdx] < day) curIdx++;
        return curIdx;
    }
};